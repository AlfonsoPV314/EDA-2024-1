#include <stdio.h>

void darVuelta(int arreglo[], int largo){

	int indice = 0;
	int stop = 0;
	while (stop == 0){
	
		if (indice >= largo/2){
		
			stop = 1;
		
		}else{
		
			int aux = arreglo[indice];
			arreglo[indice] = arreglo[largo - 1 - indice];
			arreglo[largo - 1 - indice] = aux;
		
		}
		indice += 1;
	
	}

}

void imprimir_arreglo(int arreglo[], int largo){

	 for (int i = 0; i < largo; i++){
	 
		printf("%d", arreglo[i]);
	 
	 }

}


int main(){

	int arreglo[] = {0,1,2,3,4,5,6};
	int largo = 7;
	darVuelta(arreglo, largo);
	imprimir_arreglo(arreglo, largo);
	return 0;

}