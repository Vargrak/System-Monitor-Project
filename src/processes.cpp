#include "processes.hpp"

processes::processes() {
    this->process_list = this->generate_process_list();
}

std::vector<pid *> processes::generate_process_list() {
    std::vector<pid *> process_list;
    std::string proc_path = "/proc";

    for (auto & file : std::filesystem::directory_iterator(proc_path)) {
        if (file.path().filename().string().find_first_not_of("0123456789") == std::string::npos) {
            process_list.emplace_back(new pid(std::stoi(file.path().filename().string())));
        }
    }

    return process_list;
}

void processes::print_process_list() {
    for (auto process : this->process_list) {
        std::cout << process->get_name() << std::endl;
    }
}