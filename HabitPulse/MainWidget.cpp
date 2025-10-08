#include "MainWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QLabel>
#include <QHeaderView>

MainWidget::MainWidget(QWidget *pwgt) : QWidget(pwgt){

    m_mainLayout = new QVBoxLayout();
    buttonAdd = new QPushButton();
    buttonDel = new QPushButton();
    HBox = new QHBoxLayout();
    inputField = new QLineEdit();
    tableOfHabits = new QTableWidget(0, 1);
    label = new QLabel("basic habits");
    inputField->setPlaceholderText("habit");
    buttonAdd->setText("Add");
    buttonDel->setText("Del");
    tableOfHabits->setHorizontalHeaderItem(1, new QTableWidgetItem("Name of the habit"));
    tableOfHabits->resizeColumnsToContents();

    m_mainLayout->addWidget(inputField);
    m_mainLayout->addWidget(buttonAdd);
    m_mainLayout->addWidget(label);
    m_mainLayout->addWidget(tableOfHabits);

    m_mainLayout->addLayout(HBox);

    HBox->addWidget(buttonDel);
    this->setLayout(m_mainLayout);
    this->setLayout(HBox);
    connect(buttonAdd, &QPushButton::clicked, this, &MainWidget::AddButtonClicked);
    connect(buttonDel, &QPushButton::clicked, this, &MainWidget::DeleteButtonClicked);

}

void MainWidget::AddButtonClicked(){
    tableOfHabits->setRowCount(tableOfHabits->rowCount() + 1  );
    QTableWidgetItem *textItem = new QTableWidgetItem(inputField->text());
    tableOfHabits->setItem(tableOfHabits->rowCount()-1, 0, textItem);
    tableOfHabits->resizeColumnsToContents();
    inputField->clear();
}
void MainWidget::DeleteButtonClicked(){

}

