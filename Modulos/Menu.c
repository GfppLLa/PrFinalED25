#include "../Bibliotecas/Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/Estruturas.h"
#include "../Bibliotecas/ProdutosLDE.h"
#include "../Bibliotecas/MateriasPLD.h"
#include "../Bibliotecas/MateriaPARVOREAVL.h"

void menu() {
    printf("\n==== SISTEMA FABRICA ====\n");
    printf("1. Gerenciar Produtos\n");
    printf("2. Gerenciar Materias-Primas\n");
    printf("3. Listar todos os produtos\n");
    printf("4. Listar todas as materias-primas\n");
    printf("5. Buscar produto\n");
    printf("0. Salvar e sair\n");
}

void menuProdutos(Produto **produtos, MateriaPrima *materias) {
    int opcao, codProd, codMat, qtd;
    double margem;
    char nome[100];

    do {
        printf("\n-- MENU PRODUTOS --\n");
        printf("1. Inserir produto\n");
        printf("2. Alterar produto\n");
        printf("3. Excluir produto\n");
        printf("4. Adicionar/Substituir materia-prima em produto\n");
        printf("5. Remover materia-prima do produto\n");
        printf("6. Buscar produto (exibir detalhes)\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Codigo do produto: ");
                scanf("%d", &codProd);
                getchar();
                printf("Nome do produto: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Margem de lucro: ");
                scanf("%lf", &margem);
                *produtos = inserirProdutoOrdenado(*produtos, codProd, nome, margem);
                printf("Produto inserido.\n");
                break;
            case 2:
                printf("Codigo do produto: ");
                scanf("%d", &codProd);
                getchar();
                printf("Novo nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Nova margem de lucro: ");
                scanf("%lf", &margem);
                alterarProduto(*produtos, codProd, nome, margem);
                break;
            case 3:
                printf("Codigo do produto a excluir: ");
                scanf("%d", &codProd);
                *produtos = excluirProduto(*produtos, codProd);
                printf("Produto excluido.\n");
                break;
            case 4:
                printf("Codigo do produto: ");
                scanf("%d", &codProd);
                printf("Codigo da materia-prima: ");
                scanf("%d", &codMat);
                printf("Quantidade: ");
                scanf("%d", &qtd);
                adicionarOuSubstituirMateriaProduto(*produtos, codProd, codMat, qtd);
                break;
            case 5:
                printf("Codigo do produto: ");
                scanf("%d", &codProd);
                printf("Codigo da materia-prima a remover: ");
                scanf("%d", &codMat);
                removerMateriaDoProduto(*produtos, codProd, codMat);
                break;
            case 6:
                printf("Digite o codigo do produto para buscar: ");
                scanf("%d", &codProd);
                getchar();
                produtoSolicitado(codProd, *produtos, materias);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}


void menuMaterias(MateriaPrima **materias){
    int opcao, cod;
    double preco;
    char nome[100];

    do {
        printf("\n-- MENU MATERIAS-PRIMAS --\n");
        printf("1. Inserir materia-prima\n");
        printf("2. Alterar materia-prima\n");
        printf("3. Excluir materia-prima\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar o \n do buffer

        switch(opcao) {
            case 1:
                printf("Codigo da materia-prima: ");
                scanf("%d", &cod);
                getchar();
                printf("Nome da materia-prima: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Preco: ");
                scanf("%lf", &preco);
                *materias = inserirMateria(*materias, cod, nome, preco);
                printf("Materia-prima inserida.\n");
                break;
            case 2:
                printf("Codigo da materia-prima: ");
                scanf("%d", &cod);
                getchar();
                printf("Novo nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Novo preco: ");
                scanf("%lf", &preco);
                alterarMateriaPrima(*materias, cod, nome, preco);
                break;
            case 3:
                printf("Codigo da materia-prima a excluir: ");
                scanf("%d", &cod);
                *materias = excluirMateria(*materias, cod);
                printf("Materia-prima excluida.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}


