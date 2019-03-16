/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * @author	Walt Kilar 2019
 * @file	mainwindow.h
 * @brief	Helper file for the AES-256_GUI main method
 * @todo	none
 * 
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"


#include<stdio.h>
#include<stdlib.h>
 
#include "AES-256.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("AFC.ico"));
    setWindowTitle("AES Encryption/ Decryption");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonClearKey_clicked()
{
    ui->lineEditKey1->clear();
    ui->lineEditKey2->clear();
    ui->lineEditKey3->clear();
    ui->lineEditKey4->clear();
}

void MainWindow::on_radioButton16Key_clicked()
{
    ui->lineEditKey3->setEnabled(false);
    ui->lineEditKey4->setEnabled(false);
}


void MainWindow::on_radioButton24Key_clicked()
{
    ui->lineEditKey3->setEnabled(true);
    ui->lineEditKey4->setEnabled(false);
}

void MainWindow::on_radioButton32Key_clicked()
{
    ui->lineEditKey3->setEnabled(true);
    ui->lineEditKey4->setEnabled(true);
}

void MainWindow::on_pushButtonClearInput_clicked()
{
    ui->textEditInput->clear();
}

void MainWindow::on_pushButtonClearOutput_clicked()
{
    ui->textEditOutput->clear();
}

void MainWindow::on_pushButtonEncryption_clicked()
{
    unsigned char Input[256] = {'\0'};
    unsigned char Key[256] = {'\0'};
    QString temp;
    bool ok;
    QStringList list;
    temp = ui->textEditInput->toPlainText().toUpper();
    list = temp.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        Input[i] = list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("Prompt Message"), tr("Data format is incorrect!"), QMessageBox::Ok);
               }
    }
    temp = ui->lineEditKey1->text().append(" "+ui->lineEditKey2->text()).toUpper();
    list = temp.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        Key[i] = list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("Prompt Message"), tr("Data format is incorrect!"), QMessageBox::Ok);
               }
    }
    AES aes1(Key);
    aes1.Cipher(Input);
    QString Dis;
    for(int i=0; i<16; i++)
    {
        QString temp1;
        temp1.sprintf("%02x ", Input[i]);
        Dis += temp1;
    }
    ui->textEditOutput->setText(Dis.toUpper());
}

void MainWindow::on_pushButtonDecryption_clicked()
{
    unsigned char Output[256] = {'\0'};
    unsigned char Key[256] = {'\0'};
    QString temp;
    bool ok;
    QStringList list;
    temp = ui->textEditOutput->toPlainText().toUpper();
    list = temp.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        Output[i] = list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("Prompt Message"), tr("Data format is incorrect!"), QMessageBox::Ok);
               }
    }
    temp = ui->lineEditKey1->text().append(" "+ui->lineEditKey2->text()).toUpper();
    list = temp.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        Key[i] = list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("Prompt Message"), tr("Data format is incorrect!"), QMessageBox::Ok);
               }
    }
    AES aes1(Key);
    aes1.InvCipher(Output);
    QString Dis;
    for(int i=0; i<16; i++)
    {
        QString temp1;
        temp1.sprintf("%02x ", Output[i]);
        Dis += temp1;
    }
    ui->textEditInput->setText(Dis.toUpper());
}
