#include <stdio.h>

void nombreEpico(int A[], int w, int n){
	int i = 0;
	int aux;
	while (i<w){
		for (int j=0; j<n-1; j++){
			aux = A[j+1];
			A[j+1] = A[j];
			A[j] = aux;
		}
		i++;
	}
}

void imprimir_arreglo(int arreglo[], int largo){

	 for (int i = 0; i < largo; i++){
	 
		printf("%d,", arreglo[i]);
	 
	 }
}

int main(){
	int A[] = {6, 5, 3, 4, 2, 0};
	int n = 6;
	int w = 2;
	nombreEpico(A, w, n);
	imprimir_arreglo(A, n);
	return 0;
}