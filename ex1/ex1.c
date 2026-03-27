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

#define TAM 1000000

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


// 4. Implementar Busca Binária
int buscaBinaria(int vet[],int size,int chave){
    int inicio = 0,fim = size-1;
    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(chave > vet[meio]){
            inicio = meio+1;
        }else if(chave < vet[meio]){
            fim = meio-1;
        }else{
            return 1;
        }
    }
    return 0;
}

// 5. Criar programa de geracao de valores aleatorios


// 6. Criar programa que calcule o tempo de execucao

// 7. Criar programa que calcule o desvio padrao
float desvio_padrao (int vet[], int n) {
    int i;
    float media, desvio;
    float soma1, soma2, sub = 0.0;

    //calcula a media
    for (i = 0; i < n; i++) {
        soma1 = soma1 + vet[i];
    }
    media = soma1 / n;

    //subtrai a media de cada valor e eleva ao quadrado
    for (i = 0; i < n; i++) {
        sub = vet[i] - media;
        soma2 = soma2 + pow(sub, 2);
    }

    soma2 = soma2 / n;
    return desvio = sqrt(soma2);
}
