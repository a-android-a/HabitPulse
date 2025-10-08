#pragma once
#include<QWidget>

class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;
class QTableWidget;
class QLabel;

class MainWidget: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *m_mainLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonDel;
    QHBoxLayout *HBox;
    QLineEdit *inputField;
    QTableWidget *tableOfHabits;
    QLabel *label;
public:
    MainWidget(QWidget* pwgt  = 0 );

private slots:
    void AddButtonClicked();
    void DeleteButtonClicked();
};

