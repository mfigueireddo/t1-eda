#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int main(void){

    // Vetor com 1000 CPFs
    long *vetor = gera_vetor("cpf_list.txt");

    //teste_primos(vetor);
    teste_melhor_primo(vetor, 367);
    //teste_soma_um(vetor);
    //teste_dobra_quadratica(vetor);
    //teste_dobra_quadratica2(vetor);

    return 0;
}