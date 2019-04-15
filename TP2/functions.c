#include "prototype.h"

float **somatorioMatriz(int **arr, float **mask, int sizeM, int size_mask, int size_res) {
    int i, j, l, k;
    float **arr_res = (float**) malloc(size_res*sizeof(float*));
    for(i=0; i < size_res; i++)
        arr_res[i] = (float*) malloc(size_res*sizeof(float));
    for(i=0; i < size_res; i++)
        for(j=0; j < size_res; j++)
            for(l=0; l < size_mask; l++)
                for(k=0; k < size_mask; k++)
                    arr_res[j][i] += (float)(arr[l+j][k+i] * mask[l][k]);
    return arr_res;
}

int achaMaiorMatrizPorMascara_Iterativo(int **arr, int sizeM) {
    int i, j, iter, size_mask = sizeM, size_res = 1;
    for(iter=0; iter < sizeM - 1; iter++){
        float **mask = (float**) malloc(size_mask*sizeof(float*));
        float **res_arr = (float**) malloc(size_res*sizeof(float*));
        for(i=0; i < size_res; i++)
            res_arr[i] = (float*) malloc(size_res*sizeof(float));
        for(i=0; i < size_mask; i++)
            mask[i] = (float*) malloc(size_mask*sizeof(float));
        for(i=0; i < size_mask; i++)
            for(j=0; j < size_mask; j++)
                mask[i][j] = (float)1/(size_mask*size_mask); //Grau de ativação para cada elemento da mascara
        res_arr = somatorioMatriz(arr, mask, sizeM, size_mask, size_res);
        //printaMatrizFloat(res_arr, size_res, sizeM);
        liberaMatrizFloat(res_arr, size_res);
        liberaMatrizFloat(mask, size_mask);
        size_res++;
        size_mask--;
    }
}

void printaMaiorMatriz(float **res_arr, int sizeM, int size_mask) {
    int i, j;
    for(i=0; i < sizeM; i++){
        for(j=0; j < sizeM; j++){
            
        }
    }
}

int achaMaiorMatrizPorMascara_Recursivo(int **arr, int sizeM, int size_mask) {
    int i, j;
    int size_res = sizeM - size_mask + 1;
    if(size_mask <= 1)
        return 1;
    float **mask = (float**) malloc(size_mask*sizeof(float*));
    float **res_arr = (float**) malloc(size_res*sizeof(float*));
    for(i=0; i < size_res; i++)
        res_arr[i] = (float*) malloc(size_res*sizeof(float));
    for(i=0; i < size_mask; i++)
        mask[i] = (float*) malloc(size_mask*sizeof(float));
    for(i=0; i < size_mask; i++)
        for(j=0; j < size_mask; j++)
            mask[i][j] = (float)1/(size_mask*size_mask); //Grau de ativação para cada elemento da mascara
    res_arr = somatorioMatriz(arr, mask, sizeM, size_mask, size_res);
    //printaMatrizFloat(res_arr, size_res, sizeM);
    liberaMatrizFloat(res_arr, size_res);
    liberaMatrizFloat(mask, size_mask);
    achaMaiorMatrizPorMascara_Recursivo(arr, sizeM, size_mask - 1);
}

void SystemUsage() {
    struct rusage resources;
    struct timeval tv;
    char buffer[30];
    time_t curtime;
    gettimeofday(&tv, NULL);
    int rc;
    double utime, stime, total_time;
    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
        perror("getrusage failed");
    curtime = tv.tv_sec;
    strftime(buffer,30,"%d-%m-%Y  %T.",localtime(&curtime));
    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    total_time = utime+stime;
    printf("\nUser time %.3f, System time %.3f, Total Time %.3f\n\r ", utime, stime, total_time);
    printf("%s%ld\n", buffer, tv.tv_usec);
}
