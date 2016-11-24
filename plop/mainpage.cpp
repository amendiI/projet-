#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);
}

mainpage::~mainpage()
{
    delete ui;
}
