#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Point;

int main() {
	
    FILE *file;
    int numVertices, i;
    float area = 0.0;
    
    // Abre o arquivo para leitura
    file = fopen("vertices.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    // L� o n�mero de v�rtices
    fscanf(file, "%d", &numVertices);
    
    // Aloca espa�o para armazenar os v�rtices
    Point *vertices = (Point *)malloc(numVertices * sizeof(Point));
    if (vertices == NULL) {
        perror("Erro ao alocar mem�ria");
        fclose(file);
        return 1;
    }
    
    // L� as coordenadas dos v�rtices
    for (i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].x, &vertices[i].y);
    }
    
    // Fecha o arquivo
    fclose(file);
    
    // Calcula a �rea do pol�gono usando a f�rmula de Shoelace
    for (i = 0; i < numVertices - 1; i++) {
        area += (vertices[i].x * vertices[i+1].y - vertices[i+1].x * vertices[i].y);
    }
    area += (vertices[numVertices-1].x * vertices[0].y - vertices[0].x * vertices[numVertices-1].y);
    area = fabsf(area) / 2.0;
    
    // Exibe a �rea do pol�gono
    printf("A area do poligono e %.2f\n", area);
    
    // Libera a mem�ria alocada
    free(vertices);
    
    return 0;
}
