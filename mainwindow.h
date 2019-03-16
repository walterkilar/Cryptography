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
 * @brief	Header file for the AES-256_GUI GUI
 * @todo	Fix 24 and 32-bit key length encryption
 * 
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonClearKey_clicked();

    void on_radioButton24Key_clicked();

    void on_radioButton32Key_clicked();

    void on_radioButton16Key_clicked();

    void on_pushButtonClearInput_clicked();

    void on_pushButtonClearOutput_clicked();

    void on_pushButtonEncryption_clicked();

    void on_pushButtonDecryption_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
