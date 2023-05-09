#pragma once
#ifndef SYSINFO_HPP
#define SYSINFO_HPP

#include "cpuinfo.hpp"
#include "mem.hpp"
#include "processes.hpp"

/**
 * @brief Class that holds and compiles information from all the cpus, processes, memory, etc; and stores
 * them in a singular class for ease of access.
 * @author Lilith Ernst
 * 
 * @version 5-9-23
 * 
 */
class sysinfo {
    private:
        cpuinfo system_cpu;
        mem system_mem;
        processes system_processes;


    public:

        /**
         * @brief Construct a new sysinfo object
         * 
         */
        sysinfo();

        //Getters
        cpuinfo getCpu() { return this->system_cpu; }
        mem getMemory() { return this->system_mem; }
        processes getProcesses() { return this->system_processes; }

        /**
         * @brief Updates all information about the system
         * 
         */
        void updateAllInfo();
};

#endif
