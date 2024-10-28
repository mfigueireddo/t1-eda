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
    for(int i=0; i<tamanho; i++){
        printf("Número %d\nColisões %d\nVazios %d\nSoma %d\n\n", primos[i], colisoes[i], vazios[i], soma[i]);
    }
    */

    printf("O melhor primo é o %d\n%d colisões\n%d vazios\n%d soma\n", primos[indiceMenor], colisoes[indiceMenor], vazios[indiceMenor], soma[indiceMenor]);
}

// Em caso de colisão, multiplicar por uma constante prima (a melhor)
void teste_melhor_primo(long *vetor, int primo){
    int colisoes, vazios, soma;
    multiplica_constante(vetor, TAM_CPFS, primo, &colisoes, &vazios, &soma); 
    printf("Número %d\nColisões %d\nVazios %d\nSoma %d\n\n", primo, colisoes, vazios, soma);
}

// Em caso de colisão, somar um
void teste_soma_um(long *vetor){
    soma_um(vetor, 1000);
}

// Fazer dobra e, em caso de colisão, multiplicar pelo quadrado das tentativas
void teste_dobra_quadratica(long *vetor){
    dobra_quadratica(vetor, 1000);
}

// Fazer dobra e, em caso de colisão, multiplicar pelo quadrado das tentativas e dobrar de novo
void teste_dobra_quadratica2(long *vetor){
    dobra_quadratica2(vetor, 1000);
}