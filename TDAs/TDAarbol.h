#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"

//AUTOR: Alfonso Sebastian Palacios Vergara, Ingeniería Civil Informática USACH - 3er semestre, 2024. Estructuras de Datos.

/*------------- estructuras de datos -------------*/
typedef struct nodoABO{
	int dato;
	struct nodoABO* izq;
	struct nodoABO* der;
}NodoABO;

typedef struct arbolBinOrd{
  NodoABO* raiz;
}ABO;

//___________________________________________________________________________________________________________________________________

/*----------------------- llamados -----------------------*/

ABO* crearABO();
NodoABO* crearNodoABO(int val);
NodoABO* insertar(NodoABO* aux, int val); //no es void
int esHoja(NodoABO* aux);
NodoABO* buscar(NodoABO* aux, int val);
NodoABO* buscarPadre(NodoABO* aux, int val);
int queHijoEs(NodoABO* padre, int val);
void preOrden(NodoABO* n);
void inOrden(NodoABO* n);
void postOrden(NodoABO* n);
NodoABO* eliminar(NodoABO* aux, int val);
int calcularAltura(NodoABO* n);

//___________________________________________________________________________________________________________________________________

/*----------------------- operaciones -----------------------*/

NodoABO* crearNodoABO(int val){
	NodoABO* nodoNvo=(NodoABO*)malloc(sizeof(NodoABO));
	nodoNvo->dato=val;
	nodoNvo->izq=NULL;
	nodoNvo->der=NULL;
	return nodoNvo;
}

ABO* crearABO(){
	ABO* a=(ABO*)malloc(sizeof(ABO));
	a->raiz=NULL;
	return a;
}

NodoABO* insertar(NodoABO* aux, int val){	//insertas en el nodo raíz (si tienes un Arbol* T, llamas con T->raiz)
	if (aux == NULL){
		return crearNodoABO(val);
	}else{
		if (val<=aux->dato){	//valor menor que el dato, avanza por izquierda
			aux->izq = insertar(aux->izq, val);
			
		}else{		//valor mayor que el dato, crea en el lado derecho
			aux->der = insertar(aux->der, val);
		}
	}
	return aux;
}

int esHoja(NodoABO* aux){
	if (aux->izq == NULL && aux->der == NULL){
		return 1;
	}
	return 0;
}

NodoABO* buscar(NodoABO* aux, int val){		//lo mismo acá
	if (aux == NULL){
		return NULL;
	}else{
		if (val == aux->dato){
			return aux;
		}else{
			if (val < aux->dato){
				return buscar(aux->izq, val);
			}else{
				return buscar(aux->der, val);
			}
		}
	}
}

NodoABO* buscarPadre(NodoABO* aux, int val){		//lo mismo acá
	if (aux == NULL || (aux->der == NULL && aux->izq == NULL)){
		return NULL;
	}else{
		if (aux->izq != NULL){
			if (val == aux->izq->dato){
				return aux;
			}
		}
		if (aux->der != NULL){
			if (val == aux->der->dato){
				return aux;
			}
		}
		if (val < aux->dato){
			return buscarPadre(aux->izq, val);
		}else{
			return buscarPadre(aux->der, val);
		}
	}
}

int queHijoEs(NodoABO* padre, int val){
	if (padre == NULL){
		return 0;
	}else if (padre->izq == NULL && padre->der == NULL){
		return 0;
	}else if (padre->izq != NULL){		//1 = izquierdo
		if (padre->izq->dato == val){
			return 1;
		}
	}else if (padre->der != NULL){		//2 = derecho
		if (padre->der->dato == val){
			return 2;
		}
	}
	return 0;
}

void preOrden(NodoABO* n){		//lo mismo en todas lol
	if (n == NULL){
		return;
	}
	if (esHoja(n) == 1){
		printf("%d, ", n->dato);
	}else{
		printf("%d, ", n->dato);
		preOrden(n->izq);
		preOrden(n->der);
	}
}

void inOrden(NodoABO* n){
	if (n == NULL){
		return;
	}
	if (esHoja(n) == 1){
		printf("%d, ", n->dato);
	}else{
		inOrden(n->izq);
		printf("%d, ", n->dato);
		inOrden(n->der);
	}
	return;
}

void postOrden(NodoABO* n){
	if (n == NULL){
		return;
	}
	if (esHoja(n) == 1){
		printf("%d, ", n->dato);
	}else{
		postOrden(n->izq);
		postOrden(n->der);
		printf("%d, ", n->dato);
	}
	return;
}


NodoABO* eliminar(NodoABO* aux, int val){
	if (aux == NULL){
		return NULL;
	}else{
		NodoABO* padre = buscarPadre(aux, val);
		NodoABO* output = buscar(aux, val);
		if (esHoja(output) == 1){		//si es hoja
			if (queHijoEs(padre, val) == 1){	//si el nodo a eliminar esta a la izquierda
				padre->izq = NULL;
				return output;
			}else{								//si el nodo a eliminar esta a la derecha
				padre->der = NULL;
				return output;
			}
		}else if (output->izq == NULL){
			if (queHijoEs(padre, val) == 1){
				padre->izq = buscar(aux, val)->der;
				return output;
			}else{
				padre->der = buscar(aux, val)->der;
				return output;
			}
		}else if (output->der == NULL){
			if (queHijoEs(padre, val) == 1){
				padre->izq = buscar(aux, val)->izq;
				return output;
			}else{
				padre->der = buscar(aux, val)->izq;
				return output;
			}
		}else{
			NodoABO* aux1 = output->der;
			while (aux1->izq != NULL){
				aux1 = aux1->izq;
			}
			output->dato = aux1->dato;
			aux1->dato = val;
			return eliminar(output->der, val);
		}
	}
}

int max(int x, int y){
	if (x <= y){
		return y;
	}
	return x;
}

int calcularAltura(NodoABO* n){
	if (esHoja(n) == 1){
		return 0;
	}else{
		int x = -1;
		int y = -1;
		if (n->izq != NULL){
			x = calcularAltura(n->izq);
		}
		if (n->der != NULL){
			y = calcularAltura(n->der);
		}
		return 1 + max(x, y);
	}
}

int calcular_FE(NodoABO* n){
	if (esHoja(n) == 1){
		return 0;
	}else if (n->izq == NULL){
		return calcularAltura(n->der);
	}else if (n->der == NULL){
		return calcularAltura(n->izq);
	}
	return calcularAltura(n->izq) - calcularAltura(n->der);
}

void rotacionDer(ABO* T, int val){		//Se llama con el ARBOL, no con su raiz
	NodoABO* actual = buscar(T->raiz, val);
	NodoABO* padre = buscarPadre(T->raiz, val);
	if (actual->der == NULL){
		if (padre->dato != T->raiz->dato){
			NodoABO* abuelo = buscarPadre(T->raiz, padre->dato);
			abuelo->der = actual;
			actual->der = padre;
			padre->izq = NULL;
		}else{
			T->raiz = actual;
			T->raiz->der = padre;
			padre->izq = NULL;
		}
	}else{
		NodoABO* hijoDer = actual->der;
		if (padre->dato != T->raiz->dato){
			NodoABO* abuelo = buscarPadre(T->raiz, padre->dato);
			NodoABO* aux;
			abuelo->der = actual;
			actual->der = padre;
			padre->izq = hijoDer;
		}else{
			T->raiz = actual;
			T->raiz->der = padre;
			padre->izq = hijoDer;
		}
	}
}

void rotacionIzq(ABO* T, int val){		//Se llama con el ARBOL, no con su raiz
	NodoABO* actual = buscar(T->raiz, val);
	NodoABO* padre = buscarPadre(T->raiz, val);
	if (actual->izq == NULL){
		if (padre->dato != T->raiz->dato){
			NodoABO* abuelo = buscarPadre(T->raiz, padre->dato);
			abuelo->izq = actual;
			actual->izq = padre;
			padre->der = NULL;
		}else{
			T->raiz = actual;
			T->raiz->izq = padre;
			padre->der = NULL;
		}
	}else{
		NodoABO* hijoIzq = actual->izq;
		if (padre->dato != T->raiz->dato){
			NodoABO* abuelo = buscarPadre(T->raiz, padre->dato);
			NodoABO* aux;
			abuelo->izq = actual;
			actual->izq = padre;
			padre->der = hijoIzq;
		}else{
			T->raiz = actual;
			T->raiz->izq = padre;
			padre->der = hijoIzq;
		}
	}
}