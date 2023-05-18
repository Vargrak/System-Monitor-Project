#include "sysinfo.hpp"

/**
 * @brief Construct a new sysinfo::sysinfo object
 * 
 */
sysinfo::sysinfo() {
    this->system_cpu = cpuinfo();
    this->system_mem = mem();
    this->system_processes = processes();
}

/**
 * @brief Updates all information about the system
 * 
 */
void sysinfo::updateAllInfo() {
    this->system_cpu.updateInfo();

    this->system_mem.updateInfo();
    
    this->system_processes.updateInfo();
}