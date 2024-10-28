#define TAM_HASH 1201 // primeiro número primo depois de 1000 
#define TAM_CPFS 1000 // quantidade de CPFs

void teste_primos(long *vetor);
void teste_melhor_primo(long *vetor, int primo);
void teste_soma_um(long *vetor);
void teste_dobra_quadratica(long *vetor);
void teste_dobra_quadratica2(long *vetor);

int formata_cpf(long cpf);
int formata_cpf2(long cpf, int n);
void dobra_quadratica(long *vetor, int tamanho);
void dobra_quadratica2(long *vetor, int tamanho);
void soma_um(long *vetor, int tamanho);
void multiplica_constante(long *vetor, int tamanho, const int constante, int *colisoes, int *vazios, int *resultado);

long* gera_vetor(char *nome_arq);
void exibe_vetor_long(long *vetor, int tamanho);
void exibe_vetor_int(int *vetor, int tamanho);
int* gera_primos(int range, int* tamanho);