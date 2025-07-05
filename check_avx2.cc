#include <intrin.h>
int main() {
    int cpuInfo[4];
    // Get registers EAX=7 and ECX. (C.f. https://en.wikipedia.org/wiki/CPUID).
    __cpuidex(cpuInfo, 7, 0);
    // AVX2 is indicated by bit 5 of the EBX register (cpuInfo[1]).
    // Per Unix convention, a return value of 0 is success.
    return (cpuInfo[1] & (1 << 5)) ? 0 : 1;
}
