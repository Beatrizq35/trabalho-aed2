#ifndef EX1_H
#define EX1_H
#include <time.h> // Necessário para a struct timespec

/* ---------------------------------------------------------
   Funções de Criacao de Vetor
   --------------------------------------------------------- */

// Cria vetor Desordenado
void criaVetDesordenado(int vet[], int tam);

// Cria vetor Ordenado
void criaVetOrdenado(int vet[], int tam);

/* ---------------------------------------------------------
   Funções de Busca
   --------------------------------------------------------- */

// Retorna o índice do elemento ou -1 se não encontrado
int buscaSequencial(int vet[], int key);

// Retorna o índice do elemento ou -1 se não encontrado (Vetor deve estar ordenado)
int buscaBinaria(int vet[], int key);

/* ---------------------------------------------------------
   Funções de Utilidade e Tempo
   --------------------------------------------------------- */

// Calcula a diferença de tempo entre início e fim em segundos (double)
double calculaTempo(struct timespec inicio, struct timespec fim);

/* ---------------------------------------------------------
   Funções de Estatística
   --------------------------------------------------------- */

// Calcula a média
double calculaMedia(double tempos[], int n);

// Calcular o desvio padrão
double desvioPadrao(double tempos[], int n);
#endif