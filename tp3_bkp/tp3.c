#include "grafo.h"

void menu(char *entrada, char *saida, char *tipo) {
    int cor;
    Grafo_Matriz *gr = leArquivo_Entrada(entrada);
    switch (atoi(tipo)) {
        case 1:
            printf("\nImplementação backtracking:\n");
            //cor = backtrack_kColoracao(gr);
            cor = solucaoBT(gr);
            printf("k-Coloração: %d\n", cor);
            break;
        case 2:
            printf("\nImplementação Welsh-Powell\n");
            cor = coloreGrafo_Heuristica(gr);
            printf("k-Coloração: %d\n", cor);
            break;
        case 3:
            printf("\nImplementação Dutton e Brigham\n");
            cor = coloreGrafo_Heuristica2(gr);
            printf("k-Coloração: %d\n", cor);
            break;
        default:
            printf("Tipo de Implementação inválido\n");
            return;
    }
    escreveArquivo_Saida(cor, saida);
    SystemUsage();
    //printf("%d\n", FB_2(gr));
    //printa_MatrizAdj(gr);
}

int main(int argc, char **argv) {
    if(argc < 4){
        printf("Falta argumentos na execução!\n");
        return 0;
    }
    int opt;
    char *entrada = NULL, *saida = NULL, *tipo = NULL;
    while((opt = getopt(argc, argv, "i:o:t:")) != -1){
        switch(opt){
            case 'i':
                entrada = optarg;
                break;
            case 'o':
                saida = optarg;
                break;
            case 't':
                tipo = optarg;
                break;
            default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: %c\n", optopt);
                return -1;
        }
    }
    menu(entrada, saida, tipo);
    return 0;
}
