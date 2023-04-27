#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.cpp"
#include "string_helper.cpp"

/**
 * @brief Class for storing information about a single cpu thread from /proc/cpuinfo.
 * @author Lilith Ernst
 * @version 4-17-23
 * 
 */
class cpuinfo
{
    private:
        class cpu
        {
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

        enum FIELDS 
        {
            processor, vendor_id, cpu_family, model, model_name, stepping, 
            microcode, clock_speed, cache, physical_id, siblings, core_id, 
            cpu_cores, apicid, initial_apicid, fpu, fpu_execution, cpuid_level, 
            wp, flags, bugs, bogomips, tlb_size, clflush_size, cache_alignment, 
            address_sizes, power_management
        };

        std::map<std::string, FIELDS> field_map = 
        {
            {"processor:", processor}, {"vendor_id:", vendor_id}, {"cpufamily:", cpu_family}, {"model:", model}, {"modelname:", model_name}, {"stepping:", stepping}, 
            {"microcode:", microcode}, {"cpuMHz:", clock_speed}, {"cachesize:", cache}, {"physicalid:", physical_id}, {"siblings:", siblings}, {"coreid:", core_id}, 
            {"cpucores:", cpu_cores}, {"apicid:", apicid}, {"initialapicid:", initial_apicid}, {"fpu:", fpu}, {"fpu_exception:", fpu_execution}, {"cpuidlevel:", cpuid_level}, 
            {"wp:", wp}, {"flags:", flags}, {"bugs:", bugs}, {"bogomips:", bogomips}, {"TLBsize:", tlb_size}, {"clflushsize:", clflush_size}, {"cache_alignment:", cache_alignment}, 
            {"addresssizes:", address_sizes}, {"powermanagement:", power_management}
        };
            
        std::vector<cpu *> threads;
        
    public:

        void updateInfo() 
        {
            std::vector<std::string> cputext = file_loader::load_file("/proc/cpuinfo");
            cpu *thread = new cpu();

            for (auto line : cputext)
            {
                std::string field = string_helper::remove_whitespace(line.substr(0, line.find(":") + 1));
                std::string value = line.substr(line.find(":") + 1);

                try
                {
                    switch (field_map[field]) 
                    {
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
                        default:
                            //std::cout << "Error: " << field << " is not a valid field" << std::endl;
                            break;
                    }
                }

                catch(const std::exception& e)
                {
                    continue;
                }
                

                
            }

            this->threads.push_back(thread);
        }

        void printInfo() {
            for (auto thread : this->threads) 
            {
                std::cout << "processor: " << thread->processor << std::endl;
                std::cout << "vendor_id: " << thread->vendor_id << std::endl;
                std::cout << "cpu_family: " << thread->cpu_family << std::endl;
                std::cout << "model: " << thread->model << std::endl;
                std::cout << "model_name: " << thread->model_name << std::endl;
                std::cout << "stepping: " << thread->stepping << std::endl;
                std::cout << "microcode: " << thread->microcode << std::endl;
                std::cout << "clock_speed: " << thread->clock_speed << std::endl;
                std::cout << "cache: " << thread->cache << std::endl;
                std::cout << "physical_id: " << thread->physical_id << std::endl;
                std::cout << "siblings: " << thread->siblings << std::endl;
                std::cout << "core_id: " << thread->core_id << std::endl;
                std::cout << "cpu_cores: " << thread->cpu_cores << std::endl;
                std::cout << "apicid: " << thread->apicid << std::endl;
                std::cout << "initial_apicid: " << thread->initial_apicid << std::endl;
                std::cout << "fpu: " << thread->fpu << std::endl;
                std::cout << "fpu_execution: " << thread->fpu_execution << std::endl;
                std::cout << "cpuid_level: " << thread->cpuid_level << std::endl;
                std::cout << "wp: " << thread->wp << std::endl;
                // std::cout << "flags: ";
                // for (auto flag : thread->flags) 
                // {
                //     std::cout << flag << " ";
                // }

                std::cout << std::endl;
            }
        }
};
