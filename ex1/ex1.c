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

<<<<<<< HEAD
- Criar vetor do tipo inteiro
- Implementar Busca Sequencial
- Implementar Busca Binária
- Criar programa de geracao de valores aleatorios
- Criar programa que calcule o tempo de execucao
- Criar programa que calcule a media entre as 30 execucoes
- Criar programa que calcule o desvio padrao.  (OK)
*/

#include <stdio.h> 
#include <math.h>
#include "EX1.h"

// 1. Criar vetor

// 2. 

// Desvio
=======
1.Criar vetor do tipo inteiro
2.Implementar Busca Sequencial
3.Implementar Busca Binária
4.Criar programa de geracao de valores aleatorios
5.Criar programa que calcule o tempo de execucao
6.Criar programa que calcule a media entre as 30 execucoes
7.Criar programa que calcule o desvio padrao
*/

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
// END

void ler(int *v, int size) {
    for (int i = 0; i < size; i++)
        scanf("%d%*c", &v[i]);
}

int main() {
    int chave;
    int size;
    scanf("%d%*c",&chave);
    scanf("%u%*c",&size); // tamanho do vetor
    int vet[size];
    ler(vet,size);
    if (buscaBinaria(vet, size, chave)) {
        printf("SIM");
    } else {
        printf("NAO");
    }
}
//7.Criar programa que calcule o desvio padrao
>>>>>>> bd1385abe04201444cf42112580b487337f60382
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

<<<<<<< HEAD
    soma2 = soma2 / n;
    return desvio = sqrt(soma2);
}
=======
}
>>>>>>> bd1385abe04201444cf42112580b487337f60382
