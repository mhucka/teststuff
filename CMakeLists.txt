cmake_minimum_required(VERSION 3.31)
project(check CXX)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type not specified. Defaulting to Release")
endif()

file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/check_avx2.cc" "
#include <intrin.h>
int main() {
    int cpuInfo[4];
    __cpuidex(cpuInfo, 7, 0);
    return (cpuInfo[1] & (1 << 5)) ? 0 : 1;
}"
)

add_executable(check_2 "${CMAKE_CURRENT_SOURCE_DIR}/check_avx2.cc")

target_compile_options(check_2 PRIVATE /arch:AVX2)

add_custom_command(
    TARGET check_2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running the test program..."
    COMMAND $<TARGET_FILE:check_2>
    COMMAND ${CMAKE_COMMAND} -E echo "Test program finished."
    COMMENT "Executing test program"
)

# Run the compiled checker and check its return code
execute_process(
    COMMAND $<TARGET_FILE:check_2>
    RESULT_VARIABLE check_result
)

execute_process(COMMAND echo "Result is ${check_result}")

# if(check_result EQUAL 0)
#     message(STATUS "✅ Feature 'AVX-512F' found!")
#     # Add your compile definitions for AVX-512F
#     add_compile_definitions(HAS_AVX512F)
# elseif(check_result EQUAL 11)
#     message(STATUS "❌ Feature 'AVX-512F' not found.")
# else()
#     message(STATUS "wrong")
# endif()
