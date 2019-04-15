#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>

int **geraMatrizAleatoria(int size, int seed);
void printaMatrizInt(int **arr, int size);
void printaMatrizFloat(float **arr, int size, int sizeM);
void liberaMatrizInt(int **arr, int size);
void liberaMatrizFloat(float **arr, int size);
int achaMaiorMatrizPorMascara_Recursivo(int **arr, int sizeM, int size_mask);
int achaMaiorMatrizPorMascara_Iterativo(int **arr, int sizeM);
void SystemUsage();
#endif
