#include <stdio.h>
#include <stdlib.h>

//AUTOR: Alfonso Sebastian Palacios Vergara, Ingeniería Civil Informática USACH - 3er semestre 2024. Estructuras de Datos.

/* ESTRUCTURA DE DATOS*/
struct nodo{
  int info;
  struct nodo* sig;
};
typedef struct nodo Nodo;

struct lista{
  Nodo* head;
};
typedef struct lista Lista;

struct nodoDoble{
	int info;
	struct nodoDoble* sig;
	struct nodoDoble* ant;
};
typedef struct nodoDoble NodoDoble;

struct listaDoble{
	NodoDoble* head;
};
typedef struct listaDoble ListaDoble;

struct nodoPila{
	int info;
	struct nodoPila* sig;
};
typedef struct nodoPila NodoPila;

struct pila{
	NodoPila* top;
};
typedef struct pila Pila;

typedef struct nodoCola{
	int info;
	struct nodoCola* sig;
}NodoCola;

typedef struct cola{
	NodoCola* front;
	NodoCola* rear;
	int n;
}Cola;

/*_____________Funciones______________*/

//Lista* algo = crearLista() ⇒   L	Crea en memoria la lista, inicializa sus datos y retorna una lista vacía.
Lista* crearLista(){
	Lista* L=(Lista*)malloc(sizeof(Lista));
	L->head=NULL;
	return L;
}

//Nodo* algo = crearNodo(val) ⇒ nodo 	Crea en memoria un nodo cuya info es val y que apunta a un nodo vacío, y lo retorna.
Nodo* crearNodo(int val){
	Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig = NULL;
	nodo->info = val;
	return nodo;
}

// int algo = esVacía(L) ⇒ V (1), F (0)	
int esVacia(Lista* L){
	Nodo* aux = L->head;
	if (aux == NULL){
		return 1;
	}else{
		return 0;
	}
}

// mostrarLista(L) 		Recorre los elementos de la lista para procesarlos 
void mostrarLista(Lista* L){
	Nodo* aux = L->head;
	int val;
	if (esVacia(L) == 1){
		printf("NULL\n");
	}else{
		printf("[");
		while (aux != NULL){
			val = aux->info;
			printf(" %d -> ", val);
			aux = aux->sig;
		}
		printf("]\n");
	}
}

// insertarInicio(L, x) 	Inserta x al inicio de la lista L. 
void insertarInicio(Lista* L, int x){
	Nodo* nuevoNodo = crearNodo(x);
	nuevoNodo->sig = L->head;
	L->head = nuevoNodo;
}

// insertarFin(L, x) 	Inserta x al final  de la lista L. 
void insertarFin(Lista* L, int x){
	if (esVacia(L) == 1){
		Nodo* nuevoNodo = crearNodo(x);
		L->head = nuevoNodo;

	}else{
		Nodo* aux = L->head;
		while (aux->sig != NULL){
			aux = aux->sig;
		}
		Nodo* nuevoNodo = crearNodo(x);
		aux->sig = nuevoNodo;
	}
}

// int algo = largoLista(L)		Cuenta los elementos de la lista L.
int largoLista(Lista* L){
	if (esVacia(L) == 1){
		return 0;
	}else{
		Nodo* aux = L->head;
		int contador = 0;
		while (aux != NULL){
			contador++;
			aux = aux->sig;
		}
		return contador;
	}
}

int sonIgualesArreglos(int* A, int* B, int n){
	for (int i=0; i<n; i++){
		if (A[i] != B[i]){
			return 0;
		}
	}
	return 1;
}

// insertarEnPos(L, p, x) 	Inserta x en la posición p (primer elemento es posición 0) de la lista L. 
void insertarEnPos(Lista* L, int p, int x){
	Nodo* aux = L->head;
	if (p == 0){
		insertarInicio(L, x);
	}else{
		int i = 0;
		while (i != p-1 && aux != NULL){
			aux = aux->sig;
			i++;
		}
		if (aux == NULL){
			printf("No se ha encontrado la posicion %d en la lista\n", p);
		}else{
			Nodo* nuevoNodo = crearNodo(x);
			nuevoNodo->sig = aux->sig;
			aux->sig = nuevoNodo;
			printf("Se ha agregado %d a la posicion %d en la lista\n", x, p);
		}
	}
}

// eliminarInicio(L) 	Elimina al inicio de la lista L. 
void  eliminarInicio(Lista* L){
	if (esVacia(L) == 1){
		printf("No hay nada que eliminar\n");
	}else{
		Nodo* aux = L->head;
		L->head = L->head->sig;
		free(aux);
	}
	
}

// eliminarFin(L) 	Elimina  al final  de la lista L. 
int  eliminarFin(Lista* L){
	if (esVacia(L) == 1){
		printf("No hay nada que eliminar\n");
		return -1;
	}else{
		Nodo* aux = L->head;
		while (aux->sig->sig != NULL){
			aux = aux->sig;
		}
		int val = aux->sig->info;
		aux->sig = NULL;
		printf("Se ha eliminado el ultimo elemento de la lista\n");
		return val;
	}
}

// eliminarElem(L, x) 	Busca elemento a eliminar y lo elimina de la lista L. Si existen más de uno, elimina el primero que encuentra. 
int eliminarElem(Lista* L, int x){
	if (esVacia(L) == 1){
		return -1;
	}else{
		Nodo* aux = L->head;
		if (aux->info == x){
			eliminarInicio(L);
		}
		while (aux->sig->info != x && aux->sig->sig != NULL){
			aux = aux->sig;
		}
		if (aux->sig == NULL){
			return -1;
		}else{
			int val = aux->sig->info;
			aux->sig = aux->sig->sig;
			free(aux->sig);
			return val;
		}
	}
}

// int algo = buscarElem(L, x) ⇒   p 	Retorna la posición del primer valor x encontrado 
int buscarElem(Lista* L, int x){
	if (esVacia(L)==1){
		printf("No se puede buscar un elemento en una lista vacía\n");
		return -1;
	}else{
		Nodo* aux = L->head;
		int contador = 0;
		while (aux != NULL && aux->info != x){
			aux = aux->sig;
			contador++;
		}
		if (aux == NULL){
			printf("No se ha encontrado el valor %d en la lista\n", x);
			return -1;
		}else{
			printf("El valor %d se encuentra en la posicion %d\n", x, contador);
			return contador;
		}
	}
}
	
// int algo = recuperarElem(L, p) ⇒   x 	Retorna el valor de la posición p en la lista L.
int recuperarElem(Lista* L, int p){
	if (esVacia(L) == 1 || p < 0){
		printf("No se puede encontrar la posición %d en la lista\n", p);
		return -1;
	}else{
		Nodo* aux = L->head;
		int contador = 0;
		while (aux != NULL && contador != p){
			aux = aux->sig;
			contador++;
		}
		if (aux == NULL){
			printf("No se puede encontrar la posición %d en la lista\n", p);
			return -1;
		}else{
			int val = aux->info;
			printf("Se ha recuperado el valor %d de la posicion %d en la lista\n", val, p);
			return val;
		}
	}
}

// invertirLista(L)		Invierte las posiciones de la lista L.
void invertirLista(Lista* L){
	if (esVacia(L) == 1){
		printf("No hay nada que invertir");
	}else{
		Nodo* anterior = L->head;
		Nodo* ahora = anterior->sig;
		Nodo* siguiente = ahora->sig;
		anterior->sig = NULL;
		ahora->sig = anterior;
		anterior = ahora;
		ahora = siguiente;
		siguiente = ahora->sig;
		while (siguiente != NULL){
			ahora->sig = anterior;
			anterior = ahora;
			ahora = siguiente;
			siguiente = ahora->sig;
		}
		ahora->sig = anterior;
		L->head = ahora;
		
	}
}

// int algo = estaElem(L, x) ⇒ V (1), F (0) 	Retorna 1 si x está en L, y 0 si no.
int estaElem(Lista* L, int x){
	if (esVacia(L) == 1){
		return 0;
	}
	Nodo* aux = L->head;
	while (aux != NULL){
		if (aux->info == x){
			return 1;
		}
		aux = aux->sig;
	}
	return 0;
}

// cantVecesRepetido(L1, L2) 	Retorna la cantidad de veces que cada elemento de L1 se repite en L2
void cantVecesRepetido(Lista* L1, Lista* L2){
	if (esVacia(L1)==1 || esVacia(L2)==1){
		printf("Alguna de las listas es vacía");
	}else{
		int actual_1, actual_2;
		int contador = 0;
		Nodo* aux1 = L1->head;
		actual_1 = aux1->info;
		Nodo* aux2;
		Nodo* aux3;
		Lista* L3 = crearLista();
		while (aux1 != NULL){
			aux2 = L2->head;
			actual_2 = aux2->info;
			while (aux2 != NULL){
				if (actual_1 == actual_2 && estaElem(L3, actual_2) != 1){
					contador++;
					insertarFin(L3, actual_2);
				}
				aux2 = aux2->sig;
				if (aux2 != NULL){
					actual_2 = aux2->info;
				}
			}
			aux3 = aux1;
			printf("La cantidad de veces que %d esta en la segunda lista es %d\n", actual_1, contador);
			aux1 = aux1->sig;
			if (aux1 != NULL){
				actual_1 = aux1->info;
			}
			contador = 0;
		}
	}
}

//ListaDoble* algo = crearListaDoble() ⇒   LD	Crea en memoria la lista doble, inicializa sus datos y retorna una lista doble vacía.
ListaDoble* crearListaDoble(){
	ListaDoble* LD = (ListaDoble*)malloc(sizeof(ListaDoble));
	LD->head = NULL;
	return LD;
}

//NodoDoble* algo = crearNodoDoble(val) ⇒ ND 	Crea en memoria un nodo doble cuya info es val y que apunta a dos nodos vacíos, y lo retorna.
NodoDoble* crearNodoDoble(int val){
	NodoDoble* ND = (NodoDoble*)malloc(sizeof(NodoDoble));
	ND->info = val;
	ND->sig = NULL;
	ND->ant = NULL;
	return ND;
}

// int algo = esVacíaDoble(L) ⇒ V (1), F (0)	
int esVaciaDoble(ListaDoble* LD){
	NodoDoble* aux = LD->head;
	if (aux == NULL){
		return 1;
	}else{
		return 0;
	}
}

// insertarFinDoble(LD, x) 	Inserta x al final  de la lista doble LD. 
void insertarFinDoble(ListaDoble* LD, int x){
	if (esVaciaDoble(LD) == 1){
		NodoDoble* nuevoNodo = crearNodoDoble(x);
		LD->head = nuevoNodo;
	}else{
		NodoDoble* aux = LD->head;
		while (aux->sig != NULL){
			aux = aux->sig;
		}
		NodoDoble* nuevoNodo = crearNodoDoble(x);
		aux->sig = nuevoNodo;
		nuevoNodo->ant = aux;
		
		
	}
}

// mostrarListaDoble(LD) 		Recorre los elementos de la lista doble para procesarlos 
void mostrarListaDoble(ListaDoble* LD){
	NodoDoble* aux = LD->head;
	if (esVaciaDoble(LD) == 1){
		printf("NULL\n");
	}else{
		printf("[");
		while (aux != NULL){
			printf("<- %d -> ", aux->info);
			aux = aux->sig;
		}
		printf("]\n");
	}
}

// mataRepetidosDoble(LD) 	Elimina MASACRA Y EJECUTA los elementos repetidos de la lista doble LD.
void mataRepetidosDoble(ListaDoble* LD){
	if (esVaciaDoble(LD) == 1){
		printf("no puedo MATAR los repetidos de una lista doble vacía\n");
	}else{
		NodoDoble* ahora = LD->head;
		NodoDoble* anterior = ahora;
		int val = ahora->info;
		Lista* Laux = crearLista();
		insertarFin(Laux, val);
		ahora = ahora->sig;
		val = ahora->info;
		while (ahora->sig != NULL){
			if (estaElem(Laux, val) == 1){
				ahora->sig->ant = anterior;
				printf("Se ha EXTERMINADO %d de la lista doble\n", val);
				ahora = ahora->sig;
				anterior->sig = ahora->sig;
				val = ahora->info;
			}else{
				insertarFin(Laux, val);
				anterior = ahora;
				ahora = ahora->sig;
				val = ahora->info;
			}
		}
		if (estaElem(Laux, val) == 1){
			printf("se ha EXTERMINADO %d de la lista\n", val);
			anterior->sig = NULL;
		}
	}
}

// Pila* algo = crearPila() ⇒ P 	Crea en memoria una pila, inicializa sus datos y retorna una pila vacía.
Pila* crearPila(){
	Pila* P = (Pila*)malloc(sizeof(Pila));
	P->top = NULL;
	return P;
}

//NodoPila* algo = crearNodoPila(val) ⇒ nodopila 	Crea en memoria un nodo cuya info es val y que apunta a un nodo vacío, y lo retorna.
NodoPila* crearNodoPila(int val){
	NodoPila* nodo=(NodoPila*)malloc(sizeof(NodoPila));
	nodo->sig = NULL;
	nodo->info = val;
	return nodo;
}

// int algo = esVacíaPila(P) ⇒ V (1), F (0)	
int esVaciaPila(Pila* P){
	NodoPila* aux = P->top;
	if (aux == NULL){
		return 1;
	}else{
		return 0;
	}
}

// push(P, x) 	Inserta el valor x en el top de la pila P.
void push(Pila* P, int x){
	NodoPila* aux = P->top;
	NodoPila* nuevoNodo = crearNodoPila(x);
	nuevoNodo->sig = aux;
	P->top = nuevoNodo;
}

// int algo = pop(P) 	Elimina el top de la pila P y retorna su valor.
int pop(Pila* P){
	if (esVaciaPila(P) == 1){
		return -1;
	}else{
		NodoPila* aux = P->top;
		int val = aux->info;
		P->top = aux->sig;
		return val;
	}
}

// moverPila(P) 	Mueve los elementos de la pila P1 a la pila P2, dejando la pila P1 vacía.
void moverPila(Pila* P1, Pila* P2){
	if (esVaciaPila(P1) != 1){
		NodoPila* aux = P1->top;
		int val = aux->info;
		while (aux != NULL){
			push(P2, val);
			pop(P1);
			aux = P1->top;
			if (aux != NULL){
				val = aux->info;
			}
		}
	}
}

// mostrarPila(P) 		Recorre los elementos de la pila para procesarlos 
void mostrarPila(Pila* P){
	NodoPila* aux = P->top;
	int val;
	if (esVaciaPila(P) == 1){
		printf("NULL\n");
	}else{
		Pila* Paux = crearPila();
		while (aux != NULL){
			val = aux->info;
			printf("|%d|\n", val);
			moverPila(P, Paux);
			aux = aux->sig;
		}
		printf("|_|\n\n");
		aux = Paux->top;
		while (aux != NULL){
			val = aux->info;
			moverPila(Paux, P);
			aux = aux->sig;
		}
	}
}

// cambiarElems(P, n) 	Deja los primeros n elementos (en su orden inicial) de la pila P al final de P, es decir, lo más alejados del top.
void cambiarElems(Pila* P, int n){
	if (esVaciaPila(P) == 1 || n < 0){
		return;
	}else{
		Pila* Paux1 = crearPila();
		Pila* Paux2 = crearPila();
		int val, val2;
		NodoPila* aux = P->top;
		int i = 0;
		while (i < n && aux != NULL){
			val = pop(P);
			push(Paux1, val);
			aux = P->top;
			i++;
		}
		if (aux == NULL && i != n){
			printf("No se ha podido realizar el procedimiento\n");
		}else{
			while (aux != NULL){
				val2 = pop(P);
				push(Paux2, val2);
				aux = P->top;
			}
			moverPila(Paux1, P);
			moverPila(Paux2, P);
		}
	}
}

//los siguientes codigos son de Ignacio Solar xd
//Gracias Solar sos un crack
Cola *crear_cola(){
  Cola *Q = (Cola *)malloc(sizeof(Cola));
  Q->front = NULL;
  Q->rear = NULL;
  Q->n = 0;
  return Q;
}

int cola_vacia(Cola *Q) { return Q->front == NULL;} 

NodoCola *crear_nodo_cola(int valor) {
  NodoCola *nodo;
  nodo = (NodoCola *)malloc(sizeof(NodoCola));
  nodo->info = valor;
  nodo->sig = NULL;
  return nodo;
}

void enqueue(Cola *Q, int valor) {
  NodoCola *Nodo_nuevo = crear_nodo_cola(valor);
  if (cola_vacia(Q)) {
    Q->front = Nodo_nuevo;
    Q->rear = Nodo_nuevo;
  } else {
    Q->rear->sig = Nodo_nuevo;
    Q->rear = Nodo_nuevo;
  }
  Q->n++;
}

int dequeue(Cola *Q) {
  if (cola_vacia(Q)) {
    exit(1); // O puedes manejar el error de otra manera
  }

  NodoCola *temp = Q->front;
  int valor = temp->info;
  Q->front = Q->front->sig;

  if (Q->front == NULL) { // Si despues de remover, la cola queda vacia
    Q->rear = NULL;
  }

  free(temp);
  Q->n--;

  return valor; // Retornamos el valor desencolado
}

void mostrar_cola(Cola *Q) {
  if (Q == NULL || Q->n == 0) {
    printf("Cola está vacía.\n");
    return;
  }

  Cola *temp = crear_cola();

  // Desencolando de la cola original y encolando en la temporal mientras
  // imprimimos
  printf("Cola: ");
  while (!cola_vacia(Q)) {
    int valor = dequeue(Q);
    enqueue(temp, valor);
    printf("%d ", valor);
  }
  printf("\n");

  // Copiando de nuevo la cola temporal a la original
  while (!cola_vacia(temp)) {
    int valor = dequeue(temp);
    enqueue(Q, valor);
  }

  // Liberar memoria de la cola temporal
  free(temp);
}