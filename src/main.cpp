#include "cpuinfo.cpp"

int main()
{
    cpuinfo cpuinfo;

    cpuinfo.updateInfo();
    cpuinfo.printInfo();

    return 0;
}