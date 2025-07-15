#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

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
  struct MatProduto *ini_mat; // lista de matérias prima utlizada no produto
  struct TProduto *prox, ant*;
 } Produto;

// protótipos

// leitura e escrita de arquivos
FILE* abrirArquivo(const char *caminho, const char *modo); // abre o arquivo para leitura ou escrita
int escreverCSV(FILE *arquivo, const char *texto); // escreve um csv e retorna flag 
void lerCSV(FILE *arquivo); // lê um arq csv e escreve-o em lista ou arvore
int fecharArquivo(FILE *arquivo); // fecha arquivo

// implementação e manipulação de lista duplamente encadeada
// Lista de Produtos
Produto *criarProduto(char *nome, float margemLucro);
Produto *buscarProduto(Produto *head, int codigo); // busca detalhada de um único produto
void inserirProduto(Produto **head, Produto *novoProduto); // inserção ordenada
void removerProduto(Produto **head, int codigo);
void editarProduto(Produto **head, int codigo);
void imprimirProdutos(Produto *head); // mostra uma lista com todos os produtos de forma resumida
void liberarProdutos(Produto **head); // librar a lista de produtos

// Lista de Matérias-Prima do Produto - MatProduto
MatProduto *criarListaMatProd(int codigo_mat, int qtde); // o codigo daqui deve ser o mesmo de 
void *inserirListaMatProd(MatProduto **head, MatProduto *novoMat);
void imprimeListaMatProd(MatProduto *head);
void removeMatProd(MatProduto **head, int codigo);
void liberarMatProdutos(MatProduto **head);

// Arvore Balanceada para Matérias-Prima
MatPrima *novoNo(char *nome, float preco); // obs* novo->codigo = gerarCodigo(char *str)
MatPrima *inserirArvore(MatPrima *no, char *nome, float preco);
MatPrima *rotacaoDir(MatPrima *no);
MatPrima *rotacaoEsq(MatPrima *no);
MatPrima *searchFromTree(MatPrima *head, int codigo);
MatPrima *removeFromTree(MatPrima *head, int codigo);
MatPrima *editTreeNode(MatPrima *head, int codigo);
int obterAltura(MatPrima *no);
void inOrder(MatPrima *head);
void fecharArvore(MatPrima *head);

// utilitários
void menu(); // UI
void limparTela();
int getOpcao(); // lê opcao e trata erros antes de retornar
void opcaoHandler(int opcao); // recebe opcaoe direciona para as funcionalidades
int gerarCodigo(char *str); // recebe uma string e retorna um codigo/hash
float calcularPrecoVenda(float margemLucro, MatPrima *listaMateriais);
float calcularPrecoCusto(MatPrima* listaMateriais);
int max(int a, int b); // Retorna o maior entre dois inteiros               
void esperar(); // espera um enter para continuar o fluxo do programa

#endif
