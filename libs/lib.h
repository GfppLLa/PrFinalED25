#ifndef LIB_H
#define LIB_H

typedef struct MateriaPrima{
  char *nome;
  float preco;
  int codigo;
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
// criar no, inserir no inicio/fim, percorrer, excluir...

// implementação e manipulação de arvore AVL
// inserções, rotações, percurso, excluir...

// funçoes para a lista de produtos, incluem produtos.csv e dll.c
// inserir, excluir e alterar, salvar modificações no arquivo, listar todos, consultar por nome/codigo   

// funções para a lista de matéria prima, incluem matPrima.csv e tree.c
// inserir, excluir e alterar, salvar modificações no arquivo, listar todos, consultar por nome/codigo   

// utilitários
void menu(); // UI
void limparTela();
int getOpcao(); // lê opcao e trata erros antes de retornar
void opcaoHandler(int opcao);
int gerarCodigo(char *str); // recebe uma string e retorna um codigo/hash
float calcularPrecoVenda(float margemLucro, MatPrima *listaMateriais);
float calcularPrecoCusto(MatPrima* listaMateriais);

#endif
