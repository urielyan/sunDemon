#include "VirtualKeyboard.h"
#include "ui_VirtualKeyboard.h"

#include <QDebug>

VirtualKeyboard::VirtualKeyboard(QWidget *parent) :
    Widget(parent),
    ui(new Ui::VirtualKeyboard)
{
    ui->setupUi(this);

    QList<QPushButton *> allPButtons = this->findChildren<QPushButton *>();
    foreach (QPushButton *b, allPButtons) {
        connect(b, &QPushButton::clicked, this, &VirtualKeyboard::buttonsClicked);
    }
}

VirtualKeyboard::~VirtualKeyboard()
{
    delete ui;
}

QString VirtualKeyboard::getStr()
{
    return ui->lineEdit->text();
}

void VirtualKeyboard::setInputMask(QString inputMask)
{
    ui->lineEdit->setInputMask(inputMask);
}

void VirtualKeyboard::setInitText(QString str)
{
    ui->lineEdit->setText(str);
}

void VirtualKeyboard::buttonsClicked()
{
    QPushButton *b = static_cast<QPushButton*>(sender());
    if (!b)
    {
        return;
    }

    //若不是数字则返回
    bool ok = false;
    float number = b->text().toFloat(&ok);
    Q_UNUSED(number);
    if (!ok)
    {
        return;
    }

    ui->lineEdit->setText(ui->lineEdit->text().append(b->text()));
    //qDebug() << number << b->text() << ui->lineEdit->text().toFloat() << ok;
}

void VirtualKeyboard::on_backspace_clicked()
{
    QString currentText = ui->lineEdit->text();
    ui->lineEdit->setText(currentText.left(currentText.size() - 1));
}

void VirtualKeyboard::on_clear_clicked()
{
    ui->lineEdit->clear();
}

void VirtualKeyboard::on_ok_clicked()
{
    emit inputComplete(QString::number(ui->lineEdit->text().toFloat()));
    qDebug() << ui->lineEdit->text().toFloat();
}

void VirtualKeyboard::on_point_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("."));
}
