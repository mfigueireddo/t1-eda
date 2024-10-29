#include <stdio.h>
#include <stdlib.h>

#define TAM_CPFS 1000
#define TAM_HASH 1657

FILE* abre_arquivo(char* nome_arq, char* modo);
long* gera_vetor(char *nome_arq);
void conta_vazios(long *vetor, int tam);

int main(void){

    long tabela_hash[TAM_HASH];
    int hash, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    FILE* saida = abre_arquivo("dados.txt", "w");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }


    for(int i=0; i<TAM_CPFS; i++){
        hash = vetor[i] % TAM_HASH;
        tentativas = 0;
        while(tabela_hash[hash] != -1){
            colisoes++;
            tentativas++;
            hash = ((vetor[i] % TAM_HASH) + tentativas + (tentativas*tentativas)) % TAM_HASH;
        }
        if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900 || i == 1000){
            fprintf(saida, "%d,%d", i, colisoes);
            if (i != 1000) fprintf(saida, "\n");
        }
        tabela_hash[hash] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash], hash);
    }

    printf("\n%d colisões.\n", colisoes);
    conta_vazios(tabela_hash, TAM_HASH);

    free(vetor);
    fclose(saida);

    return 0;
}

FILE* abre_arquivo(char* nome_arq, char* modo){
    FILE* arquivo = fopen(nome_arq, modo);
    if (arquivo == NULL) exit(1);
    return arquivo;
}

long* gera_vetor(char* nome_arq){

    FILE* arquivo = abre_arquivo(nome_arq, "r");

    long* vetor = (long*)malloc(sizeof(long)*TAM_CPFS);
    if (vetor == NULL) exit(1);

    long aux;
    int indice = 0;

    while (fscanf(arquivo, " %ld", &aux) == 1) {
        vetor[indice++] = aux;
    }

    fclose(arquivo);

    return vetor;
}

void conta_vazios(long *vetor, int tam){
    int vazios = 0;
    for(int i=0; i<tam; i++){
        if (vetor[i] == -1) vazios++;
    }
    printf("\nExistem %d posições vazias.\n", vazios);
}