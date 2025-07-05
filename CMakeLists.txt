cmake_minimum_required(VERSION 3.31)
project(check)

# Add an executable for the CPU feature check
add_executable(cpu_check check_avx512f.cc)

execute_process(COMMAND echo "Hello from execute_process")

# Run the compiled checker and check its return code
execute_process(
    COMMAND $<TARGET_FILE:cpu_check>
    RESULT_VARIABLE check_result
#    OUTPUT_QUIET
#    ERROR_QUIET
)

execute_process(COMMAND echo "Result is ${check_result}")

if(check_result EQUAL 0)
    message(STATUS "✅ Feature 'AVX-512F' found!")
    # Add your compile definitions for AVX-512F
    add_compile_definitions(HAS_AVX512F)
elseif(check_result EQUAL 11)
    message(STATUS "❌ Feature 'AVX-512F' not found.")
else()
    message(STATUS "wrong")
endif()
