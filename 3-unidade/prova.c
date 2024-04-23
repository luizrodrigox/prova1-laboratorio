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

void grafoDirecionado(int linha, int coluna, int **matriz){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if (matriz[i][j] != matriz[j][i]){
                printf("O grafo e direcionado\n");
            }
        }
    }
    printf("O grafo nao e direcionado\n");
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
    printf("vertice com maior grau: %d - %d\n", indice, maiorgrau);

    FILE *arquivograus = fopen("dados_grafos_graus.txt", "w");

    for (int i = 0; i < linha; i++){
        fprintf(arquivograus, "Vertice %d: %d\n", i, aux[i]);
    }
    fclose(arquivograus);
}

void verticeIsolado(int linha, int coluna, int **matriz){
    int aux1[linha];
    int aux2[coluna];
    for (int i = 0; i < linha; i++){
        aux1[i] = 0;
        aux2[i] = 0;
        for (int j = 0; j < coluna; j++){
            aux1[i] += matriz[i][j];
            aux2[i] += matriz[j][i];
        }
        if (aux1[i] == 0 && aux2[i] == 0){
                printf("vertice %d - isolado\n", i);
            }
    }
    printf("nao tem vertice isolado\n");
}

void verticeSumidouro(int linha, int coluna, int **matriz){
    int aux[linha];
    for (int i = 0; i < linha; i++){
        aux[i] = 0;
        for (int j = 0; j < coluna; j++){
            aux[i] += matriz[i][j];
        }
        if(aux[i] == 0){
            printf("vertice %d - sumidouro\n", i);
        }
    }
    printf("nao tem vertice sumidouro\n");
}

void verticeFonte(int linha, int coluna, int **matriz){
    int aux[coluna];
    for (int j = 0; j < coluna; j++){
        aux[j] = 0;
        for (int i = 0; i < linha; i++){
            aux[j] += matriz[i][j];
        }
        if(aux[j] == 0){
            printf("vertice %d - fonte\n", j);
        }
    }
    printf("nao tem vertice fonte\n");
}

void grafoComplemetar(int linha, int coluna, int **matriz){
    FILE *arquivo = fopen("dados_grafo_complementar.txt", "w");

    fprintf(arquivo, "%d %d\n", linha, coluna);

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if (i == j){
                fprintf(arquivo, "%d ", 0);
            }
            if (matriz[i][j] == 0){
                fprintf(arquivo, "%d ", 1);
            }else{
                fprintf(arquivo, "%d ", 0);
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

void primeiroEultimo(int coluna, int **matriz){
    int i = 0;
    int j = coluna;
    if(matriz[i][j] == 0){
        printf("O primeiro e o ultimo, nao estao conectados\n");
    } else{
        printf("O primeiro e o ultimo estao conectados\n");
    }
}

void multiplosde5(int linha, int coluna, int **matriz){
    FILE *arquivo = fopen("dados_grafo_gerador.txt", "w");

    int cont = 0;
    for (int i = 0; i < linha; i += 5){
        cont++;
    }
    fprintf(arquivo, "%d %d\n", cont, cont);
    
    for (int i = 0; i <= linha; i += 5){
        for (int j = 0; j <= coluna; j += 5){
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
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
    
    //imprimeMatriz(linha, coluna, matriz);
    //grafoDirecionado(linha, coluna, matriz);
    //grafoGraus(linha, coluna, matriz);
    //verticeIsolado(linha, coluna, matriz);
    //verticeSumidouro(linha, coluna, matriz);
    //verticeFonte(linha, coluna, matriz);
    grafoComplemetar(linha, coluna, matriz);
    //primeiroEultimo(coluna, matriz);
    //multiplosde5(linha, coluna, matriz);

    for (int i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}