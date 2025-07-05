#include <iostream>
#include <intrin.h> // Required for __cpuidex

int main() {
    int cpuInfo[4];

    // Call __cpuidex with EAX=7 and ECX=0
    __cpuidex(cpuInfo, 7, 0);

    // AVX-512F is indicated by bit 16 of the EBX register (cpuInfo[1])
    bool avx512f_supported = (cpuInfo[1] & (1 << 16));

    if (avx512f_supported) {
        // Print a specific string to be captured by CMake
        std::cout << "AVX512F SUPPORTED" << std::endl;
        return 0; // Success
    } else {
        std::cout << "AVX512F NOT SUPPORTED" << std::endl;
    }

    return 11; // Failure
}
