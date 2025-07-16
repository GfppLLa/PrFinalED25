#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/Estruturas.h"
#include "../Bibliotecas/ProdutosLDE.h"
#include "../Bibliotecas/MateriasPLD.h"
#include "../Bibliotecas/MateriaPARVOREAVL.h"
#include "../Bibliotecas/Arquivos.h"
#include "../Bibliotecas/Menu.h"

int main() {
    Produto *produtos = NULL;
    MateriaPrima *materias = NULL;
    FILE *arq;
    char buffer[150];
    int opcao;

    // Carregamento dos arquivos
    arq = fopen("../ARQUIVOS/materias_primas.csv", "r");
    if (arq) {
        if (fgets(buffer, sizeof(buffer), arq)) {
            materias = salvarMateriasArq(arq, materias);
        }
        fclose(arq);
    }

    arq = fopen("../ARQUIVOS/produtos.csv", "r");
    if (arq) {
        if (fgets(buffer, sizeof(buffer), arq)) {
            produtos = salvarInfoArq(arq, produtos);
        }
        fclose(arq);
    }

    arq = fopen("../ARQUIVOS/materias_produto.csv", "r");
    if (arq) {
        if (fgets(buffer, sizeof(buffer), arq)) {
            carregarMateriasDosProdutos(arq, produtos);
        }
        fclose(arq);
    }

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                menuProdutos(&produtos, materias);
                break;
            case 2:
                menuMaterias(&materias);
                break;
            case 3:
                imprimirProdutos(produtos, materias);
                break;
            case 4:
                imprimirEmOrdem(materias);
                break;
            case 0:
                salvarTodos(produtos, materias);
                printf("Dados salvos. Encerrando programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
