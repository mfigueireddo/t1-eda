#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

void linear_probing(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes, incremento;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = vetor[i] % TAM_HASH;
        incremento = 0;
        while(hash[indice] != -1){
            incremento++; 
            indice = (vetor[i] % TAM_HASH + incremento) % TAM_HASH;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM_HASH);

    printf("Houveram %d colisões com o método Linear Probing.\n\n", colisoes);
}

void quadratic_probing(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes, tentativas;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = vetor[i] % TAM_HASH;
        tentativas = 0;
        while(hash[indice] != -1){
            tentativas++;
            indice = (vetor[i] % TAM_HASH + tentativas * tentativas) % TAM_HASH;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor_long(hash, TAM_HASH);

    printf("Houveram %d colisões com o método Quadratic Probing.\n\n", colisoes);
}

void double_hashing(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, indiceAux, colisoes, tentativas;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = vetor[i] % TAM_HASH;
        tentativas = 0;
        while(hash[indice] != -1){
            tentativas++;
            indiceAux = 1 + (vetor[i] % (TAM_HASH-1));
            indice = (vetor[i] % TAM_HASH + tentativas * indiceAux) % TAM_HASH;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor_long(hash, TAM_HASH);

    printf("Houveram %d colisões com o método Double Hashing.\n\n", colisoes);
}

void dobra_linear(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes, incremento;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf(vetor[i]);
        incremento = 0;
        while(hash[indice] != -1){
            incremento++; 
            indice = (vetor[i] % TAM_HASH + incremento) % TAM_HASH;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM_HASH);

    printf("Houveram %d colisões com o método de Dobra e Linear Probing.\n\n", colisoes);
}

void dobra_quadratic(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, colisoes, tentativas;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf(vetor[i]);
        tentativas = 0;
        while(hash[indice] != -1){
            tentativas++;
            indice = (vetor[i] % TAM_HASH + tentativas * tentativas) % TAM_HASH;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor(hash, TAM_HASH);

    printf("Houveram %d colisões com o método de Dobra e Quadratic Probing.\n\n", colisoes);
}

void dobra_hashing(long *vetor, int tamanho){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, indiceAux, colisoes, tentativas;
    colisoes = 0;

    for(int i=0; i<tamanho; i++){
        indice = formata_cpf(vetor[i]);
        tentativas = 0;
        while(hash[indice] != -1){
            tentativas++;
            indiceAux = formata_cpf2(vetor[i]);
            indice = (formata_cpf(vetor[i]) + tentativas * indiceAux) % TAM_HASH;
            colisoes++;
            if (indice >= TAM_HASH){
                indice = 0;
            }
        }
        hash[indice] = vetor[i];
    }

    // exibe_vetor_long(hash, TAM_HASH);

    printf("Houveram %d colisões com o método de Dobra com Double Hashing.\n\n", colisoes);
}

void multiplica_constante(long *vetor, int tamanho_vetor, const int constante, int *colisoes, int *vazios, int *resultado){

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice;
    *colisoes = 0;
    *vazios = 0;

    for(int i=0; i<tamanho_vetor; i++){
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