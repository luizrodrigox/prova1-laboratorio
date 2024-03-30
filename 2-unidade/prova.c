#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_HASH 5000

typedef struct Contato {
    char nome[100];
    char telefone[100];
    char email[100];
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
        printf("Erro: memoria insuficiente.\n");
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
        printf("Contato nao encontrado.\n");
    }
}

void buscar_contato(ListaContatos *lista, char *nome) {
    int hash = calcular_hash(nome);
    Contato *atual = lista->tabela[hash];

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual != NULL) {
        printf("Contato encontrado: %s\n %s\n %s\n", atual->nome, atual->telefone, atual->email);
    } else {
        printf("Contato nao encontrado.\n");
    }
}

void imprimir_contatos(ListaContatos *lista) {
    printf("Lista de contatos:\n");
    for (int i = 0; i < CAPACIDADE_HASH ;i++) {
        Contato *atual = lista->tabela[i];
        while (atual != NULL) {
            printf("%s\n %s\n %s\n \n", atual->nome, atual->telefone, atual->email);
            atual = atual->prox;
        }
    }
}

int main() {
    ListaContatos lista;
    inicializar_lista(&lista);

    FILE *f = fopen("todosOsContatos.txt", "r");
    char nome[100];
    char tel[100];
    char email[100];

    for (int i = 0; i < 10000; i++) {
        fscanf(f, "Nome: %[A-Z. a-z]\n", nome);
        fscanf(f, "Telefone: %[(0-9) -0-9]\n", tel);
        fscanf(f, "Email: %s\n", email);
        fscanf(f, "\n");
        inserir_contato(&lista, nome, tel, email);
    }
    fclose(f);
   
    int opcao;

    do {
        printf("\nMENU:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do contato: ");
                scanf("%s", nome);
                printf("Digite o telefone do contato: ");
                scanf("%s", tel);
                printf("Digite o email do contato: ");
                scanf("%s", email);
                inserir_contato(&lista, nome, tel, email);
                break;
            case 2:
                printf("Digite o nome do contato a ser removido:\n");
                scanf("%s", nome);
                remover_contato(&lista, nome);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: \n");
                scanf("%s", nome);
                buscar_contato(&lista, nome);
                break;
            case 4:
                printf("Todos os contatos:\n");
                imprimir_contatos(&lista);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
