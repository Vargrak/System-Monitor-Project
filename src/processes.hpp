#pragma once
#ifndef PROCESSES_HPP
#define PROCESSES_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

#include "pid.hpp"

class processes {
    private:
        std::vector<pid *> process_list;

    public:
        processes();

        std::vector<pid *> generate_process_list();
        void print_process_list();
};

#endif