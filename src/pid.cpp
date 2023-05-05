#include "pid.hpp"

pid::pid(int process) {
    std::string pid_folder = "/proc/" + std::to_string(process) + "/";

    std::vector<std::string> cmdline = file_loader::load_file(pid_folder + "cmdline");
    std::vector<std::string> comm = file_loader::load_file(pid_folder + "console");
    std::vector<std::string> status = file_loader::load_file(pid_folder + "status");
    std::vector<std::string> stat = file_loader::load_file(pid_folder + "stat", ' ');

    this->process_id = process;
    
    for (auto line : status) {
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

    this->cmdline = cmdline.size() > 0 ? cmdline[0] : "";
    this->priority = stat.size() > 0 ? std::stoi(stat[17]) : 0;
    this->nice = stat.size() > 0 ? std::stoi(stat[18]) : 0;
}




