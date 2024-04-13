#include <stdio.h>
#include <stdlib.h>

#define maxlinha 4000
#define maxcoluna 4000

void imprimeMatriz(int linha, int coluna, int **matriz){
     for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void grafoGraus(int linha, int coluna, int **matriz){
    int indice = 0, maiorgrau = 0;
    int aux[linha];
    for (int i = 0; i < linha; i++){
        aux[i] = 0;
        for (int j = 0; j < coluna; j++){
            aux[i] += matriz[i][j];
        }
        if (maiorgrau < aux[i]){
            maiorgrau = aux[i];
            indice = i;
            }
    }
    printf("vertice com maior grau: %d - %d", indice, maiorgrau);
    FILE *arquivograus = fopen("dados_grafos_graus.txt", "w");

    for (int i = 0; i < linha; i++){
        fprintf(arquivograus, "Grau do vertice %d: %d\n", i, aux[i]);
    }
    fclose(arquivograus);
}

int main() {
    int **matriz;
    int linha, coluna;

    FILE *arquivo = fopen("dados_matriz.txt", "r");
    if(arquivo == NULL){
        printf("erro ao abrir arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d %d", &linha, &coluna);

    matriz = (int **)malloc(linha * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        return 1;
    }
    for (int i = 0; i < linha; i++) {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a matriz.\n");
            return 1;
        }
    }

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    fclose(arquivo);
    
    grafoGraus(linha, coluna, matriz);
    //imprimeMatriz(linha, coluna, matriz);

    for (int i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}