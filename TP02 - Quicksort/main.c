#include <stdio.h>
#include <string.h>
#include <locale.h>

// Função para trocar dois elementos de um vetor de strings
void trocar(char *arr[], int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Função Quicksort
void quicksort(char *arr[], int esquerda, int direita, int *comparacoes, int *trocas) {
    if (esquerda < direita) {
        // Escolher um pivô (aqui, escolhemos o elemento do meio)
        int meio = (esquerda + direita) / 2;
        char *pivot = arr[meio];

        // Particionar o vetor
        int i = esquerda;
        int j = direita;
        while (i <= j) {
            while (strcmp(arr[i], pivot) < 0) {
                (*comparacoes)++;
                i++;
            }
            while (strcmp(arr[j], pivot) > 0) {
                (*comparacoes)++;
                j--;
            }
            if (i <= j) {
                trocar(arr, i, j);
                (*trocas)++;
                i++;
                j--;
            }
        }

        // Recursivamente ordenar as partições esquerda e direita
        quicksort(arr, esquerda, j, comparacoes, trocas);
        quicksort(arr, i, direita, comparacoes, trocas);
    }
}

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparacoes = 0;
    int trocas = 0;

    // Ordenar o vetor usando Quicksort
    quicksort(arr, 0, 19, &comparacoes, &trocas);

    // Mostrar o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < 20; i++) {
        printf("%s\n", arr[i]);
    }

    // Gerar um arquivo de saída
    FILE *arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        fprintf(arquivoSaida, "%s\n", arr[i]);
    }

    fclose(arquivoSaida);

    // Calcular a mediana
    char *mediana = arr[9]; // A mediana está na posição 10 do vetor ordenado

    printf("\nMediana: %s\n", mediana);
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);

    return 0;
}

