#include "lib.h"

void menuPrincipal()
{
  printf("========= MENU ================\n");
  printf("(1) Adicionar Produto\n");
  printf("(2) Adicionar Materia-Prima\n");
  printf("(3) Listar Produtos\n");
  printf("(4) Listar Materias-Prima\n");
  printf("(5) Buscar Produto\n");
  printf("(0) Sair\n");
  printf("===============================");
}

void menuSecundario()
{ // este menu aparece quando as op 3, 4 e 5 são esclhidas
  printf("===============================");
  printf("(6) Excluir\n");
  printf("(7) Alterar\n");
  printf("(0) Sair\n");
  printf("===============================");
}

void limparTela()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int getOpcao()
{
  int op, flag;
  do{
    printf("Digite uma opcao (numero): ");
    flag = scanf("%d", &op);
    while(getchar() != '\n');
  } while(flag != 1);
  return op;
}

void opcaoHandler(int opcao)
{
  switch(opcao)
  {
    case 1: // add produto
      Produto *novoProduto = criarProduto();
      inserirProduto(&listaProdutos, novoProduto);
      break;
    case 2: // add MatPrima
      MatPrima *novaMatPrima = novoNo();
      inserirArvore()
      break;
    case 3: // listar produtos
      imprimirProdutos(listaProdutos);
      menuSecundario();
      opcao = getOpcao();
      opcaoHandler2(opcao);
      break;
    case 4: // listar materias-prima
      break;
    case 5: // buscar produto
      break;
    default:
      printf("Opcao invalida\n");
      break;
  }
}

void opcaoHandler2(int opcao)
{
switch(opcao)
{
  case 6:
      break;
  case 7:
      break;
  }
}

unsigned int gerarCodigo(char *str) // recebe uma string e retorna um codigo/hash
{
  unsigned int hash = 0;
  int c;
  while((c = *str++))
    hash = hash * 31 + c;
  return hash;
}

float calcularPrecoVenda(float margemLucro, MatProduto *listaMateriais);


float calcularPrecoCusto(MatProduto* listaMateriais)
{
  
}

int max(int a, int b); // Retorna o maior entre dois inteiros               


void esperar()
{
  printf("Pressione Enter <-' para continuar...");
  while(getchar() != '\n');
  getchar();
}
