#ifndef LOADSTYLE_H
#define LOADSTYLE_H
#include <QFile>
#include <QString>

bool LoadStyle(const QString &pathStyle){
    QFile fileStyle(pathStyle);
    if(fileStyle.open(QFile::ReadOnly)){
        QString strCSS = QLatin1String(fileStyle.readAll());
        qApp->setStyleSheet (strCSS);
        return true;
    }else  {
        return false;
    }
     return false;
}

#endif // LOADSTYLE_H
