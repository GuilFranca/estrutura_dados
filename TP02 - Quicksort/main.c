#include <stdio.h>
#include <string.h>
#include <locale.h>

// Fun��o para trocar dois elementos de um vetor de strings
void trocar(char *arr[], int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Fun��o Quicksort
void quicksort(char *arr[], int esquerda, int direita, int *comparacoes, int *trocas) {
    if (esquerda < direita) {
        // Escolher um piv� (aqui, escolhemos o elemento do meio)
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

        // Recursivamente ordenar as parti��es esquerda e direita
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

    // Gerar um arquivo de sa�da
    FILE *arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de sa�da.\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        fprintf(arquivoSaida, "%s\n", arr[i]);
    }

    fclose(arquivoSaida);

    // Calcular a mediana
    char *mediana = arr[9]; // A mediana est� na posi��o 10 do vetor ordenado

    printf("\nMediana: %s\n", mediana);
    printf("N�mero de compara��es: %d\n", comparacoes);
    printf("N�mero de trocas: %d\n", trocas);

    return 0;
}

