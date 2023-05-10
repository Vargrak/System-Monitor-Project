#include "cpuinfo.hpp"

/**
 * @brief Class for storing information about the system's cpu from /proc/cpuinfo.
 * @author Lilith Ernst
 * @version 5-9-23
 * 
 */

cpuinfo::cpuinfo() {
    this->updateInfo();
}

/**
 * @brief Updates the information stored in the cpuinfo class.
 * 
 */
void cpuinfo::updateInfo() {
    if (!this->threads.empty()) {
        this->physical_cores.erase(this->physical_cores.begin(), this->physical_cores.end());
        this->physical_cores.shrink_to_fit();

        for (auto thread : this->threads) {
            delete thread;
        }

        this->threads.erase(this->threads.begin(), this->threads.end());
        this->threads.shrink_to_fit();
    }

    std::vector<std::string> cputext = file_loader::load_file("/proc/cpuinfo");
    cpu *thread = new cpu();
    
    for (auto line : cputext) {
        std::string field = string_helper::remove_whitespace(line.substr(0, line.find(":") + 1));
        std::string value = line.substr(line.find(":") + 1);

        try {
            switch (field_map[field]) {
                case processor:
                    thread->setProcessor(std::stoi(value));
                    break;

                case vendor_id:
                    thread->setVendorID(value);
                    break;

                case cpu_family:
                    thread->setCPUFamily(std::stoi(value));
                    break;

                case model:
                    thread->setModel(std::stoi(value));
                    break;

                case model_name:
                    thread->setModelName(value);
                    break;

                case stepping:
                    thread->setStepping(std::stoi(value));
                    break;

                case microcode:
                    thread->setMicrocode(value);
                    break;

                case clock_speed:
                    thread->setClockSpeed(std::stod(value));
                    break;

                case cache:
                    thread->setCache(std::stoi(value));
                    break;

                case physical_id:
                    thread->setPhysicalID(std::stoi(value));
                    break;

                case siblings:
                    thread->setSiblings(std::stoi(value));
                    break;

                case core_id:
                    thread->setCoreID(std::stoi(value));
                    break;

                case cpu_cores:
                    thread->setCPUCores(std::stoi(value));
                    break;

                case apicid:
                    thread->setAPICID(std::stoi(value));
                    break;

                case initial_apicid:
                    thread->setInitialAPICID(std::stoi(value));
                    break;

                case fpu:
                    thread->setFPU(value);
                    break;

                case fpu_execution:
                    thread->setFPUExecution(value);
                    break;

                case cpuid_level:
                    thread->setCPUIDLevel(std::stoi(value));
                    break;

                case wp:
                    thread->setWP(value);
                    break;

                case tlb_size:
                    thread->setTLBSize(value);
                    break;

                case clflush_size:
                    thread->setCLFlushSize(std::stoi(value));
                    break;

                case cache_alignment:
                    thread->setCacheAlignment(std::stoi(value));
                    break;

                case flags:
                    thread->setFlags(string_helper::split_string(value, ' '));
                    break;

                case bugs:
                    thread->setBugs(string_helper::split_string(value, ' '));
                    break;

                case bogomips:
                    thread->setBogomips(std::stod(value));
                    break;

                case address_sizes:
                    thread->setAddressSizes(string_helper::split_string(value, ' '));
                    break;

                case power_management:
                    thread->setPowerManagement(string_helper::split_string(value, ' '));
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
    cputext.clear();
}

/**
 * @brief Prints information for all threads.
 * 
 */
void cpuinfo::printInfo_AllCores() {
    for (auto thread : this->threads) 
    {
        std::cout << "INFORMATION FOR THREADS " << thread->getProcessor() << ":" << std::endl;
        std::cout << "Processor                         : " << thread->getProcessor() << std::endl;
        std::cout << "Vendor id                         :" << thread->getVendorID() << std::endl;
        std::cout << "CPU Family                        : " << thread->getCPUFamily() << std::endl;
        std::cout << "Model                             : " << thread->getModel() << std::endl;
        std::cout << "Model name                        :" << thread->getModelName() << std::endl;
        std::cout << "Stepping                          : " << thread->getStepping() << std::endl;
        std::cout << "Microcode                         :" << thread->getMicrocode() << std::endl;
        std::cout << "Clock speed                       : " << thread->getClockSpeed() << " MHz" << std::endl;
        std::cout << "Bogomips                          : " << thread->getBogomips() << std::endl;
        std::cout << "L2 Cache                          : " << thread->getCache() << " KB" << std::endl;
        std::cout << "Physical id                       : " << thread->getPhysicalID() << std::endl;
        std::cout << "Number of Siblings                : " << thread->getSiblings() << std::endl;
        std::cout << "Core id                           : " << thread->getCoreID() << std::endl;
        std::cout << "Number of cores (total)           : " << thread->getCPUCores() << std::endl;
        std::cout << "APIC id                           : " << thread->getAPICID() << std::endl;
        std::cout << "Initial APIC id                   : " << thread->getInitialAPICID() << std::endl;
        std::cout << "Floating-point Support:           :" << thread->getFPU() << std::endl;
        std::cout << "Floating-point exception Support  :" << thread->getFPUExecution() << std::endl;
        std::cout << "CPU id level:                     : " << thread->getCPUIDLevel() << std::endl;
        std::cout << "Write-Protect:                    :" << thread->getWP() << std::endl;
        std::cout << "Translation lookaside buffer size :" << thread->getTLBSize() << std::endl;
        std::cout << "CLFLUSH size                      : " << thread->getCLFlushSize() << std::endl;
        std::cout << "Cache alignment                   : " << thread->getCacheAlignment() << std::endl;
        std::cout << "\nFlags:\n";
        for (auto flag : thread->getFlags()) 
        {
            std::cout << flag << " ";
        }

        std::cout << "\n\nBugs:\n";
        for (auto bug : thread->getBugs()) 
        {
            std::cout << bug << " ";
        }

        std::cout << "\n\nAddress sizes:\n";
        for (auto size : thread->getAddressSizes()) 
        {
            std::cout << size << " ";
        }

        std::cout << "\n\nPower management:\n";
        for (auto management : thread->getPowerManagement()) 
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
void cpuinfo::printInfo_Summation() {
    std::vector<cpu *> unique_phyiscal_cores = this->getUniquePhysicalCores();

    std::cout << "INFORMATION FOR ALL CORES:" << std::endl;
    for (auto core : unique_phyiscal_cores) {
        std::cout << "\nINFORMATION FOR PHYSICAL CORE " << core->getProcessor() << ":" << std::endl;
        std::cout << "Vendor id                         :" << core->getVendorID() << std::endl;
        std::cout << "CPU Family                        : " << core->getCPUFamily() << std::endl;
        std::cout << "Model                             : " << core->getModel() << std::endl;
        std::cout << "Model name                        :" << core->getModelName() << std::endl;
        std::cout << "Stepping                          : " << core->getStepping() << std::endl;
        std::cout << "Microcode                         :" << core->getMicrocode() << std::endl;
        std::cout << "Average Clock Speed               : " << core->getClockSpeed() << " MHz" << std::endl;
        std::cout << "Bogomips                          : " << core->getBogomips() << std::endl;
        std::cout << "L2 Cache                          : " << core->getCache() << " KB" << std::endl;
        std::cout << "Physical id                       : " << core->getPhysicalID() << std::endl;
        std::cout << "Number of cores (total)           : " << core->getCPUCores() << std::endl;
        std::cout << "APIC id                           : " << core->getAPICID() << std::endl;
        std::cout << "Initial APIC id                   : " << core->getInitialAPICID() << std::endl;
        std::cout << "Floating-point Support:           :" << core->getFPU() << std::endl;
        std::cout << "Floating-point exception Support  :" << core->getFPUExecution() << std::endl;
        std::cout << "CPU id level:                     : " << core->getCPUIDLevel() << std::endl;
        std::cout << "Write-Protect:                    :" << core->getWP() << std::endl;
        std::cout << "Translation lookaside buffer size :" << core->getTLBSize() << std::endl;
        std::cout << "CLFLUSH size                      : " << core->getCLFlushSize() << std::endl;
        std::cout << "Cache alignment                   : " << core->getCacheAlignment() << std::endl;
        std::cout << "\nFlags:\n";
        for (auto flag : core->getFlags()) {
            std::cout << flag << " ";
        }

        std::cout << "\n\nBugs:\n";
        for (auto bug : core->getBugs()) {
            std::cout << bug << " ";
        }

        std::cout << "\n\nAddress sizes:\n";
        for (auto size : core->getAddressSizes()) {
            std::cout << size << " ";
        }

        std::cout << "\n\nPower management:\n";
        for (auto management : core->getPowerManagement()) {
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
std::vector<cpuinfo::cpu *> cpuinfo::getUniquePhysicalCores() {
    std::vector<cpu *> unique_physical_cores;
    
    //Find unique physical cores
    for (auto thread : this->threads) {
        if (unique_physical_cores.empty()) {
            unique_physical_cores.emplace_back(thread);

        } else {
            for (auto core : unique_physical_cores) {
                if (thread->getPhysicalID() != core->getPhysicalID()) {
                    unique_physical_cores.emplace_back(thread);
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
        int no_threads = 0;


        //Accumulate info from threads
        for (auto thread : this->threads) {

            if (thread->getPhysicalID() == core->getPhysicalID()) {
                total_cache += thread->getCache();
                avg_clock += thread->getClockSpeed();
                no_threads++;
            }
        }

        //Format and add to physical cores
        avg_clock /= no_threads;
        core->setClockSpeed(avg_clock);
        core->setCache(total_cache);
    }

    return unique_physical_cores;
}

/**
 * @brief Get the Physical Cores object
 * 
 * @return std::vector<cpu *> 
 */
std::vector<cpuinfo::cpu *> cpuinfo::getPhysicalCores() { return this->physical_cores; }

/**
 * @brief Get the Threads object
 * 
 * @return std::vector<cpu *> 
 */
std::vector<cpuinfo::cpu *> cpuinfo::getThreads() { return this->threads; }

