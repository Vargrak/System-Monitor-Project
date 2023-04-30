#include <string>
#include <vector>


#include "cpuinfo.cpp"
#include "mem.cpp"
#include "pid.cpp"

/**
 * @brief Class that holds and compiles information from all the cpus, processes, memory, etc; and stores
 * them in a singular class for ease of access.
 * @author Lilith Ernst
 * @version 4-30-23
 * 
 */
class information {
    private:
        cpuinfo system_cpu;
        mem system_mem;
        std::vector<pid> processes;


    public:
};
