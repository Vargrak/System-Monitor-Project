#pragma once

#include "cpuinfo.cpp"
#include "mem.cpp"

int main() {
    cpuinfo cpuinfo;
    mem meminfo;

    cpuinfo.printInfo_Summation();
    meminfo.printMemoryInfo();


    return 0;
}