#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "mainwindow.h"
#include <QMainWindow>

struct vect
{
    int x;
    int y;
};

int randomBetween(int low, int high);
int countNumber(int i, int j);
int massSort(vect mass[100]);
void runLeftStuff(vect mass[100], int field[7][7]);

#endif // FUNCTIONS_H
