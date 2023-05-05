#include "cpuinfo.hpp"
#include "mem.hpp"
#include "processes.hpp"

int main() {
    cpuinfo cpuinfo;
    mem meminfo;
    processes processinfo;

    cpuinfo.printInfo_Summation();
    meminfo.printMemoryInfo();
    processinfo.print_process_list();


    return 0;
}