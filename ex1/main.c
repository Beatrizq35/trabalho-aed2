#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h" // Importante: inclui as assinaturas que você definiu

#define TAM 1000000
#define EXECUCOES 30

int main() {
    // 1. Inicializa a semente para números aleatórios
    srand(time(NULL));

    // 2. Alocação dinâmica dos vetores (evita estouro de pilha/stack overflow)
    int *v_desordenado = (int *)malloc(TAM * sizeof(int));
    int *v_ordenado = (int *)malloc(TAM * sizeof(int));

    if (v_desordenado == NULL || v_ordenado == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // 3. Preenchimento dos vetores
    printf("Preenchendo vetores... Aguarde.\n");
    criaVetDesordenado(v_desordenado, TAM);
    criaVetOrdenado(v_ordenado, TAM);

    // Arrays para armazenar os tempos de cada execução
    double tempos_seq[EXECUCOES];
    double tempos_bin[EXECUCOES];

    printf("Iniciando buscas (30 execuções para cada algoritmo)...\n");

    for (int i = 0; i < EXECUCOES; i++) {
        struct timespec inicio, fim;
        int chave;

        // Regra do trabalho: 15 buscas com valores que existem, 15 aleatórias
        if (i < 15) {
            // Sorteia uma posição e pega o valor que está nela (garante existência)
            int pos_sorteada = rand() % TAM;
            chave = v_desordenado[pos_sorteada]; 
        } else {
            // Gera um valor aleatório qualquer
            chave = rand() % (TAM * 10);
        }

        // --- TESTE BUSCA SEQUENCIAL ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        buscaSequencial(v_desordenado, chave);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempos_seq[i] = calculaTempo(inicio, fim);

        // --- TESTE BUSCA BINÁRIA ---
        // Repetimos a lógica da chave para o vetor ordenado
        if (i < 15) {
            int pos_sorteada = rand() % TAM;
            chave = v_ordenado[pos_sorteada];
            printf("[Execução %d] Buscando valor garantido: %d\n", i, chave);
        } else {
            chave = rand() % (TAM * 10);
            printf("[Execução %d] Buscando valor aleatório: %d\n", i, chave);
        }

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        buscaBinaria(v_ordenado, chave);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempos_bin[i] = calculaTempo(inicio, fim);
    }

    // 4. Cálculos Estatísticos
    double media_seq = calculaMedia(tempos_seq, EXECUCOES);
    double desvio_seq = desvioPadrao(tempos_seq, EXECUCOES);

    double media_bin = calculaMedia(tempos_bin, EXECUCOES);
    double desvio_bin = desvioPadrao(tempos_bin, EXECUCOES);

    // 5. Exibição dos Resultados
    printf("\n================ RESULTADOS ================\n");
    printf("ALGORITMO         | MEDIA (s)    | DESVIO PADRAO\n");
    printf("--------------------------------------------\n");
    printf("Busca Sequencial  | %10.8f | %10.8f\n", media_seq, desvio_seq);
    printf("Busca Binaria     | %10.8f | %10.8f\n", media_bin, desvio_bin);
    printf("============================================\n");

    // 6. Liberação de memória
    free(v_desordenado);
    free(v_ordenado);

    return 0;
}
