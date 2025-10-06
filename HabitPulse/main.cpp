#include <QtWidgets>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QVBoxLayout>
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

    inputField->setPlaceholderText("habit");
    buttonAdd->setText("Add");

    layout->addWidget(inputField);
    layout->addWidget(buttonAdd);
    window.setLayout(layout);
    window.show();
    return app. exec();
}

