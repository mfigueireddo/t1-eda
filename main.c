#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int main(void){

    long vetor[1000];

    long aux;
    int indice = 0;

    FILE* arquivo = fopen("cpf_list.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(arquivo, " %ld", &aux) == 1) {
        vetor[indice++] = aux;
    }
    
    int tamanho;
    int* primos = gera_primos(TAM, &tamanho);
    
    for(int i=0; i<tamanho; i++){
        multiplica_constante(vetor, 1000, primos[i]);
    }

    // soma_um(vetor, 1000);

    // dobra_quadratica(vetor, 1000);

    // dobra_quadratica2(vetor, 1000);
}