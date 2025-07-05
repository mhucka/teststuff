cmake_minimum_required(VERSION 3.31)
project(check CXX)

# Add an executable for the CPU feature check
add_executable(cpu_check check_avx512f.cc)

# Values get set, but doesn't seem to get passed to msvc compiler
# set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} /arch:AVX2 /O2")
# set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /EHsc /arch:AVX2 /O2")

add_compile_options(/arch:AVX2 /O2)

# log all *_INIT variables
message(STATUS "CMake variable values:")
get_cmake_property(_varNames VARIABLES)
list(REMOVE_DUPLICATES _varNames)
list(SORT _varNames)
foreach(_varName ${_varNames})
    if(_varName MATCHES "_INIT$")
        message(STATUS "  ${_varName}=${${_varName}}")
    endif()
endforeach()

add_custom_command(
    TARGET cpu_check POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running the test program..."
    COMMAND $<TARGET_FILE:cpu_check>
    COMMAND ${CMAKE_COMMAND} -E echo "Test program finished."
    COMMENT "Executing test program"
)

get_target_property(compile_defs cpu_check COMPILE_DEFINITIONS)
message(STATUS "cpu_check compile definitions: ${compile_defs}")


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
