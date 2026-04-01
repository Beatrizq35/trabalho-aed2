/*
Aproveitando o vetor da questão anterior utilizado na busca sequencial, crie uma lista
encadeada com os mesmos valores. Execute a busca sequencial 30 vezes no vetor e 30
vezes na lista encadeada, usando os mesmos valores para a busca em cada execução nas
duas estruturas de dados. Registre os tempos de execução de cada busca, calcule e exiba
a média dos tempos de execução para cada estrutura. Use o mesmo mecanismo da questão
anterior para garantir que pelo menos 15 valores sejam encontrados nas estruturas de
dados.
*/
#include <stdio.h>
#include <stdlib.h>
#include "EX2.h"
 
/* ---------------------------------------------------------
   Inicializa a lista: cabeça aponta para NULL, tamanho = 0
   --------------------------------------------------------- */
void inicializaLista(Lista *l) {
    l->cabeca = NULL;
    l->tamanho = 0;
}
 
/* ---------------------------------------------------------
   Insere um valor no FINAL da lista encadeada
   --------------------------------------------------------- */
void insereNaLista(Lista *l, int valor) {
    // Aloca memória para o novo nó
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória para nó!\n");
        exit(1);
    }
 
    novo->dado = valor;
    novo->proximo = NULL;
 
    // Se a lista estiver vazia, o novo nó é a cabeça
    if (l->cabeca == NULL) {
        l->cabeca = novo;
    } else {
        // Percorre até o último nó e encadeia
        No *atual = l->cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
 
    l->tamanho++;
}
 
/* ---------------------------------------------------------
   Constrói a lista encadeada com os mesmos valores do vetor
   --------------------------------------------------------- */
void criaListaDoVetor(Lista *l, int vet[], int tam) {
    inicializaLista(l);
    printf("Criando lista encadeada com %d elementos... Aguarde.\n", tam);
    for (int i = 0; i < tam; i++) {
        insereNaLista(l, vet[i]);
    }
    printf("Lista encadeada criada com sucesso!\n");
}
 
/* ---------------------------------------------------------
   Libera toda a memória alocada pela lista
   --------------------------------------------------------- */
void liberaLista(Lista *l) {
    No *atual = l->cabeca;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    l->cabeca = NULL;
    l->tamanho = 0;
}
 
/* ---------------------------------------------------------
   Busca Sequencial na Lista Encadeada
   Percorre nó a nó comparando o dado com a chave
   Retorna 1 se encontrado, 0 se não encontrado
   --------------------------------------------------------- */
int buscaSequencialLista(Lista *l, int key) {
    No *atual = l->cabeca;
    while (atual != NULL) {
        if (atual->dado == key) {
            return 1; // Encontrado
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}
