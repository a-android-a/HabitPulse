#include <QtWidgets>
#include <QFile>
#include <QMessageBox>
#include "LoadStyle.h"
#include"MainWidget.h"
int main (int argc, char** argv){
    QApplication app(argc, argv);

    QWidget window;
    window.setBackgroundRole(QPalette::ColorRole::Base);

    if(!LoadStyle("style.qss")){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("The style file was not found");
        msgBox.exec();
    }
    MainWidget *mainWidget = new MainWidget();
    mainWidget->show();
    return app. exec();
}

