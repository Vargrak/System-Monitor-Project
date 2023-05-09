#include "sysinfo.hpp"

int main() {
    sysinfo system = sysinfo();

    while (true) {
        system.updateAllInfo();
        system.getCpu().printInfo_Summation();
        system.getMemory().printMemoryInfo();
        system.getProcesses().printProcessList();
    }

    return 0;
}