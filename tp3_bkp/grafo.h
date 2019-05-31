#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>

typedef struct _Arestas{
    int aresta, id, cor; // 0 sem cor
} arestas;

typedef struct _Grafo_Matriz{
    int **mapa;
    arestas *arestas;
    int num_vertices;
    char ponderado, direcionado;  // 'S' = 83 'N' = 78
}Grafo_Matriz;

//  --- LEITURA DOS ARQUIVOS I/O ---
Grafo_Matriz *leArquivo_Entrada(char *entrada);
void escreveArquivo_Saida(int coloracao, char *saida);
//  --- MANIPULAÇÃO DO GRAFO ---
Grafo_Matriz *criaGrafo_MatrizAdj(int vertices, int ponderado, int direcionado);
int insereAresta_MatrizAdj(Grafo_Matriz *gr, int v1, int v2);
//  --- ALGORITMOS COLORAÇÃO DE GRAFOS ---
int solucaoBT(Grafo_Matriz *gr);
int backtrack_kColoracao(Grafo_Matriz *gr);
int coloreGrafo_Heuristica(Grafo_Matriz *gr);
int coloreGrafo_Heuristica2(Grafo_Matriz *gr);
int FB_2(Grafo_Matriz *gr);
//  --- FUNÇÕES AUXILIARES ---
void SystemUsage();
void printa_MatrizAdj(Grafo_Matriz *gr);
arestas *sort(Grafo_Matriz *gr);
void quickSort(arestas *array, int start, int end);

#endif
