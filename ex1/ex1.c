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

// 1.Criar vetor do tipo inteiro

int criaVetDesordenado (int vet[], int n, int tam) {
    int i;

    for (i = 0; i < tam; i++) {

    }
}

// 2. Implementar Busca Sequencial

// 3. Implementar Busca Binária

<<<<<<< HEAD
=======
#ind
1.
1.2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 1000000

void gerarVetorOrdenado(int *vet, int size) {
    // Usamos long para evitar overflow durante a geração se os números crescerem muito
    long long atual = rand() % 50; 
    
    for (int i = 0; i < size; i++) {
        vet[i] = (int)atual;
        // Incremento entre 1 e 10. Como o mínimo é 1, NUNCA haverá repetidos.
        atual += (rand() % 10) + 1; 
    }
}

int main() {
    // Alocação dinâmica é necessária para 1 milhão de itens (evita estouro de pilha/stack overflow)
    int *vet = (int *)malloc(TAMANHO * sizeof(int));
    
    if (vet == NULL) {
        printf("Erro de memória!\n");
        return 1;
    }

    srand(time(NULL));

    printf("Gerando 1.000.000 de valores...\n");
    gerarVetorOrdenado(vet, TAMANHO);

    // Teste: Imprimir os 10 primeiros e os 10 últimos
    printf("Primeiros 5: ");
    for(int i = 0; i < 5; i++) printf("%d ", vet[i]);
    
    printf("\nUltimos 5: ");
    for(int i = TAMANHO-5; i < TAMANHO; i++) printf("%d ", vet[i]);
    
    printf("\n\nSucesso! Vetor pronto para busca binaria.\n");

    // Lembre-se de liberar a memória no final
    free(vet);
    return 0;
}
//3.Implementar Busca Binária
// BEGIN
>>>>>>> 00578c241f6c59b78df29b0b1108994e564d4ec3
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

// 4. Implementar Busca Binária


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


// Declarando fora da main para evitar estouro de pilha (stack overflow)
int vetor[TAM];

void preencherVetor(int v[], int tamanho) {
    // srand define a "semente" do gerador baseada no tempo atual
    srand(time(NULL)); 

    for (int i = 0; i < tamanho; i++) {
        // rand() % 100 gera de 0 a 99. Somamos 1 para ficar de 1 a 100.
        v[i] = (rand() % 100) + 1;
    }
}