#include "cpuinfo.cpp"

int main() {
    cpuinfo cpuinfo;

    cpuinfo.updateInfo();
    cpuinfo.printInfo_Summation(); //Need to include thermals!

    return 0;
}