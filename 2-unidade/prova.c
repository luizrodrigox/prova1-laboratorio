#include <stdio.h>

typedef struct contato{
    char nome[50];
    char telefone[20];
    char email[50];
    struct contato *proximo;
} contato;

int hash(char *chave){
    int valorhash = 0;
    for(int i = 0; chave[i] != '\0'; i++){
        valorhash = valorhash + chave[i];
    }
    return valorhash % 100;
}

int main(){
    contato *tabelahash[100] = {NULL};
    int opcao;

    while (opcao != 0){
        printf("\n1- Inserir\n2- Remover, 3- Buscar\n 0- Sair");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            InserirContato();
            break;
        case 2:
            RemoverContato();
            break;
        case 3:
            BuscarContato();
            break;
        default:
            break;
        }
    }
    
    return 0;
}