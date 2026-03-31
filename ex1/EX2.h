/*
Aproveitando o vetor da questão anterior utilizado na busca sequencial, crie uma lista
encadeada com os mesmos valores. Execute a busca sequencial 30 vezes no vetor e 30
vezes na lista encadeada, usando os mesmos valores para a busca em cada execução nas
duas estruturas de dados. Registre os tempos de execução de cada busca, calcule e exiba
a média dos tempos de execução para cada estrutura. Use o mesmo mecanismo da questão
anterior para garantir que pelo menos 15 valores sejam encontrados nas estruturas de
dados.
*/
#ifndef EX2_H
#define EX2_H
 
#include <time.h> // Necessário para struct timespec
 
/* ---------------------------------------------------------
   TAD: Nó da Lista Encadeada
   --------------------------------------------------------- */
typedef struct No {
    int dado;
    struct No *proximo;
} No;
 
/* ---------------------------------------------------------
   TAD: Lista Encadeada
   --------------------------------------------------------- */
typedef struct {
    No *cabeca;
    int tamanho;
} Lista;
 
/* ---------------------------------------------------------
   Funções de Manipulação da Lista
   --------------------------------------------------------- */
 
// Inicializa a lista (deve ser chamada antes de usar)
void inicializaLista(Lista *l);
 
// Insere um valor no final da lista
void insereNaLista(Lista *l, int valor);
 
// Constrói a lista encadeada a partir de um vetor
void criaListaDoVetor(Lista *l, int vet[], int tam);
 
// Libera toda a memória alocada pela lista
void liberaLista(Lista *l);
 
/* ---------------------------------------------------------
   Função de Busca
   --------------------------------------------------------- */
 
// Busca sequencial na lista encadeada
// Retorna 1 se encontrado, 0 se não encontrado
int buscaSequencialLista(Lista *l, int key);
 
#endif
