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
int checkIfExist(int x, int y, vect mass[100], int z);
#endif // FUNCTIONS_H
