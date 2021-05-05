#ifndef HASH_SINONIMOS_T
#define HASH_SINONIMOS_T

typedef struct entrada_hash // estrutura para cada entrada do hash
{
	int chave_hash; // chave
	char palavra[100]; // palavra
	char sinonimos[10000]; // sinonimos
	struct entrada_hash *proximo; // ponteiro para a proxima estrutura em caso de colisao
} entrada_hash_t;

typedef struct // estrutura para a tabela
{
	entrada_hash_t **entradas; // vetor para as entradas
	int tamanho; // tamanho da tabela
} tabela_hash_t;

tabela_hash_t *cria_tabela(int tamanho);
int hash(char pa[]); // funcao hash
void insere_hash(tabela_hash_t *tab, int chave_hash, char p[], char s[]);
char *busca_hash(tabela_hash_t *tab, int chave_hash, char pala[]);
void teste (tabela_hash_t *tab); // imprime os valores atuais da tabela
void destroi_tabela (tabela_hash_t *tab);

#endif
