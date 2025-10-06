#include <QtWidgets>
#include<QVBoxLayout>
#include<QPushButton>
#include<QPalette>
#include <QFile>

int main (int argc, char** argv){
    QApplication app(argc, argv);

    QWidget wgt;

    wgt.setBackgroundRole(QPalette::ColorRole::Base);
    QPushButton* pcmdA = new QPushButton ("Button1");
    QPushButton* pcmdB = new QPushButton ("Button2");
    QPushButton* pcmdC = new QPushButton ("Button3");
    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget (pcmdA);
    pvbxLayout->addWidget (pcmdB) ;
    pvbxLayout->addWidget (pcmdC);
    wgt.setLayout (pvbxLayout);
    QObject::connect(pcmdA, &QPushButton::clicked, &app, &QApplication::beep);
    QObject::connect(pcmdB, &QPushButton::clicked, &app, &QApplication::beep);
    QObject::connect(pcmdC, &QPushButton::clicked, &app, &QApplication::beep);
    QFile file("style.qss");
    file.open (QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll());
    qDebug() << strCSS;
    qApp->setStyleSheet (strCSS);
    wgt.show();
    return app. exec();
}

