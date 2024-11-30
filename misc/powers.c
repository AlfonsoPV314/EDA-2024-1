#include <stdio.h>

/*

The purpose of this thing is to write on screen all the perfect squares 
using a recursive function, from an input value to another input value (top)

*/

int powers(int tope, int inicio){

	while (inicio<tope){
		
		printf("%d ", inicio);
		inicio = inicio * inicio;
	
	}
	return inicio;

}

//Iterativa, no recursiva^^^^

int main(){

	int input1;
	
	printf("User input: ");
	
	scanf("%d", &input1);
	
	int input2;
	
	printf("\nUser input: ");
	
	scanf("\n%d", &input2);
	
	printf("%d",powers(input1, input2));
	
	return 0;

}