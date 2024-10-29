#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_CPFS 1000
#define TAM_HASH 1201

void linear_probing(void);
void quadratic_probing(void);
void double_hashing(void);
int constante_prima(int primo);
void dobra_linear_probing(void);
void dobra_quadratic_probing(void);
void dobra_double_hashing(void);

FILE* abre_arquivo(char* nome_arq, char* modo);
long* gera_vetor(char *nome_arq);
void conta_vazios(long *vetor, int tam);
long dobra(long cpf);
int* gera_primos(int limite, int* tamanho);

int main(void){

    linear_probing();
    quadratic_probing();
    double_hashing();

    int tam_primos, menor, iMenor, aux;
    int* primos = gera_primos(TAM_HASH, &tam_primos);
    menor = 0;
    for(int i=0; i<tam_primos; i++){
        aux = constante_prima(primos[i]);
        if(i == 0){
            menor = aux;
            iMenor = i;
        }
        if (aux < menor){
            menor = aux;
            iMenor = i;
        }
    }
    printf("O primo com menos colisões é %d com %d colisões.\n\n", primos[iMenor], menor);
    free(primos);

    dobra_linear_probing();
    dobra_quadratic_probing();
    dobra_double_hashing();

    return 0;
}

void linear_probing(void){

    long tabela_hash[TAM_HASH];
    int hash, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash = vetor[i] % TAM_HASH;
        tentativas = 0;
        while(tabela_hash[hash] != -1){
            colisoes++;
            tentativas++;
            hash = (vetor[i] % TAM_HASH + tentativas) % TAM_HASH;
        }
        tabela_hash[hash] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash], hash);
    }

    conta_vazios(tabela_hash, TAM_HASH);
    printf("\n%d colisões com o método Linear Probing.\n\n", colisoes);

    free(vetor);

    
}

void quadratic_probing(void){

    long tabela_hash[TAM_HASH];
    int hash, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash = vetor[i] % TAM_HASH;
        tentativas = 0;
        while(tabela_hash[hash] != -1){
            colisoes++;
            tentativas++;
            hash = (vetor[i] % (TAM_HASH) + tentativas * tentativas) % TAM_HASH;
        }
        tabela_hash[hash] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash], hash);
    }

    conta_vazios(tabela_hash, TAM_HASH);
    printf("\n%d colisões com o método Quadratic Probing.\n\n", colisoes);

    free(vetor);

    
}

void double_hashing(void){

    long tabela_hash[TAM_HASH];
    int hash1, hash2, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash1 = vetor[i] % TAM_HASH;
        tentativas = 0;
        while(tabela_hash[hash1] != -1){
            colisoes++;
            tentativas++;
            hash2 = 1 + (vetor[i] % (TAM_HASH-1));
            hash1 = (vetor[i] % TAM_HASH + tentativas * hash2) % TAM_HASH;
        }

        tabela_hash[hash1] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash1], hash1);
    }

    conta_vazios(tabela_hash, TAM_HASH);
    printf("\n%d colisões com o método Double Hashing.\n\n", colisoes);

    free(vetor);

    
}

int constante_prima(int primo){

    long tabela_hash[TAM_HASH];
    int hash, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash = (vetor[i] * primo) % TAM_HASH;
        tentativas = 0;
        while(tabela_hash[hash] != -1){
            colisoes++;
            tentativas++;
            hash = ((vetor[i] * primo % TAM_HASH) + tentativas) % TAM_HASH;
        }

        tabela_hash[hash] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash], hash);
    }

    // conta_vazios(tabela_hash, TAM_HASH);
    // printf("\n%d colisões com o método multiplicação pela constante %d.\n\n", colisoes, primo);

    free(vetor);

    return colisoes;
}

void dobra_linear_probing(void){

    long tabela_hash[TAM_HASH];
    int hash, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash = dobra(vetor[i]);
        tentativas = 0;
        while(tabela_hash[hash] != -1){
            colisoes++;
            tentativas++;
            hash = (dobra(vetor[i]) + tentativas) % TAM_HASH;
        }
        tabela_hash[hash] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash], hash);
    }

    conta_vazios(tabela_hash, TAM_HASH);
    printf("\n%d colisões com o método de Dobra + Linear Probing.\n\n", colisoes);

    free(vetor);

    
}

void dobra_quadratic_probing(void){

    long tabela_hash[TAM_HASH];
    int hash, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash = dobra(vetor[i]);
        tentativas = 0;
        while(tabela_hash[hash] != -1){
            colisoes++;
            tentativas++;
            hash = (dobra(vetor[i]) + tentativas * tentativas) % TAM_HASH;
        }
        tabela_hash[hash] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash], hash);
    }

    conta_vazios(tabela_hash, TAM_HASH);
    printf("\n%d colisões com o método de Dobra + Quadratic Probing.\n\n", colisoes);

    free(vetor);

    
}

void dobra_double_hashing(void){

    long tabela_hash[TAM_HASH];
    int hash1, hash2, tentativas, colisoes;
    colisoes = 0;

    long *vetor = gera_vetor("cpf_list.txt");

    for(int i=0; i<TAM_HASH; i++){
        tabela_hash[i] = -1;
    }

    for(int i=0; i<TAM_CPFS; i++){
        hash1 = dobra(vetor[i]);
        tentativas = 0;
        while(tabela_hash[hash1] != -1){
            colisoes++;
            tentativas++;
            hash2 = 1 + (dobra(vetor[i]) % (TAM_HASH-1));
            hash1 = (dobra(vetor[i]) + tentativas * hash2) % TAM_HASH;
        }

        tabela_hash[hash1] = vetor[i];
        // printf("%ld inserido na posição %d\n", tabela_hash[hash1], hash1);
    }

    conta_vazios(tabela_hash, TAM_HASH);
    printf("\n%d colisões com o método de Dobra + Double Hashing.\n\n", colisoes);

    free(vetor);

    
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
    printf("%d posições vazias.", vazios);
}

long dobra(long cpf){
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

    long indice = soma % (TAM_HASH);

    return indice;
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