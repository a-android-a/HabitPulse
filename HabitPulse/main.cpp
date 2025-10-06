#include <QtWidgets>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include "LoadStyle.h"

int main (int argc, char** argv){
    QApplication app(argc, argv);

    QWidget window;
    window.setBackgroundRole(QPalette::ColorRole::Base);
    LoadStyle("style.qss");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QPushButton *buttonAdd = new QPushButton();
    QVBoxLayout *VBox = new QVBoxLayout();
    QLineEdit *inputField = new QLineEdit();
    QTableWidget *tableOfHabits = new QTableWidget(0, 1);
    QLabel *label = new QLabel("basic habits");
    inputField->setPlaceholderText("habit");
    buttonAdd->setText("Add");
    tableOfHabits->setHorizontalHeaderItem(1, new QTableWidgetItem("Name of the habit"));
    tableOfHabits->resizeColumnsToContents();

    layout->addWidget(inputField);
    layout->addWidget(buttonAdd);
    layout->addWidget(label);
    layout->addWidget(tableOfHabits);


    QObject::connect(buttonAdd, &QPushButton::clicked, [tableOfHabits,inputField]() {
        tableOfHabits->setRowCount(tableOfHabits->rowCount() + 1  );
        QTableWidgetItem *textItem = new QTableWidgetItem(inputField->text());
        tableOfHabits->setItem(tableOfHabits->rowCount()-1, 0, textItem);
        tableOfHabits->resizeColumnsToContents();
        inputField->clear();
    });


    window.setLayout(layout);
    window.show();
    return app. exec();
}

