#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int main(void){

    // Vetor com 1000 CPFs
    long *vetor = gera_vetor("cpf_list.txt");

    teste_primos(vetor); // O melhor é 367
    teste_linear_probing(vetor);
    teste_quadratic_probing(vetor);
    teste_double_hashing(vetor);
    teste_dobra(vetor);

    gera_relatorio(vetor, TAM_CPFS, "dados.txt");

    return 0;
}