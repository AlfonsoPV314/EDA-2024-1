#include <stdio.h>

void divDiezmilesima(int a, int b){
	if (a==b){
		return 1;
	}else if (a>b){
		int check = 0;
		int c = a*10000;
		float i = 0.0;
		while (i<c && check == 0){
			if (i*b == a){
				printf("%d", a/b);
			}else if ((i+1)*b>c){
				s;	//tengo a i, que es el numero que quiero pero tengo que dividirlo entre 10000
			}
			i++;
		}
	}
}
int main(){
	int a = 90;
	int b = 7;
	divDiezmilesima(a,b);
	return 0;
}