#include <stdio.h>
#include <stdlib.h>

/*
El propósito de este programa es leer una matriz en un archivo,
siendo la primera línea 2 números enteros que representan la cantidad
de filas y columnas respectivamente y el resto del archivo siendo
la matriz en sí, para luego crear otra matriz que sea la misma 
matriz leída pero transpuesta, y finalmente retornar esta matriz 
en otro archivo
*/

int main(int argc, char* argv[]){
	int filas, columnas, i, j, aux;
	FILE* archivo;
	printf("Abriendo archivo: %s\n", argv[1]);
	archivo = fopen(argv[1], "r");
	if (archivo == NULL){
		printf("No se ha podido abrir el archivo: %s\n", argv[1]);
		return 1;
	}
	printf("Leyendo matriz...");
	fscanf(archivo, "%d%d", &filas, &columnas);
	printf("Las filas de la matriz son: %d, y sus columnas: %d\n", filas, columnas);
	int** matriz = (int**)malloc(filas * sizeof(int));
	for (i=0; i<filas; i++){
		matriz[i] = (int*)malloc(columnas * sizeof(int));
		if (matriz == NULL || matriz[i] == NULL){
			printf("Error al alocar la matriz");
			return 1;
		}
		printf("[");
		for (j=0; j<columnas; j++){
			fscanf(archivo, "%d", &matriz[i][j]);
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
	fclose(archivo);
	printf("Lectura de la matriz exitosa. Creando archivo con matriz transpuesta...\n");
	FILE* output;
	output = fopen(argv[2], "w");
	if (output == NULL){
		printf("No se ha podido abrir el archivo: %s\n", argv[2]);
		return 1;
	}
	if (output == NULL){
		printf("No se ha podido crear el archivo");
		return 1;
	}
	int** matrizT = (int**)malloc(filas * sizeof(int));
	for (i=0; i<columnas; i++){
		matrizT[i] = (int*)malloc(columnas * sizeof(int));
		if (matrizT == NULL || matrizT[i] == NULL){
			printf("Error al alocar la matriz");
			return 1;
		}
		printf("[");
		fprintf(output, "[");
		for (j=0; j<filas; j++){
			aux = matriz[j][i];
			matrizT[i][j] = aux;
			fprintf(output, "%d ", aux);
			printf("%d ", aux);
		}
		printf("]\n");
		fprintf(output, "]\n");
	}
	printf("Creacion del archivo %s exitoso. Terminando programa...\n", argv[2]);
	fclose(output);
	for (i=0; i<filas; i++){
		free(matriz[i]);
		free(matrizT[i]);
	}
	free(matriz);
	free(matrizT);
	printf("Procedimiento exitoso.");
	return 0;
}