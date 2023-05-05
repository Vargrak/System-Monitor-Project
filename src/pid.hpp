#pragma once
#ifndef PID_HPP
#define PID_HPP

#include <iostream>
#include <string>
#include <vector>

#include "file_loader.hpp"

class pid {
    private:
        int process_id;
        std::string name;
        std::string cmdline;
        std::string state;
        int uid;
        int gid;
        int threads;
        int priority;
        int nice;


    public:
        pid(int pid);
        std::string get_name() { return this->name; }
        std::string get_cmdline() { return this->cmdline; }
        std::string get_state() { return this->state; }
        int get_uid() { return this->uid; }
        int get_gid() { return this->gid; }
        int get_threads() { return this->threads; }
        int get_priority() { return this->priority; }
        int get_nice() { return this->nice; }
};

#endif
