// main.c
#include "matriz.h"

int main(void) {
    Matriz A, B, C;
    FILE *arquivoA, *arquivoB;

    arquivoA = fopen("matrizA.txt", "r");
    arquivoB = fopen("matrizB.txt", "r");

    if (arquivoA == NULL || arquivoB == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    A = leMatriz(arquivoA);
    fclose(arquivoA);

    printf("\nMatriz A:\n");
    imprimeMatriz(A);

    B = leMatriz(arquivoB);
    fclose(arquivoB);

    printf("\nMatriz B:\n");
    imprimeMatriz(B);

    C = somaMatrizes(A, B);
    printf("\nMatriz resultante da soma (C = A + B):\n");
    imprimeMatriz(C);

    // Outros testes podem ser adicionados aqui...

    return 0;
}
