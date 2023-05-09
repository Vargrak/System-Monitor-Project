#include "sysinfo.hpp"

/**
 * @brief Construct a new information::information object
 * 
 */
sysinfo::sysinfo() {
    this->system_cpu = cpuinfo();
    this->system_mem = mem();
    this->system_processes = processes();
}


/**
 * @brief Updates all information in the information class
 * 
 */
void sysinfo::updateAllInfo() {
    this->system_cpu.updateInfo();
    this->system_mem.updateInfo();
    this->system_processes.updateInfo();
}