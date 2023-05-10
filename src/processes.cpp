#include "processes.hpp"

/**
 * @brief Construct a new processes::processes object
 * 
 */
processes::processes() {
    this->process_list = this->generateProcessList();
}

/**
 * @brief Generates a list of all processes on the system
 * 
 * @return std::vector<pid *> Vector containing all processes on the system
 */
std::vector<pid *> processes::generateProcessList() {
    if (!this->process_list.empty()) {
        for (auto process : this->process_list) {
            delete process;
        }

        this->process_list.erase(this->process_list.begin(), this->process_list.end());
        this->process_list.shrink_to_fit();
    }


    std::vector<pid *> new_process_list;
    std::string proc_path = "/proc";

    for (auto & file : std::filesystem::directory_iterator(proc_path)) {
        if (file.path().filename().string().find_first_not_of("0123456789") == std::string::npos) {
            new_process_list.emplace_back(new pid(std::stoi(file.path().filename().string())));
        }
    }

    return new_process_list;
}

/**
 * @brief Prints the list of processes on the system by name in ID ascending order
 * 
 */
void processes::printProcessList() {
    for (auto process : this->process_list) {
        std::cout << process->get_name() << std::endl;
    }
}

/**
 * @brief Updates the list of processes on the system
 * 
 */
void processes::updateInfo() {
    this->process_list = this->generateProcessList();
}