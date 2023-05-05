#pragma once
#ifndef CPUINFO_HPP
#define CPUINFO_HPP

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.hpp"
#include "string_helper.hpp"

/**
 * @brief Class for storing information about the system's cpu from /proc/cpuinfo.
 * @author Lilith Ernst
 * @version 4-30-23
 * 
 */
class cpuinfo {
    private:

        /**
         * @brief Class for storing information about a single cpu thread from /proc/cpuinfo.
         */
        class cpu {
            public:
                int processor;
                std::string vendor_id;
                int cpu_family;

                int model;
                std::string model_name;
                int stepping;

                std::string microcode;
                double clock_speed;
                int cache;

                int physical_id;
                int siblings;
                int core_id;

                int cpu_cores;
                int apicid;
                int initial_apicid;

                std::string fpu;
                std::string fpu_execution;
                int cpuid_level;

                std::string wp;
                std::vector<std::string> flags;
                std::vector<std::string> bugs;

                double bogomips;
                std::string tlb_size;
                int clflush_size;

                int cache_alignment;
                std::vector<std::string> address_sizes;
                std::vector<std::string> power_management;

                cpu() {}
        };

        enum FIELDS {
            processor, vendor_id, cpu_family, model, model_name, stepping, 
            microcode, clock_speed, cache, physical_id, siblings, core_id, 
            cpu_cores, apicid, initial_apicid, fpu, fpu_execution, cpuid_level, 
            wp, flags, bugs, bogomips, tlb_size, clflush_size, cache_alignment, 
            address_sizes, power_management, new_thread
        };

        std::map<std::string, FIELDS> field_map = {
            {"processor:", processor}, {"vendor_id:", vendor_id}, {"cpufamily:", cpu_family}, {"model:", model}, {"modelname:", model_name}, {"stepping:", stepping}, 
            {"microcode:", microcode}, {"cpuMHz:", clock_speed}, {"cachesize:", cache}, {"physicalid:", physical_id}, {"siblings:", siblings}, {"coreid:", core_id}, 
            {"cpucores:", cpu_cores}, {"apicid:", apicid}, {"initialapicid:", initial_apicid}, {"fpu:", fpu}, {"fpu_exception:", fpu_execution}, {"cpuidlevel:", cpuid_level}, 
            {"wp:", wp}, {"flags:", flags}, {"bugs:", bugs}, {"bogomips:", bogomips}, {"TLBsize:", tlb_size}, {"clflushsize:", clflush_size}, {"cache_alignment:", cache_alignment}, 
            {"addresssizes:", address_sizes}, {"powermanagement:", power_management}, {"", new_thread}
        };

        //Fields   
        std::vector<cpu *> threads;
        std::vector<cpu *> physical_cores;
        
    public:

        /**
         * @brief Construct a new cpuinfo object
         * 
         */
        cpuinfo();

        /**
         * @brief Updates the information stored in the cpuinfo class.
         * 
         */
        void updateInfo();

        /**
         * @brief Prints information for all threads.
         * 
         */
        void printInfo_AllCores();

        /**
         * @brief Prints information for each physical cpu.
         * 
         */
        void printInfo_Summation();

        /**
         * @brief Get/Update information about the physical cores
         * 
         * @return std::vector<cpu *> containing the physical cores
         */
        std::vector<cpu *> getUniquePhysicalCores();
};

#endif
