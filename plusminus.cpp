#include "plusminus.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget *parent) : QWidget(parent)
{
    QPushButton *plsBtn = new QPushButton("+",this);
    QPushButton *mnsBtn = new QPushButton("-",this);
    lbl = new QLabel("0", this);

    QGridLayout *grid = new QGridLayout(this);

    grid->addWidget(plsBtn,0,0);
    grid->addWidget(mnsBtn, 0, 1);
    grid->addWidget(lbl,1,1);

    setLayout(grid);

    connect(plsBtn, &QPushButton::clicked,this, &PlusMinus::OnPlus);
    connect(mnsBtn, &QPushButton::clicked,this, &PlusMinus::OnMinus);
}

void PlusMinus::OnPlus()
{
    int val = lbl->text().toInt();
    val++;
    lbl->setText(QString::number(val));
}

void PlusMinus::OnMinus()
{
    int val = lbl->text().toInt();
    val--;
    lbl->setText(QString::number(val));
}
