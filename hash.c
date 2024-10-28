#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int formata_cpf(long cpf){
    long soma = 0;
    while (cpf > 0){
        soma += cpf % 100;
        cpf /= 100;
    }
    return soma % TAM_HASH;
}

int formata_cpf2(long cpf, int n){
    long soma = 0;
    for(int i=0; i<n; i++){
        soma += cpf % 100;
        cpf /= 100;
    }
    return soma % TAM_HASH;
}

void dobra_quadratica(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes, tentativas;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf(vetor[i]);
        printf("%d\n\n", indice);
        tentativas = 0;
        while(hash[indice] != -1){
            indice = (indice + tentativas * tentativas) % TAM_HASH;
            tentativas++;
            colisoes++;
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM_HASH);

    printf("Houveram %d colisões com o método de dobra e com o quadrático.\n\n", colisoes);
}

void dobra_quadratica2(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes, tentativas, n;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf2(vetor[i],1);
        tentativas = 0;
        n = 2;
        while(hash[indice] != -1){
            indice = (indice + tentativas * tentativas) % TAM_HASH;
            tentativas++;
            colisoes++;
            if(hash[indice] != -1){
                indice = formata_cpf2(vetor[i],n);
            }
            n++;
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM_HASH);

    printf("Houveram %d colisões com o método de dobra e com o quadrático 2.\n\n", colisoes);
}

void soma_um(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = vetor[i] % TAM_HASH;
        while(hash[indice] != -1){
            indice++;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM_HASH);

    printf("Houveram %d colisões com o método soma um.\n\n", colisoes);
}

void multiplica_constante(long *vetor, int tamanho, const int constante, int *colisoes, int *vazios, int *resultado){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice;
    *colisoes = 0;
    *vazios = 0;

    for(int i=0; i<tamanho; i++){
        indice = (vetor[i] * constante) % TAM_HASH;
        while(hash[indice] != -1){
            indice++;
            (*colisoes)++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    for(int i=0; i<TAM_HASH; i++){
        if (hash[i] == -1){
            (*vazios)++;
        }
    }

    *resultado = (*colisoes) + (*vazios);

    // exibe_vetor_long(hash, TAM_HASH);
}