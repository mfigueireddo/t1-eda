#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

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

int* gera_primos(int range, int* tamanho) {
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

int formata_cpf(long cpf){
    long soma = 0;
    while (cpf > 0){
        soma += cpf % 100;
        cpf /= 100;
    }
    return soma % TAM;
}

int formata_cpf2(long cpf, int n){
    long soma = 0;
    for(int i=0; i<n; i++){
        soma += cpf % 100;
        cpf /= 100;
    }
    return soma % TAM;
}

void dobra_quadratica(long *vetor, int tamanho){

    long hash[TAM];

    for(int i=0; i<TAM; i++){
        hash[i] = -1;
    }

    int indice, colisoes, tentativas;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf(vetor[i]);
        printf("%d\n\n", indice);
        tentativas = 0;
        while(hash[indice] != -1){
            indice = (indice + tentativas * tentativas) % TAM;
            tentativas++;
            colisoes++;
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM);

    printf("Houveram %d colisões com o método de dobra e com o quadrático.\n\n", colisoes);
}

void dobra_quadratica2(long *vetor, int tamanho){

    long hash[TAM];

    for(int i=0; i<TAM; i++){
        hash[i] = -1;
    }

    int indice, colisoes, tentativas, n;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf2(vetor[i],1);
        tentativas = 0;
        n = 2;
        while(hash[indice] != -1){
            indice = (indice + tentativas * tentativas) % TAM;
            tentativas++;
            colisoes++;
            if(hash[indice] != -1){
                indice = formata_cpf2(vetor[i],n);
            }
            n++;
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM);

    printf("Houveram %d colisões com o método de dobra e com o quadrático 2.\n\n", colisoes);
}

void soma_um(long *vetor, int tamanho){

    long hash[TAM];

    for(int i=0; i<TAM; i++){
        hash[i] = -1;
    }

    int indice, colisoes;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = vetor[i] % TAM;
        while(hash[indice] != -1){
            indice++;
            colisoes++;
            if (indice >= TAM){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM);

    printf("Houveram %d colisões com o método soma um.\n\n", colisoes);
}

void multiplica_constante(long *vetor, int tamanho, const int constante){

    long hash[TAM];

    for(int i=0; i<TAM; i++){
        hash[i] = -1;
    }

    int indice, colisoes;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = (vetor[i] * constante) % TAM;
        while(hash[indice] != -1){
            indice++;
            colisoes++;
            if (indice >= TAM){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM);

    if (colisoes<2000)
        printf("Houveram %d colisões multiplicando por %d.\n\n", colisoes, constante);
}