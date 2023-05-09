#include "pid.hpp"

/**
 * @brief Construct a new pid::pid object
 * 
 * @param process ID number of the process
 */
pid::pid(int process) {
    //Set proc
    std::string pid_folder = "/proc/" + std::to_string(process) + "/";

    //Read from each file
    std::vector<std::string> tmp_cmdline = file_loader::load_file(pid_folder + "cmdline");
    std::vector<std::string> tmp_comm = file_loader::load_file(pid_folder + "console");
    std::vector<std::string> tmp_status = file_loader::load_file(pid_folder + "status");
    std::vector<std::string> tmp_stat = file_loader::load_file(pid_folder + "stat", ' ');

    //Set process id
    this->process_id = process;
    
    //Set other variables
    for (auto line : tmp_status) {
        if (line.find("Name") != std::string::npos) {
            this->name = line.substr(line.find(":") + 2);

        } else if (line.find("Uid") != std::string::npos) {
            this->uid = std::stoi(line.substr(line.find(":") + 2, line.find(" ")));

        } else if (line.find("Gid") != std::string::npos) {
            this->gid = std::stoi(line.substr(line.find(":") + 2, line.find(" ")));

        } else if (line.find("Threads") != std::string::npos) {
            this->threads = std::stoi(line.substr(line.find(":") + 2, line.find(" ")));
            
        } else if (line.find("State") != std::string::npos) {
            this->state = line.substr(line.find(":") + 2);
        }
    }

    this->cmdline = tmp_cmdline.size() > 0 ? tmp_cmdline[0] : "";
    this->priority = tmp_stat.size() > 0 ? std::stoi(tmp_stat[17]) : 0;
    this->nice = tmp_stat.size() > 0 ? std::stoi(tmp_stat[18]) : 0;
}




