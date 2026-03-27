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

- Criar vetor do tipo inteiro
- Implementar Busca Sequencial
- Implementar Busca Binária
- Criar programa de geracao de valores aleatorios
- Criar programa que calcule o tempo de execucao
- Criar programa que calcule a media entre as 30 execucoes
- Criar programa que calcule o desvio padrao
*/

#ind

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
        soma2 = soma2 + (sub)
    }

}