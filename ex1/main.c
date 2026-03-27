// Chamada das funções
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "EX1.h"


int main(){
  srand(time(NULL)); //srand(gerar números aleatorios toda vez que rodar) e time(NULL)//Pega o tempo atual em segundos
  / 2. Cria e preenche os vetores usando o TAD
    Vetor *v_desordenado = cria_vetor(TAM);
    Vetor *v_ordenado = cria_vetor(TAM);
    
    preenche_desordenado(v_desordenado);
    preenche_ordenado(v_ordenado);

    // Vetores para guardar os tempos de cada uma das 30 execuções
    double tempos_sequencial[EXECUCOES];
    double tempos_binaria[EXECUCOES];

    printf("Executando buscas, aguarde...\n");

    for (int i = 0; i < EXECUCOES; i++) {
        int chave_seq, chave_bin;
        struct timespec inicio, fim;

        // Regra: 15 primeiros garantem que o valor existe, 15 últimos são aleatórios
        int garantir = (i < 15);

        // --- BUSCA SEQUENCIAL ---
        if (garantir) 
            chave_seq = busca_valor_por_indice(v_desordenado, rand() % TAM);
        else 
            chave_seq = rand() % (TAM * 10);

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        busca_sequencial(v_desordenado, chave_seq);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempos_sequencial[i] = calculaTempo(inicio, fim);

        // --- BUSCA BINÁRIA ---
        if (garantir) 
            chave_bin = busca_valor_por_indice(v_ordenado, rand() % TAM);
        else 
            chave_bin = rand() % (TAM * 10);

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        busca_binaria(v_ordenado, chave_bin);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        tempos_binaria[i] = calculaTempo(inicio, fim);
    }

    // 3. Calcula e mostra os resultados finais
    double media_seq = calculaMedia(tempos_sequencial, EXECUCOES);
    double dp_seq = desvioPadrao(tempos_sequencial, EXECUCOES);

    double media_bin = calculaMedia(tempos_binaria, EXECUCOES);
    double dp_bin = desvioPadrao(tempos_binaria, EXECUCOES);

    printf("\n--- RESULTADOS BUSCA SEQUENCIAL ---\n");
    printf("Media: %f segundos\n", media_seq);
    printf("Desvio Padrao: %f segundos\n", dp_seq);

    printf("\n--- RESULTADOS BUSCA BINARIA ---\n");
    printf("Media: %f segundos\n", media_bin);
    printf("Desvio Padrao: %f segundos\n", dp_bin);

    // 4. Libera a memória (Importante para evitar Memory Leak!)
    libera_vetor(v_desordenado);
    libera_vetor(v_ordenado);

    return 0;
}
  void criaVetDesordenado(vet[],tam);
  void criaVetOrdenado(vet[],tam);
  int buscaSequencial (vet[],key);
  int buscaBinaria(vet[],size,chave);
  int geraValorAleatorio(vet[],tam,garantirEncontrado);
  double calculaTempo(struct timespec inicio, struct timespec fim);
  double calculaMedia(double tempos[], int n);
  double desvioPadrao(double tempos[], int n);
  

  
}

