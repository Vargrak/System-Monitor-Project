#include "cpuinfo.hpp"
#include "mem.hpp"

int main() {
    cpuinfo cpuinfo;
    mem meminfo;

    cpuinfo.printInfo_Summation();
    meminfo.printMemoryInfo();


    return 0;
}