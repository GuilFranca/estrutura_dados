#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    char nome_arquivo_entrada[100], nome_arquivo_saida[100];
    char caractere;
    int dentro_tag = 0;

    printf("Digite o nome do arquivo HTML de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nome_arquivo_saida);

    arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao abrir o arquivo de saida");
        return 1;
    }

    while ((caractere = fgetc(arquivo_entrada)) != EOF) {
        if (caractere == '<') {
            dentro_tag = 1;
        } else if (caractere == '>') {
            dentro_tag = 0;
        } else if (!dentro_tag) {
            fputc(caractere, arquivo_saida);
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Tags HTML removidas com sucesso. O texto foi salvo em \"%s\".\n", nome_arquivo_saida);

    return 0;
}
