#include <iostream>
#include <intrin.h> // Required for __cpuidex

int main() {
    int cpuInfo[4];

    // Call __cpuidex with EAX=7 and ECX=0
    __cpuidex(cpuInfo, 7, 0);

    // AVX2 is indicated by bit 5 of the EBX register (cpuInfo[1])
    bool avx2_supported = (cpuInfo[1] & (1 << 5));

    if (avx2_supported) {
        // Print a specific string to be captured by CMake
        std::cout << "AVX2 SUPPORTED" << std::endl;
        return 0; // Success
    } else {
        std::cout << "AVX2 NOT SUPPORTED" << std::endl;
    }

    return 11; // Failure
}
