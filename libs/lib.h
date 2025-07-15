#ifndef LIB_H
#define LIB_H

typedef struct MateriaPrima{
  char *nome;
  float preco;
  int codigo;
  int altura; // altura do nó para balanceamentos 
  struct MateriaPrima *esq, *dir;
} MatPrima;

typedef MateriaProduto{
  int codigo_mat;
  int qtde;
  struct MateriaProduto *prox, *ant;
} MatProduto;

typedef struct TProduto{
  char *nome;
  int codigo;
  float margemLucro;
  struct TProduto *prox, ant*;
  struct MatProduto *ini_mat; // lista de matérias prima utlizada no produto
} Produto;

// protótipos

// leitura e escrita de arquivos
FILE* abrirArquivo(const char *caminho, const char *modo); // abre o arquivo para leitura ou escrita
int escreverCSV(FILE *arquivo, const char *texto); // escreve um csv e retorna flag 
void lerCSV(FILE *arquivo); // lê um arq csv e escreve-o em lista ou arvore
int fecharArquivo(FILE *arquivo); // fecha arquivo

// implementação e manipulação de lista duplamente encadeada
// mat produto
// produto

// arvore avl para manipulaçaõ de matéria prima 
MatPrima *novoNo(char *nome, float preco); // obs* novo->codigo = gerarCodigo(char *str)
MatPrima *inserirArvore(MatPrima *no, char *nome, float preco);
MatPrima *rotacaoDir(MatPrima *no);
MatPrima *rotacaoEsq(MatPrima *no);
MatPrima *searchFromTree(MatPrima *head, int codigo);
MatPrima *removeFromTree(MatPrima *head, int codigo);
MatPrima *editTreeNode(MatPrima *head, int codigo);
int obterAltura(MatPrima *no);
void inOrder(MatPrima *head);
void freeTree(MatPrima *head);

// utilitários
void menu(); // UI
void limparTela();
int getOpcao(); // lê opcao e trata erros antes de retornar
void opcaoHandler(int opcao); // recebe opcaoe direciona para as funcionalidades
int gerarCodigo(char *str); // recebe uma string e retorna um codigo/hash
float calcularPrecoVenda(float margemLucro, MatPrima *listaMateriais);
float calcularPrecoCusto(MatPrima* listaMateriais);
int max(int a, int b); // Retorna o maior entre dois inteiros               


#endif
