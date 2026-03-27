/*
Desenvolva um programa que implemente um vetor com 1.000.000 (um milhão) de
elementos do tipo inteiro. Execute a busca sequencial no vetor com valores aleatórios
desordenados e a busca binária no vetor com valores aleatórios ordenados. Execute cada
algoritmo 30 vezes. Em 15 execuções uma posição do vetor deve ser sorteada para usar o
valor correspondente naquela posição para a busca (isso garante que o valor vai ser
encontrado no vetor) e nas outras 15 execuções gere valores aleatórios para a busca
(muitos deles não serão encontrados no vetor). Calcule e mostre o tempo de execução para
cada busca, a média entre as 30 execuções e o desvio padrão dos tempos de execução para
cada algoritmo.

O q fazer:

1. Criar vetor do tipo inteiro Desordenado
2. Criar vetor do tipo inteiro Ordenado
3. Implementar Busca Sequencial
4. Implementar Busca Binária
5. Criar programa de geracao de valores aleatorios
6. Criar programa que calcule o tempo de execucao
7. Criar programa que calcule a media entre as 30 execucoes
8. Criar programa que calcule o desvio padrao
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 1000000
#define EXECUCOES 30

// 1. Criar vetor do tipo inteiro desordenado
void criaVetDesordenado(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % (TAM * 10);
// 1.Criar vetor do tipo inteiro desordonado

int criaVetDesordenado (int vet[], int n, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        vet[i] = rand() % (tam * 10);
    }
}

// 2.Criar vetor do tipo inteiro ordenado(tipos abstrados de dado, apenas a função que cria)
void criaVetOrdenado(int vet[], int tam) {
    int atual = rand() % 10; // rand() : gera um número aleatorio dependendo da maquina de (32 mil a 2 milhões) %10 (divisão por 10 pegar o resto)
    for (int i = 0; i < tam; i++) {
        vet[i] = atual; // colocar o valor pego e acrescentar no vetor[i]
        atual += (rand() % 5) + 1; // (atual = (rand()%5) +1) +  atual
    }
}
// 3.Implementar Busca Sequencial

int buscaSequencial (int vet[], int key) {
    int i;

    for (i = 0; i < TAM; i++) {
        if (key == vet[i]) {
            return 1;
        }
    }
    return 0;
}


// 4. Implementar Busca Binária
int buscaBinaria(int vet[], int size, int chave) {
    int inicio = 0, fim = size - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (chave > vet[meio]) {
            inicio = meio + 1;
        } else if (chave < vet[meio]) {
            fim = meio - 1;
        } else {
            return 1;
        }
    }
    return 0;
}

// 5. Geracao de valores aleatorios
int geraValorAleatorio(int vet[], int tam, int garantirEncontrado) {
    if (garantirEncontrado) {
        int pos = rand() % tam;
        return vet[pos];
    } else {
        return rand() % (TAM * 10);
    }
}

// 6. Calcular tempo de execucao
// Uso:
//   struct timespec inicio, fim;
//   clock_gettime(CLOCK_MONOTONIC, &inicio);
//   ... codigo a medir ...
//   clock_gettime(CLOCK_MONOTONIC, &fim);
//   double t = calculaTempo(inicio, fim);

double calculaTempo(struct timespec inicio, struct timespec fim) {
    return (fim.tv_sec - inicio.tv_sec) +
           (fim.tv_nsec - inicio.tv_nsec) / 1e9;
}

// 7. Calcular media
double calculaMedia(double tempos[], int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += tempos[i];
    }
    return soma / n;
}

// 8. Calcular desvio padrao
double desvioPadrao(double tempos[], int n) {
    double media = calculaMedia(tempos, n);
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = tempos[i] - media;
        soma += diff * diff;
    }
    return sqrt(soma / n);
}