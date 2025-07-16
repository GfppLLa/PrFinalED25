#ifndef PRODUTOSLDE_H_INCLUDED
#define PRODUTOSLDE_H_INCLUDED

Produto* criarProduto(int codigoProduto, const char* nome, double margemLucro); // Cria e retorna um novo produto
Produto* posicaoProduto(Produto* lista, int codigo); // Retorna o nó anterior à posição de inserção ordenada
Produto* inserirProdutoOrdenado(Produto* lista, int codigo, const char* nome, double margemLucro); // Insere um produto na lista duplamente encadeada de forma ordenada
Produto* excluirProduto(Produto* lista, int codigo); // Remove um produto da lista pelo código
void imprimirProdutos(Produto* lista, MateriaPrima *raiz); // Imprime todos os produtos com suas matérias-primas e preços
double calcularCustoProd(MateriasPLD *materia, MateriaPrima *raiz); // Calcula o custo de produção de um produto com base nas matérias-primas
double custoDeVenda(double custoDeProd, double margemLucro); // Calcula o preço de venda com base no custo e margem de lucro
void produtoSolicitado(int codigoProduto, Produto *produto, MateriaPrima *raiz); // Exibe os dados detalhados de um produto específico
void alterarProduto(Produto *lista, int codigo, const char *novoNome, double novaMargem); // Altera os dados de um produto

#endif // PRODUTOSLDE_H_INCLUDED
