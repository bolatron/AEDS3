#include "prototipo.h"

arestas *sort(Grafo_Matriz *gr) {
    int i, j;
    arestas aux;
    arestas *array = (arestas*) malloc(gr->num_vertices*sizeof(arestas));
    for(i=0; i < gr->num_vertices; i++)
        array[i] = gr->arestas[i];
    for(i=0; i < gr->num_vertices; i++){
        for(j=gr->num_vertices-1; j > i; j--){
            if(array[j].aresta > array[i].aresta){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
    return array;
}

int quickMerge(arestas *array, int start, int end) {
    int left, right;
    arestas aux, pivo;
    right = end;
    left = start;
    pivo = array[start];
    while(left < right){
        while(array[left].aresta <= pivo.aresta && left<end)
            left++;
        while(array[right].aresta > pivo.aresta)
            right--;
        if(right < start || left > end)
            printf("Error!\n");
        if(left < right){
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }
    array[start] = array[right];
    array[right] = pivo;
    return right;
}

void quickSort(arestas *array, int start, int end) {
    if(start < end){
        int pivo = quickMerge(array, start, end);
        quickSort(array, start, pivo-1);
        quickSort(array, pivo+1, end);
    }
}
