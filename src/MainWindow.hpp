#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include <QApplication>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTimer>

#include <fmt/format.h>

#include "sysinfo.hpp"
#include "ui_SystemResourceMonitor.h"

class MainWindow : public QMainWindow {
   
   Q_OBJECT

    private:
        Ui::MainMenu *ui;
        QTimer refreshInfo;
        sysinfo system;

        void updateResources();


    public:
        MainWindow(QWidget *parent = nullptr) : QMainWindow(parent), ui(new Ui::MainMenu), system(sysinfo()) {
            ui->setupUi(this);

            connect(&refreshInfo, &QTimer::timeout, this, &MainWindow::updateResources);
            refreshInfo.start(1000);
        }

        ~MainWindow() {
            delete ui;
        }
};