#include "prototipo.h"

Grafo_Matriz *leArquivo_Entrada(char *entrada) {
    FILE *arq = fopen(entrada, "r");
    char c;
    int num_vertices, v1, v2, iter = 0, i;
    fscanf(arq, "%d", &num_vertices);
    Grafo_Matriz *gr = criaGrafo_MatrizAdj(num_vertices, 78, 78);
    while((fscanf(arq, "%d %d", &v1, &v2)) != EOF)
        insereAresta_MatrizAdj(gr, v1, v2);
    fclose(arq);
    return gr;
}

void escreveArquivo_Saida(int coloracao, char *saida) {
    FILE *arq = fopen(saida, "w");
    fprintf(arq, "%d\n", coloracao);
    fclose(arq);
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
