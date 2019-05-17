void printaMaiorMatrizMascara(int **arr, float **res_arr, int size_res, int size_mask) {
    int i, j, k, l, sizeT = size_res + size_mask - 1;
    for(i=0; i < sizeT; i++)
        for(j=0; j < sizeT; j++)
            arr[i][j] = 0;
    //printaMatrizfloat(res_arr, size_res, sizeT);
    for(i=0; i < size_res; i++){
        for(j=0; j < size_res; j++){
            if(res_arr[i][j] == 1.00){
                for(k=0; k < size_mask; k++)
                    for(l=0; l < size_mask; l++)
                        arr[i+k][j+l] = 1;
            }
        }
    }
}

void printaMaiorMatrizGuloso(int **arr, int size, GulosoData data){
    int i, j, l, k;
    for(i=0; i < size; i++)
        for(j=0; j < size; j++)
            arr[i][j] = 0;
    for(i=0; i < size; i++){
        for(j=0; j < size; j++){
            if(data.pos_i == i && data.pos_j == j){
                for(k=0; k < data.altura_max; k++)
                    for(l=0; l < data.altura_max; l++)
                        arr[i+k][j+l] = 1;
            }
        }
    }
}

void printaMaiorMatrizDinamico(int **arr, int size, int **arr_res, int max_submatrix) {
    int i, j, l, k;
    for(i=0; i < size; i++)
        for(j=0; j < size; j++)
            arr[i][j] = 0;
        for(i=0; i < size + 1; i++){
            for(j=0; j < size + 1; j++){
                if(arr_res[i][j] == max_submatrix){
                    for(k=max_submatrix; k > 0; k--)
                        for(l=max_submatrix; l > 0; l--)
                            arr[i-k][j-l] = 1;
                }
            }
        }
}
