#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};


void inserirNoInicio(struct No** inicio, int valor) {
    /* Aloca memória para o novo nó */
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    /* Verifica se a alocação falhou (retornou NULL).
       Se falhar, imprime mensagem de erro e retorna sem modificar a lista.
       Não tentamos acessar 'novo' se for NULL para evitar comportamento indefinido. */
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória ao inserir no início da lista.\n");
        return;
    }

    /* Inicializa campos do novo nó e o insere no início */
    novo->dado = valor;
    novo->proximo = *inicio;
    *inicio = novo;
} 

void removerDoInicio(struct No** inicio) {
    if (*inicio != NULL) {
        struct No* temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
    }
} 

int main() {
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado = 30;
    terceiro->proximo = NULL;

    // Percorrendo a lista
    struct No* atual = primeiro;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    return 0;
} 