#include <stdio.h>
int cantElementos(int A[], int B[], int largoA, int largoB){
	int contador = 0;
	int check = 0;
	for (int i=0; i<largoA; i++){
		for (int j=0; j<largoB; j++){
			if (B[j] == A[i]){
				if (check == 1){
					B[j] = -1;
				}else{
					contador++;
					check = 1;
					B[j] = -1;
				}
			}
		}
		check = 0;
	}
	return contador;
}
int main(){
	int B[] = {1,6,2,0,0,0,7,2,2,2,2};
	int A[] = {0,1,2,3,4,5,2,2,2};
	int algo = cantElementos(A, B, 9, 11);
	printf("%d",algo);
	return 0;
}