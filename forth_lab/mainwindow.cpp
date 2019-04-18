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
    int i, j, k, newi, newj, x, y, z, num;
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
    num = 0;
    for(z = 0; z < 10000; z++){
        k = randomBetween(1,4);
        //1 - шаг вверх
        //2 - шаг вправо
        //3 - шаг вниз
        //4 - шаг влево
        newi = i;
        newj = j;
        if(k == 1){
            if(j != 0)newj = j - 1;
        }
        if(k == 2){
            if(i != 6)newi = i + 1;
        }
        if(k == 3){
            if(j != 6)newj = j + 1;
        }
        if(k == 4){
            if(i != 0)newi = i - 1;
        }
        x = countNumber(i, j);
        y = countNumber(newi, newj);
        if (checkIfExist(x, y ,mass, num) == 0){
            if (field[newi][newj] == 0){
                field[newi][newj] = 1;
                i = newi;
                j = newj;
                if(x > 0 && x < 50 && y > 0 && y < 50 && x != y){
                    mass[num].x = x;
                    mass[num].y = y;
                    num++;
                }
            }
        } else {
            i = newi;
            j = newj;
        }
    }
    ui->textEdit->append(QString("Сторона поля = 7   Кол-во перегородок = %1\n").arg(num));
    for(z = 0; z < 100; z++){
        if(mass[z].x != 0 && mass[z].y != 0 && mass[z].x < 50 && mass[z].y < 50)
            ui->textEdit->append(QString("%1  %2\n").arg(mass[z].x).arg(mass[z].y));
    }
    for(i = 0; i < 7; i++){
        ui->textEdit->append(QString("%1 %2 %3 %4 %5 %6 %7").arg(field[i][0]).arg(field[i][1]).arg(field[i][2]).arg(field[i][3]).arg(field[i][4]).arg(field[i][5]).arg(field[i][6]));
        }
}
