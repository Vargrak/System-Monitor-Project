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
 * @version 5-9-23
 * 
 */
class cpuinfo {
    private:

        /**
         * @brief Class for storing information about a single cpu thread from /proc/cpuinfo.
         */
        class cpu {
            private:
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

            public:

                cpu() {}

                //Getters for accessing the cpu information
                int getProcessor() { return processor; }
                std::string getVendorID() { return vendor_id; }
                int getCPUFamily() { return cpu_family; }

                int getModel() { return model; }
                std::string getModelName() { return model_name; }
                int getStepping() { return stepping; }

                std::string getMicrocode() { return microcode; }
                double getClockSpeed() { return clock_speed; }
                int getCache() { return cache; }

                int getPhysicalID() { return physical_id; }
                int getSiblings() { return siblings; }
                int getCoreID() { return core_id; }

                int getCPUCores() { return cpu_cores; }
                int getAPICID() { return apicid; }
                int getInitialAPICID() { return initial_apicid; }

                std::string getFPU() { return fpu; }
                std::string getFPUExecution() { return fpu_execution; }
                int getCPUIDLevel() { return cpuid_level; }

                std::string getWP() { return wp; }
                std::vector<std::string> getFlags() { return flags; }
                std::vector<std::string> getBugs() { return bugs; }

                double getBogomips() { return bogomips; }
                std::string getTLBSize() { return tlb_size; }
                int getCLFlushSize() { return clflush_size; }

                int getCacheAlignment() { return cache_alignment; }
                std::vector<std::string> getAddressSizes() { return address_sizes; }
                std::vector<std::string> getPowerManagement() { return power_management; }

                //Setters for updating the cpu information
                void setProcessor(int Processor) { this->processor = Processor; }
                void setVendorID(std::string VendorId) { this->vendor_id = VendorId; }
                void setCPUFamily(int CpuFamily) { this->cpu_family = CpuFamily; }

                void setModel(int Model) { this->model = Model; }
                void setModelName(std::string ModelName) { this->model_name = ModelName; }
                void setStepping(int Stepping) { this->stepping = Stepping; }

                void setMicrocode(std::string Microcode) { this->microcode = Microcode; }
                void setClockSpeed(double ClockSpeed) { this->clock_speed = ClockSpeed; }
                void setCache(int Cache) { this->cache = Cache; }

                void setPhysicalID(int PhysicalId) { this->physical_id = PhysicalId; }
                void setSiblings(int Siblings) { this->siblings = Siblings; }
                void setCoreID(int CoreID) { this->core_id = CoreID; }

                void setCPUCores(int CpuCores) { this->cpu_cores = CpuCores; }
                void setAPICID(int ApicID) { this->apicid = ApicID; }
                void setInitialAPICID(int InitialApicid) { this->initial_apicid = InitialApicid; }
                void setFPU(std::string Fpu) { this->fpu = Fpu; }

                void setFPUExecution(std::string FpuExecution) { this->fpu_execution = FpuExecution; }
                void setCPUIDLevel(int CpuidLevel) { this->cpuid_level = CpuidLevel; }
                void setWP(std::string Wp) { this->wp = Wp; }

                void setFlags(std::vector<std::string> Flags) { this->flags = Flags; }
                void setBugs(std::vector<std::string> Bugs) { this->bugs = Bugs; }
                void setBogomips(double Bogomips) { this->bogomips = Bogomips; }

                void setTLBSize(std::string TlbSize) { this->tlb_size = TlbSize; }
                void setCLFlushSize(int ClflushSize) { this->clflush_size = ClflushSize; }
                void setCacheAlignment(int CacheAlignment) { this->cache_alignment = CacheAlignment; }
                
                void setAddressSizes(std::vector<std::string> AddressSizes) { this->address_sizes = AddressSizes; }
                void setPowerManagement(std::vector<std::string> PowerManagement) { this->power_management = PowerManagement; }

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

                /**
         * @brief Get/Update information about the physical cores
         * 
         * @return std::vector<cpu *> containing the physical cores
         */
        std::vector<cpu *> getUniquePhysicalCores();
        
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
         * @brief Get the Threads object
         * 
         * @return std::vector<cpu *> containing the threads
         */
        std::vector<cpu *> getThreads();

        /**
         * @brief Get the Physical Cores object
         * 
         * @return std::vector<cpu *> containing the physical cores
         */
        std::vector<cpu *> getPhysicalCores();
};

#endif
