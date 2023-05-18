/********************************************************************************
** Form generated from reading UI file 'SystemResourceMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMRESOURCEMONITOR_H
#define UI_SYSTEMRESOURCEMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QTableWidget *DataTable;
    QProgressBar *CPUBar;
    QProgressBar *MemoryBar;
    QLabel *CPULabelBar;
    QLabel *MemoryLabelBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 596);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DataTable = new QTableWidget(centralwidget);
        if (DataTable->columnCount() < 1)
            DataTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (DataTable->rowCount() < 6)
            DataTable->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        DataTable->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        DataTable->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        DataTable->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        DataTable->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        DataTable->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        DataTable->setVerticalHeaderItem(5, __qtablewidgetitem6);
        DataTable->setObjectName(QString::fromUtf8("DataTable"));
        DataTable->setGeometry(QRect(5, 11, 391, 561));
        CPUBar = new QProgressBar(centralwidget);
        CPUBar->setObjectName(QString::fromUtf8("CPUBar"));
        CPUBar->setGeometry(QRect(440, 70, 281, 51));
        CPUBar->setValue(0);
        MemoryBar = new QProgressBar(centralwidget);
        MemoryBar->setObjectName(QString::fromUtf8("MemoryBar"));
        MemoryBar->setGeometry(QRect(440, 260, 281, 51));
        MemoryBar->setValue(0);
        CPULabelBar = new QLabel(centralwidget);
        CPULabelBar->setObjectName(QString::fromUtf8("CPULabelBar"));
        CPULabelBar->setGeometry(QRect(440, 50, 71, 18));
        MemoryLabelBar = new QLabel(centralwidget);
        MemoryLabelBar->setObjectName(QString::fromUtf8("MemoryLabelBar"));
        MemoryLabelBar->setGeometry(QRect(440, 230, 101, 18));
        MainMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = DataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainMenu", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = DataTable->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainMenu", "CPU Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = DataTable->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainMenu", "CPU Clock Speed", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = DataTable->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainMenu", "CPU Usage", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = DataTable->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainMenu", "Memory", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = DataTable->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainMenu", "Memory Usage", nullptr));
        CPULabelBar->setText(QCoreApplication::translate("MainMenu", "CPU Usage", nullptr));
        MemoryLabelBar->setText(QCoreApplication::translate("MainMenu", "Memory Usage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMRESOURCEMONITOR_H
