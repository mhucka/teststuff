cmake_minimum_required(VERSION 3.31)
project(check CXX)

# log all *_INIT variables
get_cmake_property(_varNames VARIABLES)
list(REMOVE_DUPLICATES _varNames)
list(SORT _varNames)
foreach(_varName ${_varNames})
    if(_varName MATCHES "_INIT$")
        message(STATUS "${_varName}=${${_varName}}")
    endif()
endforeach()

# Add an executable for the CPU feature check
add_executable(cpu_check check_avx512f.cc)

target_compile_options(cpu_check PRIVATE /arch:AVX512)

add_custom_command(
    TARGET cpu_check POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running the test program..."
    COMMAND $<TARGET_FILE:cpu_check>
    COMMAND ${CMAKE_COMMAND} -E echo "Test program finished."
    COMMENT "Executing test program"
)


# # Run the compiled checker and check its return code
# execute_process(
#     COMMAND $<TARGET_FILE:cpu_check>
#     RESULT_VARIABLE check_result
# #    OUTPUT_QUIET
# #    ERROR_QUIET
# )

# execute_process(COMMAND echo "Result is ${check_result}")

# if(check_result EQUAL 0)
#     message(STATUS "✅ Feature 'AVX-512F' found!")
#     # Add your compile definitions for AVX-512F
#     add_compile_definitions(HAS_AVX512F)
# elseif(check_result EQUAL 11)
#     message(STATUS "❌ Feature 'AVX-512F' not found.")
# else()
#     message(STATUS "wrong")
# endif()
