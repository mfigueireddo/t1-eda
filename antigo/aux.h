#define TAM_HASH 1201 // primeiro número primo depois de 1000 
#define TAM_CPFS 1000 // quantidade de CPFs

void teste_primos(long *vetor);
void teste_linear_probing(long *vetor);
void teste_quadratic_probing(long *vetor);
void teste_double_hashing(long *vetor);
void teste_dobra(long *vetor);
void gera_relatorio(long *vetor, int tamanho, char *nome_arq);

void linear_probing(long *vetor, int tamanho);
void quadratic_probing(long *vetor, int tamanho);
void double_hashing(long *vetor, int tamanho);
void dobra_linear(long *vetor, int tamanho);
void dobra_quadratic(long *vetor, int tamanho);
void dobra_hashing(long *vetor, int tamanho);
void multiplica_constante(long *vetor, int tamanho_vetor, const int constante, int *colisoes, int *vazios, int *resultado);
void relacao_colisoes(long* vetor, int tamanho_vetor, int primo, char *nome_arq);

long* gera_vetor(char *nome_arq);
void exibe_vetor_long(long *vetor, int tamanho);
void exibe_vetor_int(int *vetor, int tamanho);
int* gera_primos(int range, int* tamanho);
long formata_cpf(long cpf);
long formata_cpf2(long cpf);