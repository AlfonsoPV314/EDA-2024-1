#include <stdio.h>
#include <stdlib.h>

/*
El propósito de este programa es leer 2 archivos que contienen 2 
matrices, con la primera línea siendo la cantidad de filas y columnas 
y el resto del archivo siendo la matriz en sí, sumar ambas matrices 
y escribir la matriz resultante en otro archivo de texto
*/

/*

void leerMatriz(char* num){
	FILE* archivo;
	int i, j, filas, columnas;
	printf("Abrir archivo %s\n", num);
	archivo = fopen(num,"r");
	if(archivo == NULL){
		printf("Error al abrir archivo %s\n",num);
	}
	
	fscanf(archivo, "%d%d", &filas, &columnas);
	printf("Las filas de la matriz son: %d, y sus columnas: %d\n", filas, columnas);
	int** matriz = (int**)malloc(filas * sizeof(int*));
	for (i=0; i<filas; i++){
		matriz[i] = (int*)malloc(columnas * sizeof(int));
		if (matriz == NULL || matriz[i] == NULL){
			printf("Error al alocar la matriz");
		}
		printf("[");
		for (j=0; j<columnas; j++){
			fscanf(archivo, "%d", &matriz[i][j]);
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
	
	fclose(archivo);
	for (i=0; i<filas; i++){
		free(matriz[i]);
	}
	free(matriz);
}

int main(int argc, char* argv[]){
	char* uno = argv[1];
	leerMatriz(uno);
	char* dos = argv[2];
	leerMatriz(dos);
	
	return 0;

*/

int main(int argc, char* argv[]){
	FILE* archivo;
	int i, j, filas1, filas2, filas3, columnas1, columnas2, columnas3, aux;
	printf("Abrir archivo %s\n", argv[1]);
	archivo = fopen(argv[1],"r");
	if(archivo == NULL){
		printf("Error al abrir archivo %s\n",argv[1]);
		return 0;
	}
	
	fscanf(archivo, "%d%d", &filas1, &columnas1);
	printf("Las filas de la matriz son: %d, y sus columnas: %d\n", filas1, columnas1);
	int** matriz = (int**)malloc(filas1 * sizeof(int*));
	for (i=0; i<filas1; i++){
		matriz[i] = (int*)malloc(columnas1 * sizeof(int));
		if (matriz == NULL || matriz[i] == NULL){
			printf("Error al alocar la matriz");
			return 0;
		}
		printf("[");
		for (j=0; j<columnas1; j++){
			fscanf(archivo, "%d", &matriz[i][j]);
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
	
	fclose(archivo);
	
	FILE* archivo2;
	printf("Abrir archivo %s\n", argv[2]);
	archivo2 = fopen(argv[2],"r");
	if(archivo2 == NULL){
		printf("Error al abrir archivo %s\n",argv[2]);
	}
	
	fscanf(archivo2, "%d%d", &filas2, &columnas2);
	printf("Las filas de la matriz son: %d, y sus columnas: %d\n", filas2, columnas2);
	int** matriz2 = (int**)malloc(filas2 * sizeof(int*));
	for (i=0; i<filas2; i++){
		matriz2[i] = (int*)malloc(columnas2 * sizeof(int));
		if (matriz2 == NULL || matriz2[i] == NULL){
			printf("Error al alocar la matriz");
		}
		printf("[");
		for (j=0; j<columnas2; j++){
			fscanf(archivo2, "%d", &matriz2[i][j]);
			printf("%d ", matriz2[i][j]);
		}
		printf("]\n");
	}
	
	fclose(archivo2);
	
	if (filas1 != filas2 || columnas1 != columnas2){
		printf("No ha sido posible realizar la suma");
		return 0;
	filas3 = filas1;
	columnas3 = columnas1;
	FILE* archivo3;
	printf("Abrir archivo %s\n", argv[3]);
	archivo3 = fopen(argv[3],"w");
	if(archivo3 == NULL){
		printf("Error al abrir archivo %s\n",argv[3]);
		return 0;
	}
	for (i=0; i<filas3; i++){
		printf("[");
		fprintf(archivo3, "[");
		for (j=0; j<columnas3; j++){
			aux = matriz[i][j] + matriz2[i][j];
			fprintf(archivo3, "%d ", aux);
			printf("%d ", aux);
		}
		printf("]\n");
		fprintf(archivo3, "]\n");
	}
	
	fclose(archivo3);
	
	for (i=0; i<filas1; i++){
		free(matriz[i]);
	}
	for (i=0; i<filas2; i++){
		free(matriz2[i]);
	}
	free(matriz);
	free(matriz2);
	return 0;
}
