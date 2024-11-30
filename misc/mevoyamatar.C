#include <stdio.h>

void mataRepetidos(int A[], int largo){
	for (int i=0; i<largo; i++){
		if (A[i] != -1){
			for (int j=i+1; j<largo; j++){
				if (A[i] == A[j]){
					A[j] = -1;
				}
			}
		}
	}
}

int verIndex(int A[], int largo){
	int i = 0;
	int desde = 0;
	int stop = 0;
	while (stop == 0){
		if (A[i] == -1 || i == largo){
			desde = i;
			stop = 1;
		}
		i++;
	}
	return desde;
}

void concatenarArreglos(int A[], int B[], int n, int largoA, int largoB){
	int verificador = 0;
	for (int i=0; i<largoB; i++){
		for (int j=0; j<largoA; j++){
			if (B[i]==A[j]){
				verificador = 1;
			}
		}
		if (verificador==0){
			A[n] = B[i];
			n++;
		}
		verificador = 0;
	}
}
void imprimir_arreglo(int arreglo[], int largo){

	 for (int i = 0; i < largo; i++){
	 
		printf("%d,", arreglo[i]);
	 
	 }
}
int main(){
	int A[] = {0,0,1,1,2,2,3,3};
	int B[] = {0,1,10,4,5};
	int C[] = {2,3,3,19,7,22,7};
	int largoA = 8;
	int largoB = 5;
	int largoC = 7;
	mataRepetidos(A, largoA);
	for (int i=0; i<largoA; i++){
		for (int j=0; j<largoA-i-1; j++){
			if (A[j]==-1){
				int aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
			}
		}
	}
	int n = verIndex(A, largoA);
	concatenarArreglos(A, B, n, largoA, largoB);
	int m = verIndex(A, largoA);
	concatenarArreglos(A, C, m, largoA, largoC);
	imprimir_arreglo(A, largoA);
	return 0;
}

//casi sirve! no concatena el 22 en este caso específico, no sé por qué.