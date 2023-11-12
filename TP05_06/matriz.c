// matriz.c
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaCabeca(Matriz *matriz) {
    Celula *cabeca = (Celula *)malloc(sizeof(Celula));
    cabeca->direita = cabeca->abaixo = cabeca;
    cabeca->linha = cabeca->coluna = -1;
    cabeca->valor = 0.0;
    matriz->cabeca = cabeca;
}

Matriz criaMatriz(int nlin, int ncol) {
    Matriz matriz;
    matriz.nlin = nlin;
    matriz.ncol = ncol;
    inicializaCabeca(&matriz);

    return matriz;
}

void insereElemento(Matriz *matriz, int linha, int coluna, float valor) {
    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    novaCelula->linha = linha;
    novaCelula->coluna = coluna;
    novaCelula->valor = valor;

    Celula *atual = matriz->cabeca;

    while (atual->direita != matriz->cabeca && atual->direita->coluna < coluna) {
        atual = atual->direita;
    }

    novaCelula->direita = atual->direita;
    atual->direita = novaCelula;

    atual = matriz->cabeca;

    while (atual->abaixo != matriz->cabeca && atual->abaixo->linha < linha) {
        atual = atual->abaixo;
    }

    novaCelula->abaixo = atual->abaixo;
    atual->abaixo = novaCelula;
}

void imprimeMatriz(Matriz A) {
    Celula *linhaAtual = A.cabeca->abaixo;

    while (linhaAtual != A.cabeca) {
        Celula *celulaAtual = linhaAtual->direita;

        while (celulaAtual != linhaAtual) {
            printf("(%d, %d): %.2f\t", celulaAtual->linha, celulaAtual->coluna, celulaAtual->valor);
            celulaAtual = celulaAtual->direita;
        }

        printf("\n");
        linhaAtual = linhaAtual->abaixo;
    }
}

Matriz leMatriz(FILE *arquivo) {
    int nlin, ncol;
    fscanf(arquivo, "%d, %d", &nlin, &ncol);

    Matriz matriz = criaMatriz(nlin, ncol);

    int i, j;
    float valor;

    while (fscanf(arquivo, "%d, %d, %f", &i, &j, &valor) == 3) {
        insereElemento(&matriz, i - 1, j - 1, valor);
    }

    return matriz;
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz resultado = criaMatriz(A.nlin, A.ncol);

    Celula *celulaA = A.cabeca->abaixo;
    Celula *celulaB = B.cabeca->abaixo;

    while (celulaA != A.cabeca || celulaB != B.cabeca) {
        if (celulaA == A.cabeca || (celulaB != B.cabeca && celulaB->linha < celulaA->linha)) {
            insereElemento(&resultado, celulaB->linha, celulaB->coluna, celulaB->valor);
            celulaB = celulaB->abaixo;
        } else if (celulaB == B.cabeca || (celulaA != A.cabeca && celulaA->linha < celulaB->linha)) {
            insereElemento(&resultado, celulaA->linha, celulaA->coluna, celulaA->valor);
            celulaA = celulaA->abaixo;
        } else {
            insereElemento(&resultado, celulaA->linha, celulaA->coluna, celulaA->valor + celulaB->valor);
            celulaA = celulaA->abaixo;
            celulaB = celulaB->abaixo;
        }
    }

    return resultado;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    // Implemente a multiplicação de matrizes aqui
    // Certifique-se de lidar corretamente com as dimensões das matrizes
    Matriz resultado = criaMatriz(A.nlin, B.ncol);

    // Preencha a lógica para multiplicação de matrizes aqui

    return resultado;
}
