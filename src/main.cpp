#include "cpuinfo.cpp"

int main()
{
    cpuinfo cpuinfo;

    cpuinfo.updateInfo();
    cpuinfo.printInfo_AllCores();

    return 0;
}