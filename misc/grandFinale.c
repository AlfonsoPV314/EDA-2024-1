#include <stdio.h>

int grandFinale(int A[], int largoA, int largoB, int dato){
	int index;
	for (int i=0; i<largoA; i++){
		if (dato>=A[i]){
			index = i;
		}
	}
	int B[largoB];
	int aux;
	for (int i=0; i<largoB; i++){
		if (i==index){
			B[i] = dato;
			B[i+1] = A[i];
			aux++;
		}else{
			B[i] = A[i + aux];
		}
	}
	return B;
}

void imprimir_arreglo(int arreglo[], int largo){

	 for (int i = 0; i < largo; i++){
	 
		printf("%d,", arreglo[i]);
	 
	 }
}

int main(){
	int A[]={0,1,2,3};
	int B = grandFinale(A, 4, 5, 4);
	imprimir_arreglo(B);
	return 0;
}

//tengo que usar punteros :^(