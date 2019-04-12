#include "functions.h"
#include "mainwindow.h"

//Функция сортирует массив векторов убирая из него (x,y), если в массиве есть (y,x) и повторы
int massSort(vect mass[100]){
    int d, i = 0;
    for(int z = 0; z <= 50; z++){
        for(d = z - 1; d >= 0; d--){
            if((mass[z].x == mass[d].y) && (mass[z].y == mass[d].x))
                mass[z].x = 0;
            if((mass[z].x == mass[d].x) && (mass[z].y == mass[d].y))
                mass[z].x = 0;
        }
        if(mass[z].x != 0) i++;
    }
    return i;
}

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

void runLeftStuff(vect mass[100], int field[7][7]){

}
