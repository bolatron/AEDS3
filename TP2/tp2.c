#include "prototype.h"

int main(int argc, char **argv) {
    int size = atoi(argv[1]);
    int seed = atoi(argv[2]);
    int **arr = geraMatrizAleatoria(size, seed);
    //printaMatrizInt(arr, size);
    //achaMaiorMatrizPorMascara_Recursivo(arr, size, size);
    //SystemUsage();
    achaMaiorMatrizPorMascara_Iterativo(arr, size);
    SystemUsage();
    liberaMatrizInt(arr, size);
    return 0;
}
