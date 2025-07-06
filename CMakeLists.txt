# set(CHECK_AVX2_SRC "${CMAKE_CURRENT_BINARY_DIR}/check_avx2.cc")
# file(WRITE ${CHECK_AVX2_SRC} "
# #include <intrin.h> // For MSVC
# int main() {
#     int cpuInfo[4];
# #if defined(__GNUC__) || defined(__clang__)
#     __asm__ __volatile__ (
#         \"cpuid;\"
#         : \"=a\" (cpuInfo[0]), \"=b\" (cpuInfo[1]), \"=c\" (cpuInfo[2]), \"=d\" (cpuInfo[3])
#         : \"a\" (7), \"c\" (0)
#     );
# #else
#     __cpuidex(cpuInfo, 7, 0);
# #endif
#     // Return 0 if supported (success), 1 if not (failure)
#     return (cpuInfo[1] & (1 << 5)) ? 0 : 1;
# }"
# )

# try_run(
#     AVX2_RUN_RESULT
#     AVX2_COMPILE_RESULT
#     "${CMAKE_CURRENT_BINARY_DIR}"
#     "${CHECK_AVX2_SRC}"
# )

# if(AVX2_COMPILE_RESULT AND AVX2_RUN_RESULT EQUAL 0)
#     message(STATUS "✅ AVX2 support detected. Enabling optimizations.")
#     set(AVX2_SUPPORTED TRUE)
# else()
#     message(STATUS "❌ AVX2 support not detected.")
#     set(AVX2_SUPPORTED FALSE)
# endif()


# =============================================================================


cmake_minimum_required(VERSION 3.31)
project(HardwareCheck CXX)

include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

list(APPEND CMAKE_MESSAGE_CONTEXT "qsim")
set(CMAKE_MESSAGE_CONTEXT_SHOW ON)

macro(check_cpu_support _FEATURE_STRING _FEATURE_FLAG)
    set(${_FEATURE_FLAG} FALSE)
    set(_MSG_PREFIX "Checking platform support for ${_FEATURE_STRING}")
    message(CHECK_START ${_MSG_PREFIX})
    set(_CHECK_COMPLETED TRUE)

    if(WIN32)
        # On Windows, there's no built-in method to learn the CPU flags. Third-
        # party tools exist, but downloading & running them is a security risk.
        # We resort instead to compiling and running our own small program.
        set(_CHECKER_FILE_PATH "${CMAKE_BINARY_DIR}/checker.cpp")
        file(WRITE ${_CHECKER_FILE_PATH} "${_WIN32_CHECKER_SRC}")
        try_run(
            _CHECKER_RETURN_VALUE
            _CHECKER_COMPILED
            "${CMAKE_BINARY_DIR}"
            "${_CHECKER_FILE_PATH}"
            RUN_OUTPUT_VARIABLE _CPU_FEATURES
        )
        if(_CHECKER_COMPILED AND _CHECKER_RETURN_VALUE EQUAL 0)
            string(FIND "${_CPU_FEATURES}" ${_FEATURE_STRING} _FOUND)
            if(NOT _FOUND EQUAL -1)
                set(${_FEATURE_FLAG} TRUE)
            endif()
        else()
            set(_CHECK_COMPLETED FALSE)
            if(NOT _CHECKER_COMPILED)
                message(CHECK_FAIL " failed to compile checker.")
            else()
                message(CHECK_FAIL " failed to run checker.")
            endif()
        endif()

    elseif(LINUX)
        execute_process(
            COMMAND bash --noprofile -c "grep -q ${_FEATURE_STRING} /proc/cpuinfo"
            RESULT_VARIABLE _EXIT_CODE
        )
        if(_EXIT_CODE EQUAL 0)
            set(${_FEATURE_FLAG} TRUE)
        endif()

    elseif(APPLE AND NOT CMAKE_APPLE_SILICON_PROCESSOR)
        execute_process(
            COMMAND bash --noprofile -c "sysctl -n hw.optional.${_FEATURE_STRING}"
            RESULT_VARIABLE _EXIT_CODE
            OUTPUT_VARIABLE _FLAG_VALUE
        )
        if(_EXIT_CODE EQUAL 0 AND _FLAG_VALUE EQUAL "1")
            set(${_FEATURE_FLAG} TRUE)
        endif()
    endif()

    if(_CHECK_COMPLETED)
        message(CHECK_PASS " Done.")
    endif()
endmacro()

# Small Windows C++ program to test bits in certain Intel CPU registers.
# Info about the registers in Intel CPUs: https://en.wikipedia.org/wiki/CPUID
#
# EAX  ECX  Bit   Name
#  1    0   19    sse4.1
#  1    0   20    sse4.2
#  1    0   28    avx
#  7    0    5    avx2
#  7    0   16    avx512f
#
# Note: CMake caches the output of try_run() by default; therefore, this program
# will not be executed each time try_run() is called.

set(_WIN32_CHECKER_SRC "
#include <iostream>
#include <string>
#include <intrin.h>

int main() {
    int cpuInfo[4];
    __cpuidex(cpuInfo, 1, 0);
    std::cout << ((cpuInfo[2] & (1 << 19)) ? \"sse4.1\\n\"  : \"\");
    std::cout << ((cpuInfo[2] & (1 << 20)) ? \"sse4.2\\n\"  : \"\");
    __cpuidex(cpuInfo, 7, 0);
    std::cout << ((cpuInfo[1] & (1 << 5))  ? \"avx2\\n\"    : \"\")
              << ((cpuInfo[1] & (1 << 16)) ? \"avx512f\\n\" : \"\");
    return 0;
}
")

if(WIN32)
    check_cpu_support("avx2" CPU_SUPPORTS_AVX2)
    check_cpu_support("avx512f" CPU_SUPPORTS_AVX512)
    check_cpu_support("sse4.1" CPU_SUPPORTS_SSE4)
elseif(LINUX)
    check_cpu_support("avx2" CPU_SUPPORTS_AVX2)
    check_cpu_support("avx512f" CPU_SUPPORTS_AVX512)
    check_cpu_support("sse4" CPU_SUPPORTS_SSE4)
elseif(APPLE AND NOT CMAKE_APPLE_SILICON_PROCESSOR)
    check_cpu_support("avx2_0" CPU_SUPPORTS_AVX2)
    check_cpu_support("avx512f" CPU_SUPPORTS_AVX512)
    check_cpu_support("sse4_1" CPU_SUPPORTS_SSE4)
endif()

message(STATUS "avx2 = ${CPU_SUPPORTS_AVX2}")
