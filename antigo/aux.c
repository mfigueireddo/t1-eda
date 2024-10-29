#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

long* gera_vetor(char *nome_arq){
    // Vetor para armazenar TAM_CPFS CPFs
    long *vetor = (long*)malloc(sizeof(long)*TAM_CPFS);
    if (vetor == NULL) exit(1);

    long aux; // Armazena o CPF
    int indice = 0; // Guarda o índice no vetor de CPFs

    // Abre o arquivo
    FILE* arquivo = fopen(nome_arq, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Guarda os CPFs no arquivo
    while (fscanf(arquivo, " %ld", &aux) == 1) {
        vetor[indice++] = aux;
    }

    // Retorna o vetor de CPFs
    return vetor;
}

void exibe_vetor_long(long *vetor, int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%ld\n", vetor[i]);
    }
}

void exibe_vetor_int(int *vetor, int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%d\n", vetor[i]);
    }
}

int* gera_primos(int range, int* tamanho){
    bool* is_prime = malloc((range + 1) * sizeof(bool));
    if (is_prime == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    for (int i = 0; i <= range; i++) {
        is_prime[i] = true;  // Assume que todos são primos inicialmente
    }
    is_prime[0] = is_prime[1] = false;  // 0 e 1 não são primos

    for (int i = 2; i * i <= range; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= range; j += i) {
                is_prime[j] = false;  // Marca múltiplos de i como não-primos
            }
        }
    }

    // Conta quantos números primos foram encontrados
    int count = 0;
    for (int i = 2; i <= range; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    // Aloca o vetor para armazenar os números primos
    int* primos = malloc(count * sizeof(int));
    if (primos == NULL) {
        printf("Erro ao alocar memória.\n");
        free(is_prime);
        return NULL;
    }

    // Preenche o vetor com os números primos
    int index = 0;
    for (int i = 2; i <= range; i++) {
        if (is_prime[i]) {
            primos[index++] = i;
        }
    }

    free(is_prime);
    *tamanho = count;  // Retorna o tamanho do vetor de primos encontrado
    return primos;
}

long formata_cpf(long cpf){
    long aux;
    long soma = 0;

    for(int i=0; i<2; i++){
        aux = cpf % 10000;
        cpf /= 10000;

        soma += aux;
        soma %= 10000;
    }

    aux = cpf % 1000;
    soma += aux;
    soma %= 10000;

    // Aplicar o módulo 1201 para obter o índice final
    long indice = soma % (TAM_HASH);

    return indice;
}

long formata_cpf2(long cpf){
    long aux;
    long soma = 0;

    for(int i=0; i<2; i++){
        aux = cpf % 10000;
        cpf /= 10000;

        soma += aux;
        soma %= 10000;
    }

    aux = cpf % 1000;
    soma += aux;
    soma %= 10000;

    // Aplicar o módulo 1201 para obter o índice final
    long indice = 1 + soma % (TAM_HASH-1);

    return indice;
}