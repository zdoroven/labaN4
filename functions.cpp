#include "functions.h"
#include "mainwindow.h"

//Функция возвращающая номер позиции ячейки (i,j)
int countNumber(int i, int j)
{
    int number = 0;
    for(int ii = 0; ii < 7; ii++){
        for(int jj = 0; jj < 7; jj++){
            number++;
            if(ii == i && jj == j) return number;
        }
    }
    return -1;
}

//Функция возвращающая случайное число от low до high
int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

int checkIfExist(int x, int y, vect mass[100], int z){
    for(int f = 0; f < z; f++){
        if ((mass[f].x == x && mass[f].y == y) || ((mass[f].x == y && mass[f].y == x))){
            return 1;
        }
    }
    return 0;
}
