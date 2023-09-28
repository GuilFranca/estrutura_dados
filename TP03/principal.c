#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE *arquivo;
    int numVertices;
    
    arquivo = fopen("trianguloABC.txt", "r"); 
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    
    fscanf(arquivo, "%d", &numVertices);
    
    if (numVertices < 3) {
        printf("O pol�gono deve ter pelo menos 3 v�rtices.\n");
        fclose(arquivo);
        return 1;
    }
    
    Ponto *pontos = (Ponto *)malloc(numVertices * sizeof(Ponto));
    
    if (pontos == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        fclose(arquivo);
        return 1;
    }
    
    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
    }
    
    fclose(arquivo);
    
    float area = calcularAreaPoligono(pontos, numVertices);
    
    printf("A �rea do pol�gono � %.2f\n", area);
    
    free(pontos);
    
    return 0;
}
