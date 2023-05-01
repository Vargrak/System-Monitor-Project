#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.cpp"
#include "string_helper.cpp"

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
        cpuinfo() {
            updateInfo();
        }

        /**
         * @brief Updates the information stored in the cpuinfo class.
         * 
         */
        void updateInfo() {
            std::vector<std::string> cputext = file_loader::load_file("/proc/cpuinfo");
            cpu *thread = new cpu();

            for (auto line : cputext) {
                std::string field = string_helper::remove_whitespace(line.substr(0, line.find(":") + 1));
                std::string value = line.substr(line.find(":") + 1);

                try {
                    switch (field_map[field]) {
                        case processor:
                            thread->processor = std::stoi(value);
                            break;

                        case vendor_id:
                            thread->vendor_id = value;
                            break;

                        case cpu_family:
                            thread->cpu_family = std::stoi(value);
                            break;

                        case model:
                            thread->model = std::stoi(value);
                            break;

                        case model_name:
                            thread->model_name = value;
                            break;

                        case stepping:
                            thread->stepping = std::stoi(value);
                            break;

                        case microcode:
                            thread->microcode = value;
                            break;

                        case clock_speed:
                            thread->clock_speed = std::stod(value);
                            break;

                        case cache:
                            thread->cache = std::stoi(value);
                            break;

                        case physical_id:
                            thread->physical_id = std::stoi(value);
                            break;

                        case siblings:
                            thread->siblings = std::stoi(value);
                            break;

                        case core_id:
                            thread->core_id = std::stoi(value);
                            break;

                        case cpu_cores:
                            thread->cpu_cores = std::stoi(value);
                            break;

                        case apicid:
                            thread->apicid = std::stoi(value);
                            break;

                        case initial_apicid:
                            thread->initial_apicid = std::stoi(value);
                            break;

                        case fpu:
                            thread->fpu = value;
                            break;

                        case fpu_execution:
                            thread->fpu_execution = value;
                            break;

                        case cpuid_level:
                            thread->cpuid_level = std::stoi(value);
                            break;

                        case wp:
                            thread->wp = value;
                            break;

                        case tlb_size:
                            thread->tlb_size = value;
                            break;

                        case clflush_size:
                            thread->clflush_size = std::stoi(value);
                            break;

                        case cache_alignment:
                            thread->cache_alignment = std::stoi(value);
                            break;

                        case flags:
                            thread->flags = string_helper::split_string(value, ' ');
                            break;

                        case bugs:
                            thread->bugs = string_helper::split_string(value, ' ');
                            break;

                        case bogomips:
                            thread->bogomips = std::stod(value);
                            break;

                        case address_sizes:
                            thread->address_sizes = string_helper::split_string(value, ',');
                            break;

                        case power_management:
                            thread->power_management = string_helper::split_string(value, ' ');
                            break;

                        case new_thread:
                            this->threads.push_back(thread);
                            thread = new cpu();
                            break;

                        default:
                            std::cout << "Error: " << field << " is not a valid field" << std::endl;
                            break;
                    }

                } catch(const std::exception& e) {
                    continue;
                }  
            }

            getUniquePhysicalCores();
        }

        /**
         * @brief Prints information for all threads.
         * 
         */
        void printInfo_AllCores() {
            for (auto thread : this->threads) 
            {
                std::cout << "INFORMATION FOR THREADS " << thread->processor << ":" << std::endl;
                std::cout << "Processor                         : " << thread->processor << std::endl;
                std::cout << "Vendor id                         :" << thread->vendor_id << std::endl;
                std::cout << "CPU Family                        : " << thread->cpu_family << std::endl;
                std::cout << "Model                             : " << thread->model << std::endl;
                std::cout << "Model name                        :" << thread->model_name << std::endl;
                std::cout << "Stepping                          : " << thread->stepping << std::endl;
                std::cout << "Microcode                         :" << thread->microcode << std::endl;
                std::cout << "Clock speed                       : " << thread->clock_speed << " MHz" << std::endl;
                std::cout << "Bogomips                          : " << thread->bogomips << std::endl;
                std::cout << "L2 Cache                          : " << thread->cache << " KB" << std::endl;
                std::cout << "Physical id                       : " << thread->physical_id << std::endl;
                std::cout << "Number of Siblings                : " << thread->siblings << std::endl;
                std::cout << "Core id                           : " << thread->core_id << std::endl;
                std::cout << "Number of cores (total)           : " << thread->cpu_cores << std::endl;
                std::cout << "APIC id                           : " << thread->apicid << std::endl;
                std::cout << "Initial APIC id                   : " << thread->initial_apicid << std::endl;
                std::cout << "Floating-point Support:           :" << thread->fpu << std::endl;
                std::cout << "Floating-point exception Support  :" << thread->fpu_execution << std::endl;
                std::cout << "CPU id level:                     : " << thread->cpuid_level << std::endl;
                std::cout << "Write-Protect:                    :" << thread->wp << std::endl;
                std::cout << "Translation lookaside buffer size :" << thread->tlb_size << std::endl;
                std::cout << "CLFLUSH size                      : " << thread->clflush_size << std::endl;
                std::cout << "Cache alignment                   : " << thread->cache_alignment << std::endl;
                std::cout << "\nFlags:\n";
                for (auto flag : thread->flags) 
                {
                    std::cout << flag << " ";
                }

                std::cout << "\n\nBugs:\n";
                for (auto bug : thread->bugs) 
                {
                    std::cout << bug << " ";
                }

                std::cout << "\n\nAddress sizes:\n";
                for (auto size : thread->address_sizes) 
                {
                    std::cout << size << " ";
                }

                std::cout << "\n\nPower management:\n";
                for (auto management : thread->power_management) 
                {
                    std::cout << management << " ";
                }

                std::cout << "\n------------------------------------\n";
                std::cout << std::endl;
            }
        }

        /**
         * @brief Prints information for each physical cpu.
         * 
         */
        void printInfo_Summation() {
            std::vector<cpu *> unique_phyiscal_cores = this->getUniquePhysicalCores();

            std::cout << "INFORMATION FOR ALL CORES:" << std::endl;
            for (auto core : unique_phyiscal_cores) {
                std::cout << "\nINFORMATION FOR PHYSICAL CORE " << core->processor << ":" << std::endl;
                std::cout << "Vendor id                         :" << core->vendor_id << std::endl;
                std::cout << "CPU Family                        : " << core->cpu_family << std::endl;
                std::cout << "Model                             : " << core->model << std::endl;
                std::cout << "Model name                        :" << core->model_name << std::endl;
                std::cout << "Stepping                          : " << core->stepping << std::endl;
                std::cout << "Microcode                         :" << core->microcode << std::endl;
                std::cout << "Average Clock Speed               : " << core->clock_speed << " MHz" << std::endl;
                std::cout << "Bogomips                          : " << core->bogomips << std::endl;
                std::cout << "L2 Cache                          : " << core->cache << " KB" << std::endl;
                std::cout << "Physical id                       : " << core->physical_id << std::endl;
                std::cout << "Number of cores (total)           : " << core->cpu_cores << std::endl;
                std::cout << "APIC id                           : " << core->apicid << std::endl;
                std::cout << "Initial APIC id                   : " << core->initial_apicid << std::endl;
                std::cout << "Floating-point Support:           :" << core->fpu << std::endl;
                std::cout << "Floating-point exception Support  :" << core->fpu_execution << std::endl;
                std::cout << "CPU id level:                     : " << core->cpuid_level << std::endl;
                std::cout << "Write-Protect:                    :" << core->wp << std::endl;
                std::cout << "Translation lookaside buffer size :" << core->tlb_size << std::endl;
                std::cout << "CLFLUSH size                      : " << core->clflush_size << std::endl;
                std::cout << "Cache alignment                   : " << core->cache_alignment << std::endl;
                std::cout << "\nFlags:\n";
                for (auto flag : core->flags) {
                    std::cout << flag << " ";
                }

                std::cout << "\n\nBugs:\n";
                for (auto bug : core->bugs) {
                    std::cout << bug << " ";
                }

                std::cout << "\n\nAddress sizes:\n";
                for (auto size : core->address_sizes) {
                    std::cout << size << " ";
                }

                std::cout << "\n\nPower management:\n";
                for (auto management : core->power_management) {
                    std::cout << management << " ";
                }

                std::cout << "\n------------------------------------\n";
                std::cout << std::endl;
            }
        }

        /**
         * @brief Get/Update information about the physical cores
         * 
         * @return std::vector<cpu *> containing the physical cores
         */
        std::vector<cpu *> getUniquePhysicalCores() {
            std::vector<cpu *> unique_physical_cores;
            
            //Find unique physical cores
            for (auto thread : this->threads) {
                if (unique_physical_cores.empty()) {
                    unique_physical_cores.push_back(thread);

                } else {
                    for (auto core : unique_physical_cores) {
                        if (thread->physical_id != core->physical_id) {
                            unique_physical_cores.push_back(thread);
                        }
                    }
                }
            }

            this->physical_cores = unique_physical_cores;


            //Update average clock speed for each physical core
            for (auto core : this->physical_cores) {
                //Per physical core
                int total_cache = 0;
                double avg_clock = 0;
                int threads = 0;

                //Accumulate info from threads
                for (auto thread : this->threads) {
                    if (thread->physical_id == core->physical_id) {
                        total_cache += thread->cache;
                        avg_clock += thread->clock_speed;
                        threads++;
                    }
                }

                //Format and add to physical cores
                avg_clock /= threads;
                core->clock_speed = avg_clock;
                core->cache = total_cache;
            }

            return unique_physical_cores;
        }
};
