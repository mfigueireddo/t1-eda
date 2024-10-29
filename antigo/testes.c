#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

// Em caso de colisão, multiplicar por uma constante prima (a ser testada)
void teste_primos(long *vetor){

    // Vetor de números primos
    int tamanho_primos;
    int *primos = gera_primos(TAM_HASH, &tamanho_primos);

    // Colisões
    int *colisoes = (int*)malloc(sizeof(int)*tamanho_primos);
    if (colisoes == NULL) exit(1);

    // Vazios
    int *vazios = (int*)malloc(sizeof(int)*tamanho_primos);
    if (vazios == NULL) exit(1);

    // Colisões + Vazios
    int *soma = (int*)malloc(sizeof(int)*tamanho_primos);
    if (soma == NULL) exit(1);

    // Aplica o método de hash
    for(int i=0; i<tamanho_primos; i++) multiplica_constante(vetor, TAM_CPFS, primos[i], &colisoes[i], &vazios[i],&soma[i]);

    int menor, indiceMenor;

    for(int i=0; i<tamanho_primos; i++){
        if (i == 0){
            menor = colisoes[0];
            indiceMenor = 0;
        }
        else if(colisoes[i] < menor){
            menor = colisoes[i];
            indiceMenor = i;
        }
    }

    /*
    for(int i=0; i<tamanho_primos; i++){
        printf("Número %d\nColisões %d\nVazios %d\nSoma %d\n\n", primos[i], colisoes[i], vazios[i], soma[i]);
    }
    */

    printf("O melhor primo é o %d\n%d colisões\n%d vazios\n%d soma\n\n", primos[indiceMenor], colisoes[indiceMenor], vazios[indiceMenor], soma[indiceMenor]);
}

// Em caso de colisão, somar um
void teste_linear_probing(long *vetor){
    linear_probing(vetor, TAM_CPFS);
}

// Em caso de colisão, multiplicar pelo quadrado de uma constante
void teste_quadratic_probing(long *vetor){
    quadratic_probing(vetor, TAM_CPFS);
}

// Em caso de colisão, executa duas funções de dispersão
void teste_double_hashing(long *vetor){
    double_hashing(vetor, TAM_CPFS);
}

// Faz dobra do CPF
void teste_dobra(long *vetor){
    dobra_linear(vetor, TAM_CPFS);
    dobra_quadratic(vetor, TAM_CPFS);
    dobra_hashing(vetor, TAM_CPFS);
}

// Gera relatório de Double Hashing
void gera_relatorio(long *vetor, int tamanho, char *nome_arq){
    FILE* arq = fopen(nome_arq, "w");
    if (arq == NULL) exit(1);

    int desejados[] = { 100,200,300,400,500,600,700,800,900,1000 };

    long hash[TAM_HASH];

    for(int i=0; i<TAM_HASH; i++){
        hash[i] = -1;
    }

    int indice, indiceAux, insercoes, colisoes, tentativas;
    insercoes = 0;
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
        insercoes++;
        for(int i=0; i<10; i++){
            if (insercoes == desejados[i]){
                fprintf(arq, "%d,%d", insercoes, colisoes);
                if (insercoes != 1000){
                    fprintf(arq, "\n");
                }
            }
        }
        hash[indice] = vetor[i];
    }

    fclose(arq);
}