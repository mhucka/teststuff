cmake_minimum_required(VERSION 3.21)
project(HardwareCheck CXX)

set(CHECK_AVX2_SRC "${CMAKE_CURRENT_BINARY_DIR}/check_avx2.cc")
file(WRITE ${CHECK_AVX2_SRC} "
#include <intrin.h> // For MSVC
int main() {
    int cpuInfo[4];
#if defined(__GNUC__) || defined(__clang__)
    __asm__ __volatile__ (
        \"cpuid;\"
        : \"=a\" (cpuInfo[0]), \"=b\" (cpuInfo[1]), \"=c\" (cpuInfo[2]), \"=d\" (cpuInfo[3])
        : \"a\" (7), \"c\" (0)
    );
#else
    __cpuidex(cpuInfo, 7, 0);
#endif
    // Return 0 if supported (success), 1 if not (failure)
    return (cpuInfo[1] & (1 << 5)) ? 0 : 1;
}"
)

try_run(
    AVX2_RUN_RESULT
    AVX2_COMPILE_RESULT
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CHECK_AVX2_SRC}"
)

if(AVX2_COMPILE_RESULT AND AVX2_RUN_RESULT EQUAL 0)
    message(STATUS "✅ AVX2 support detected. Enabling optimizations.")
    set(AVX2_SUPPORTED TRUE)
else()
    message(STATUS "❌ AVX2 support not detected.")
    set(AVX2_SUPPORTED FALSE)
endif()
