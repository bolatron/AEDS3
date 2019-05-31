#include "prototipo.h"

Grafo_Matriz *criaGrafo_MatrizAdj(int vertices, int ponderado, int direcionado) {
    int i, j;
    Grafo_Matriz *gr = (Grafo_Matriz*) malloc(sizeof(Grafo_Matriz));
    gr->ponderado = (char)ponderado;
    gr->direcionado = (char)direcionado;
    gr->num_vertices = vertices;
    gr->mapa = (int**) malloc(vertices*sizeof(int*));
    for(i=0; i < vertices; i++){
        gr->mapa[i] = (int*) malloc(vertices*sizeof(int));
        for(j=0; j < vertices; j++)
            gr->mapa[i][j] = 0;
    }
    gr->arestas = (arestas*) malloc(vertices*sizeof(arestas));
    return gr;
}

int insereAresta_MatrizAdj(Grafo_Matriz *gr, int v1, int v2) {
    if(gr->mapa[v1][v2] > 0 || v1 == v2)
        return 0;
    gr->mapa[v1][v2] = 1;
    gr->mapa[v2][v1] = 1;
    gr->arestas[v1].id = v1;
    gr->arestas[v1].aresta++;
    gr->arestas[v1].cor = 0;
    gr->arestas[v2].id = v2;
    gr->arestas[v2].aresta++;
    gr->arestas[v2].cor = 0;
    return 1;
}

int **removeVertice_MatrizAdj(int **mapa, int num_vertices, int v1) {
    int i, j, aux_i = 0, aux_j = 0;
    int **novo_mapa = (int**) malloc(num_vertices*sizeof(int*));
    for(i=0; i < num_vertices; i++)
        novo_mapa[i] = (int*) malloc(num_vertices*sizeof(int));
    for(i=0; i < num_vertices+1; i++){
        for(j=0; j < num_vertices+1; j++){
            if(v1==i)aux_i = 1;
            if(v1==j)aux_j = 1;
            if(i != v1 && j != v1){
                novo_mapa[i-aux_i][j-aux_j] = mapa[i][j];
            }
        }
        aux_j = 0;
    }
    return novo_mapa;
}

int isSafe(int v, Grafo_Matriz *gr, int *color, int i) {
    int j;
    for(j=0; j < gr->num_vertices; j++)
        if(gr->mapa[v][j] && i == color[j])
            return 0;
    return 1;
}


int graphColoringUtil(Grafo_Matriz *gr, int m, int *color, int v){
    int i;
    if(v == gr->num_vertices)
        return 1;
    for(i=1; i <= m; i++){
        if(isSafe(v, gr, color, i)){
            color[v] = i;
            if (graphColoringUtil(gr, m, color, v+1) == 1)
            return 1;
            color[v] = 0;
        }
    }
    return 0;
}


int coloreGrafo(Grafo_Matriz *gr, int m) {
    int i;
    int *color = (int*) malloc(gr->num_vertices*sizeof(int));
    for(i=0; i < gr->num_vertices; i++)
        color[i] = 0;
    if(graphColoringUtil(gr, m, color, 0) == 0)
        return 1;
    return 0;
}

/* Solução por meio de backtracking, retirada da página
    https://www.geeksforgeeks.org/graph-coloring-applications/ */
int solucaoBT(Grafo_Matriz *gr) {
    int i;
    for(i=1; coloreGrafo(gr, i); i++);
    return i;
}

int check_color(Grafo_Matriz *gr) {
    int i, flag = 0;
    for(i=0; i < gr->num_vertices; i++)
        if(gr->arestas[i].cor == 0)
            flag = 1;
    return flag;
}

/* Solução pela Heuristica Welsh Powell */
int coloreGrafo_Heuristica(Grafo_Matriz *gr) {
    int i, j, cor = 1;
    arestas *arr = sort(gr);
    for(i=0; check_color(gr); i++){
        gr->arestas[arr[i].id].cor = cor;
        for(j=0; j < gr->num_vertices; j++){
            if(gr->mapa[gr->arestas[arr[i].id].id][j] == 0 && gr->arestas[arr[i].id].id != j)
                if(gr->arestas[j].cor == 0)
                    gr->arestas[j].cor = cor;
        }
        cor++;
    }
    return cor - 1;
}

int mapaVazio(int **mapa, int num_vertices) {
    int i, j, flag = 1;
    for(i=0; i < num_vertices; i++)
        for(j=0; j < num_vertices; j++)
            if(mapa[i][j] == 1 && i != j)
                flag = 0;
    return flag;
}

int verificaClique(int **mapa, int num_vertices) {
    int i, j, flag = 0;
    for(i=0; i < num_vertices; i++)
        for(j=0; j < num_vertices; j++)
            if(mapa[i][j] == 0 && i != j)
                flag = 1;
    return flag;
}

int zykovCondensa(int **mapa, int vertice_atual, int num_vertices) {
    int i, **novo_mapa;
    if(mapaVazio(mapa, num_vertices))
        return 1;
    if(verificaClique(mapa, num_vertices)){
        for(i=0; i < num_vertices; i++){
            if(mapa[vertice_atual][i] == 0 && vertice_atual != i){
                novo_mapa = removeVertice_MatrizAdj(mapa, num_vertices-1, i);
            }
        }
    }else
        return num_vertices;
    return zykovCondensa(novo_mapa, vertice_atual+1, num_vertices-1);
}

/* Solução desenvolvida pela Heuristica Dutton e Brigham */
int coloreGrafo_Heuristica2(Grafo_Matriz *gr) {
    int k_coloracao;
    k_coloracao = zykovCondensa(gr->mapa, 0, gr->num_vertices);
    return k_coloracao;
}

void printa_MatrizAdj(Grafo_Matriz *gr) {
    int i, j;
    printf("Número de arestas por vertice:\n");
    for(i=0; i < gr->num_vertices; i++)
        printf("%d ", gr->arestas[i].id);
    printf("\nMatriz de Adjacência:\n");
    for(i=0; i < gr->num_vertices; i++){
        for(j=0; j < gr->num_vertices; j++)
            printf("%d ", gr->mapa[i][j]);
        printf("\n");
    }
}
