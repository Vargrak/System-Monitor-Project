#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include <QApplication>
#include <QMainWindow>

#include <fmt/format.h>

#include "sysinfo.hpp"
#include "MainWindow.hpp"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    return app.exec();
}



/////////////////////////////////////////////////////////////

    // //init ncurses
    // initscr();
    // cbreak();
    // noecho();
    // nodelay(stdscr, true);

    // //hide cursor
    // curs_set(0);


    // int yMaxOld = 0;
    // int xMaxOld = 0;

    // WINDOW *sysinfo_win = nullptr;
    // WINDOW *graphs = nullptr;

    // while (true) {
    //     system.updateAllInfo();

    //     //clear();
    //     if (getch() == 'q') {
    //         break;
    //     }

    //     //get screen size
    //     int yMax, xMax;
    //     getmaxyx(stdscr, yMax, xMax);



    //     //create window
    //     if (yMax != yMaxOld || xMax != xMaxOld) {
    //         if (sysinfo_win != nullptr) {
    //             delwin(sysinfo_win);
    //         }

    //         if (graphs != nullptr) {
    //             delwin(graphs);
    //         }

    //         //Two windows that are 1/4 of the screen
    //         sysinfo_win = newwin(yMax / 2, xMax / 2, 0, 0);
    //         graphs = newwin(yMax / 2, xMax / 2, 0, xMax / 2);
 
    //         yMaxOld = yMax;
    //         xMaxOld = xMax;
    //     }

    //     werase(sysinfo_win);
    //     werase(graphs);

    //     //create box
    //     box(sysinfo_win, 0, 0); //Windows are getting cut off at bottom
    //     box(graphs, 0, 0);

    //     //print to window
    //     mvwprintw(sysinfo_win, 1, 1, "CPU Info");
    //     mvwprintw(sysinfo_win, 2, 1, "CPU Name: %s", system.getCpu().getPhysicalCores()[0]->getModelName().c_str());
    //     mvwprintw(sysinfo_win, 3, 1, "CPU Clock Speed: %.2f GHz", system.getCpu().getPhysicalCores()[0]->getClockSpeed() / 1000);
    //     mvwprintw(sysinfo_win, 4, 1, "CPU Usage: %.2f %%", system.getCpu().getTotalCPUUtilization() * 100);

    //     mvwprintw(sysinfo_win, 6, 1, "Memory Info");
    //     mvwprintw(sysinfo_win, 7, 1, "Total Memory: %ld", system.getMemory().getTotalMemory());
    //     mvwprintw(sysinfo_win, 8, 1, "Memory Usage: %ld / %ld", system.getMemory().getTotalMemory() - system.getMemory().getAvailableMemory(), system.getMemory().getTotalMemory());


    //     std::string memoryGraph = "";
    //     for (int i = 0; i < (system.getMemory().getTotalMemory() - system.getMemory().getAvailableMemory()) / 1000000; i++) {
    //         memoryGraph += "[#]";
    //     }

    //     for (int i = 0; i < system.getMemory().getAvailableMemory() / 1000000; i++) {
    //         memoryGraph += "[ ]";
    //     }

    //     std::string cpuGraph = "";
    //     for (int i = 0; i < system.getCpu().getTotalCPUUtilization() * 20; i++) {
    //         cpuGraph += "[#]";
    //     }

    //     for (int i = 0; i < 20 - (system.getCpu().getTotalCPUUtilization() * 20); i++) {
    //         cpuGraph += "[ ]";
    //     }


    //     mvwprintw(graphs, 1, 1, "Memory Usage Graph");
    //     mvwprintw(graphs, 2, 1, "%s" , memoryGraph.c_str());
    //     mvwprintw(graphs, 4, 1, "Total Cpu Usage");
    //     mvwprintw(graphs, 5, 1, "%s", cpuGraph.c_str());
        

    //     //refresh window
    //     wrefresh(sysinfo_win);
    //     wrefresh(graphs);

    //     std::this_thread::sleep_for(std::chrono::milliseconds(((int)(refreshRate * 1000))));
    // }

    // delwin(sysinfo_win);
    // delwin(graphs);

    // endwin();