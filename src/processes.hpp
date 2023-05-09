#pragma once
#ifndef PROCESSES_HPP
#define PROCESSES_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

#include "pid.hpp"

/**
 * @brief Class for representing all processes on the system
 * @author Lilith Ernst
 * 
 * @version 5-9-23
 * 
 */
class processes {
    private:
        std::vector<pid *> process_list;

    public:
        processes();

        std::vector<pid *> generateProcessList();
        void printProcessList();

        void updateInfo();
};

#endif