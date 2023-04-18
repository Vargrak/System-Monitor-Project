#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.cpp"

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

        std::vector<std::tuple<std::string, FIELDS>> field_map
        {
            std::make_tuple("processor", processor),
            std::make_tuple("vendor_id", vendor_id),
            std::make_tuple("cpu_family", cpu_family),
            std::make_tuple("model", model),
            std::make_tuple("model_name", model_name),
            std::make_tuple("stepping", stepping),
            std::make_tuple("microcode", microcode),
            std::make_tuple("clock_speed", clock_speed),
            std::make_tuple("cache", cache),
            std::make_tuple("physical_id", physical_id),
            std::make_tuple("siblings", siblings),
            std::make_tuple("core_id", core_id),
            std::make_tuple("cpu_cores", cpu_cores),
            std::make_tuple("apicid", apicid),
            std::make_tuple("initial_apicid", initial_apicid),
            std::make_tuple("fpu", fpu),
            std::make_tuple("fpu_execution", fpu_execution),
            std::make_tuple("cpuid_level", cpuid_level),
            std::make_tuple("wp", wp),
            std::make_tuple("flags", flags),
            std::make_tuple("bugs", bugs),
            std::make_tuple("bogomips", bogomips),
            std::make_tuple("tlb_size", tlb_size),
            std::make_tuple("clflush_size", clflush_size),
            std::make_tuple("cache_alignment", cache_alignment),
            std::make_tuple("address_sizes", address_sizes),
            std::make_tuple("power_management", power_management)
        };

        std::vector<cpu *> threads;
        
    public:

        void updateInfo() 
        {
            
            cpu *current_thread = new cpu();

            for (auto line : cputext) 
            {
                line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
            }
        }

        std::vector<std::string> formatInfo()
        {
            std::vector<std::string> cputext = file_loader::load_file("/proc/cpuinfo");
            std::vector<std::string> formatted;

            for (auto line : cputext) 
            {
                formatted.emplace_back(line.erase(remove_if(line.begin(), line.end(), isspace), line.end()));
            }
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
                std::cout << "flags: ";
                for (auto flag : thread->flags) 
                {
                    std::cout << flag << " ";
                }

                std::cout << std::endl;
            }
        }
};
