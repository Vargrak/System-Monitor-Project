#include "MainWindow.hpp"

void MainWindow::updateResources() {
            system.updateAllInfo();

            double cpuUtilization = system.getCpu().getTotalCPUUtilization() * 100;
            double usedMemory = (system.getMemory().getTotalMemory() - system.getMemory().getAvailableMemory());
            double totalMemory = system.getMemory().getTotalMemory();

            ui->CPUBar->setValue(cpuUtilization);
            ui->MemoryBar->setValue(usedMemory / totalMemory * 100);

            ui->DataTable->setItem(0, 0, new QTableWidgetItem(system.getCpu().getPhysicalCores()[0]->getModelName().c_str()));
            ui->DataTable->setItem(1, 0, new QTableWidgetItem(fmt::format("{:.2f} GHz", system.getCpu().getPhysicalCores()[0]->getClockSpeed() / 1000).c_str()));
            ui->DataTable->setItem(2, 0, new QTableWidgetItem(fmt::format("{:.2f} %", system.getCpu().getTotalCPUUtilization() * 100).c_str()));

            ui->DataTable->setItem(5, 0, new QTableWidgetItem(fmt::format("{} / {} Gb",
                 (system.getMemory().getTotalMemory() - system.getMemory().getAvailableMemory()) / 1000000, system.getMemory().getTotalMemory() / 1000000).c_str()));
}