#include "abs.h"
#include "ui_abs.h"

abs::abs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::abs)
{
    ui->setupUi(this);
}

abs::~abs()
{
    delete ui;
}
