#include <curses.h>
#include <ncurses.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>



#include "sysinfo.hpp"


int main() {
    sysinfo system = sysinfo();

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, true);

    //hide cursor
    curs_set(0);


    int yMaxOld = 0;
    int xMaxOld = 0;

    WINDOW *sysinfo_win = nullptr;
    WINDOW *graphs = nullptr;

    while (true) {
        system.updateAllInfo();

        clear();
        if (getch() == 'q') {
            break;
        }

        //get screen size
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);



        //create window
        if (yMax != yMaxOld || xMax != xMaxOld) {
            if (sysinfo_win != nullptr) {
                delwin(sysinfo_win);
            }

            if (graphs != nullptr) {
                delwin(graphs);
            }

            //Two windows that are 1/4 of the screen
            sysinfo_win = newwin(yMax / 2, xMax / 2, 0, 0);
            graphs = newwin(yMax / 2, xMax / 2, 0, xMax / 2);
 
            yMaxOld = yMax;
            xMaxOld = xMax;
        }

        werase(sysinfo_win);
        werase(graphs);

        //create box
        box(sysinfo_win, 0, 0);
        box(graphs, 0, 0);

        //print to window
        mvwprintw(sysinfo_win, 1, 1, "CPU Info");
        mvwprintw(sysinfo_win, 2, 1, "CPU Name: %s", system.getCpu().getPhysicalCores()[0]->getModelName().c_str());
        mvwprintw(sysinfo_win, 3, 1, "CPU Clock Speed: %f", system.getCpu().getPhysicalCores()[0]->getClockSpeed());
        mvwprintw(sysinfo_win, 4, 1, "CPU Cache: %d", system.getCpu().getPhysicalCores()[0]->getCache());
        mvwprintw(sysinfo_win, 5, 1, "CPU Cores: %d", system.getCpu().getPhysicalCores()[0]->getCPUCores());
        mvwprintw(sysinfo_win, 6, 1, "CPU Threads: %d", system.getCpu().getPhysicalCores()[0]->getSiblings());

        mvwprintw(sysinfo_win, 8, 1, "Memory Info");
        mvwprintw(sysinfo_win, 9, 1, "Total Memory: %ld", system.getMemory().getTotalMemory());
        mvwprintw(sysinfo_win, 10, 1, "Free Memory: %ld", system.getMemory().getAvailableMemory());
        mvwprintw(sysinfo_win, 11, 1, "Used Memory: %ld", system.getMemory().getTotalMemory() - system.getMemory().getAvailableMemory());


        std::string memoryGraph = "";
        for (int i = 0; i < (system.getMemory().getTotalMemory() - system.getMemory().getAvailableMemory()) / 1000000; i++) {
            memoryGraph += "[#]";
        }

        for (int i = 0; i < system.getMemory().getAvailableMemory() / 1000000; i++) {
            memoryGraph += "[ ]";
        }

        mvwprintw(graphs, 1, 1, "Memory Usage Graph");
        mvwprintw(graphs, 2, 1, "%s" , memoryGraph.c_str());

        //refresh window
        wrefresh(sysinfo_win);
        wrefresh(graphs);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    delwin(sysinfo_win);
    delwin(graphs);

    endwin();
    return 0;
} 