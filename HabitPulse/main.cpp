#include <QtWidgets>
#include<QVBoxLayout>
#include<QPushButton>
#include<QPalette>
#include <QFile>
#include"LoadStyle.h"
int main (int argc, char** argv){
    QApplication app(argc, argv);

    QWidget wgt;

    wgt.setBackgroundRole(QPalette::ColorRole::Base);
    LoadStyle("style.qss");
    QPushButton* pcmdA = new QPushButton ("Button1");
    QPushButton* pcmdB = new QPushButton ("Button2");
    QPushButton* pcmdC = new QPushButton ("Button3");
    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget (pcmdA);
    pvbxLayout->addWidget (pcmdB);
    pvbxLayout->addWidget (pcmdC);
    wgt.setLayout (pvbxLayout);
    QObject::connect(pcmdA, &QPushButton::clicked, &app, &QApplication::beep);
    QObject::connect(pcmdB, &QPushButton::clicked, &app, &QApplication::beep);
    QObject::connect(pcmdC, &QPushButton::clicked, &app, &QApplication::beep);


    wgt.show();
    return app. exec();
}

