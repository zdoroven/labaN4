#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "functions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_clicked()
{
    ui->textEdit->clear();
    int field [7][7];
    vect mass  [100];
    int i, j, k, newi, newj, x, y, z;
    //Обнуление массива поля
    for (i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            field[i][j] = 0;
        }
    }
    field[0][0] = 1;
    i = 0;
    j = 0;
    newi = 0;
    newj = 0;
    for(z = 0; z < 100; z++){
        k = randomBetween(1,4);
        //1 - шаг вверх
        //2 - шаг вправо
        //3 - шаг вниз
        //4 - шаг влево
        if(k == 1){
            if(j != 0)
                newj = j - 1;
        }
        if(k == 2){
            if(i != 6) newi = i + 1;
        }
        if(k == 3){
            if(j != 6) newj = j + 1;
        }
        if(k == 4){
            if(i != 0) newi = i - 1;
        }
        field[newi][newj] = 1;
        x = countNumber(i, j);
        y = countNumber(newi, newj);
        i = newi;
        j = newj;
        if(x != -1 && y != -1 && x != y){
            mass[z].x = x;
            mass[z].y = y;
        } else mass[z].x = 0;
    }
    z = massSort(mass);
    ui->textEdit->append(QString("Сторона поля = 7   Кол-во перегородок = %1\n").arg(z));
    for(z = 0; z < 50; z++){
        if(mass[z].x != 0)
        ui->textEdit->append(QString("%1  %2\n").arg(mass[z].x).arg(mass[z].y));
    }
    for(j = 0; j < 7; j++){
        ui->textEdit->append(QString("%1 %2 %3 %4 %5 %6 %7").arg(field[0][j]).arg(field[1][j]).arg(field[2][j]).arg(field[3][j]).arg(field[4][j]).arg(field[5][j]).arg(field[6][j]));
    }
}
