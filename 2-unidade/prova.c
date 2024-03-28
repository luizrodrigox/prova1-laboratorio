#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_HASH 5003

typedef struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
    struct Contato *prox;
} Contato;

typedef struct {
    Contato *tabela[CAPACIDADE_HASH];
} ListaContatos;

int calcular_hash(char *chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % CAPACIDADE_HASH;
}

void inicializar_lista(ListaContatos *lista) {
    for (int i = 0; i < CAPACIDADE_HASH; i++) {
        lista->tabela[i] = NULL;
    }
}

void inserir_contato(ListaContatos *lista, char *nome, char *telefone, char *email) {
    int hash = calcular_hash(nome);

    Contato *novo_contato = (Contato *)malloc(sizeof(Contato));
    if (novo_contato == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->telefone, telefone);
    strcpy(novo_contato->email, email);
    novo_contato->prox = NULL;

    novo_contato->prox = lista->tabela[hash];
    lista->tabela[hash] = novo_contato;
}

void remover_contato(ListaContatos *lista, char *nome) {
    int hash = calcular_hash(nome);
    Contato *atual = lista->tabela[hash];
    Contato *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL){
            lista->tabela[hash] = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        printf("Contato removido com sucesso.\n");
    } else {
        printf("Contato não encontrado.\n");
    }
}

void buscar_contato(ListaContatos *lista, char *nome) {
    int hash = calcular_hash(nome);
    Contato *atual = lista->tabela[hash];

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual != NULL) {
        printf("Contato encontrado: %s - %s\n", atual->nome, atual->telefone);
    } else {
        printf("Contato não encontrado.\n");
    }
}

void imprimir_contatos(ListaContatos *lista) {
    printf("Lista de contatos:\n");
    for (int i = 0; i < CAPACIDADE_HASH; i++) {
        Contato *atual = lista->tabela[i];
        while (atual != NULL) {
            printf("%s: %s\n", atual->nome, atual->telefone);
            atual = atual->prox;
        }
    }
}

void ler_contatos_arquivo(ListaContatos *lista) {
    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char nome[50];
    char telefone[20];
    char email[50];

    while (fscanf(arquivo, "%s\n %s\n %s\n", nome, telefone, email) != EOF) {
        inserir_contato(lista, nome, telefone, email);
    }

    fclose(arquivo);
}

int main() {
    ListaContatos lista;
    inicializar_lista(&lista);
    ler_contatos_arquivo(&lista);
    imprimir_contatos(&lista);

    int opcao;
    char nome[50], telefone[20], email[50];
    do {
        printf("\nOpções:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do contato: ");
                scanf("%s", nome);
                printf("Digite o telefone do contato: ");
                scanf("%s", telefone);
                printf("Digite o email do contato: ");
                scanf("%s", email);
                inserir_contato(&lista, nome, telefone, email);
                break;
            case 2:
                printf("Digite o nome do contato a ser removido: ");
                scanf("%s", nome);
                remover_contato(&lista, nome);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf("%s", nome);
                buscar_contato(&lista, nome);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}