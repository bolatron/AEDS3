#include "prototype.h"

/* Gera uma matriz de inteiros 0 e 1, com base na seed dada */
int **geraMatrizAleatoria(int size, int seed) {
    srand(seed);
    int i, j;
    int **arr = (int**) malloc(size*sizeof(int*));
    for(i=0; i < size; i++)
        arr[i] = (int*) malloc(size*sizeof(int));
    for(i=0; i < size; i++)
        for(j=0; j < size; j++)
            arr[i][j] = rand()%2;
    return arr;
}

/* Função auxiliar da "geraMatrizAleatoria()", printa os elementos da matriz */
void printaMatrizInt(int **arr, int size) {
    int i, j;
    printf("Matriz gerada: \n");
    for(i=0; i < size; i++){
        for(j=0; j < size; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void printaMatrizFloat(float **arr, int size, int sizeM){
    int i, j;
    printf("ativação em Mascara %d x %d:\n", (sizeM+1)-size, (sizeM+1)-size);
    for(i=0; i < size; i++){
        printf("[ ");
        for(j=0; j < size; j++)
            printf("%f ", arr[i][j]);
        printf("]\n");
    }
    printf("\n");
}

void liberaMatrizInt(int **arr, int size) {
    int i;
    for(i=0; i < size; i++)
        free(arr[i]);
    free(arr);
}

void liberaMatrizFloat(float **arr, int size) {
    int i;
    for(i=0; i < size; i++)
        free(arr[i]);
    free(arr);
}
