#include <stdio.h>
#include <stdlib.h>
#include "TDAlistas.h"

//AUTOR: Alfonso Sebastian Palacios Vergara, Ingeniería Civil Informática USACH - 3er semestre, 2024. Estructuras de Datos.

/*------------- estructuras de datos -------------*/

typedef struct matrizAdy
{
	int n; 		//Numero de vertices
	int m; 		//Numero de aristas
	int** MA; 	//matriz 
}MatrizAdy;

typedef struct listaAdy{
	int n;	//Numero de vertices
	Lista** LA;	//lista
}ListaAdy;

typedef struct arista{
	int v1, v2;	//Entre qué 2 vértices está la arista
	int peso;
}Arista;

typedef struct nodoPrim{
	int ind;	//índice del vértice
	int dist;	//distancia hasta el vértice más cercano encontrado
	struct nodoPrim* sig;
}NodoPrim;

typedef struct listaPrim{
	NodoPrim* head;
}ListaPrim;

//___________________________________________________________________________________________________________________________________

/*----------------------- llamados -----------------------*/

/*_____________MISCELANEOS______________*/

//Crea una arista entre 2 vértices con el peso especificado
//Output: Arista*; input: int peso, int vertice1, int vertice2
Arista* crearArista(int peso, int v1, int v2);

//Verifica si en un arreglo hay algún 0. Funcion auxiliar para Dijkstra
//Output: BoolInt; input: arreglo A y su largo
int quedanSinVisitar(int* A, int largo);

//Elige el vértice no visitado que hasta ahora haya tenido la menor distancia desde el origen en cada iteración de Dijkstra y devuelve su índice. Funcion auxiliar para Dijkstra
//Output: int índice del vértice con menor distancia; input: arreglos con distancias, lista de vértices ya visitados y su largo
int minimaDistanciaDijkstra(int* distancia, int* visitados, int largo);

//Crea una lista de Prim vacía. Función auxiliar para Prim.
//Output: ListaPrim* L con L->head nulo; input: sin parámetros
ListaPrim* crearListaPrim();

//Crea un nodo de Prim con el índice del vértice especificado y la distancia al vértice más cercano (encontrado hasta el momento) especificada. Función auxiliar para Prim.
//Output: NodoPrim* nodo con los datos requeridos que apunta a nulo; input: int índice del vértice, int distancia al vértice origen
NodoPrim* crearNodoPrim(int ind, int dist);

//Verifica si un vértice está en una lista de Prim a partir de su índice ÚNICO. Función auxiliar para Prim.
//Output: BoolInt; input: ListaPrim* lista en la que verificar, int índice ÚNICO del vértice a verificar
int estaEnListaPrim(ListaPrim* L, int ind);

//Añade a una lista de Prim un nodo con el índice del vértice a añadir y con su distancia desde el vértice más cercano encontrado. Función auxiliar para Prim.
//Output: void; input: ListaPrim* lista a modificar, int índice del vértice a añadir, int* arreglo con las distancias de cada vértice desde el vértice más cercano a cada uno encontrado.
void enlistarPrim(ListaPrim* L, int ind, int* dist);

//Actualiza la distancia encontrada para un vértice en una lista de Prim. Función auxiliar para Prim.
//Output: void; input: ListaPrim* lista a modificar, int índice del vértice en el nodo, int distancia a actualizar desde el vértice más cercano encontrado.
void actualizarListaPrim(ListaPrim* L, int ind, int* dist);

//Encuentra el índice del vértice no visitado con la menor distancia a cualquier vértice visitado, lo devuelve y quita su nodo de la lista de Prim entregada. Función auxiliar para Prim.
//Output: int índice del vértice más cercano al origen; input: ListaPrim* lista para buscar, int* arreglo con los vértices visitados, int largo del arreglo
int minimaDistanciaPrim(ListaPrim* L, int* visitados);

//Muestra una lista de Prim. Funcion auxiliar no necesaria para Prim.
//Output: void (printea la lista de Prim); input: ListaPrim* lista a mostrar por pantalla
void mostrarListaPrim(ListaPrim* L);

/*_____________MATRICES______________*/

//Crea una estructura para una matriz de adyacencia vacía. 
//Output: estructura; input: numero de filas (y columnas)
MatrizAdy* crearMatrizAdyVacia(int n);

//Lee una matriz de las otras y la convierte en una de adyacencia DIRIGIDA. LA PRIMERA LINEA DEBE SER SOLO EL NUMERO DE VERTICES.
//Output: MatrizAdy*; input: argv[x]
MatrizAdy* leerArchivoMatriz(char *nombreArchivo);

//Lee una matriz de las otras y la convierte en una de adyacencia NO DIRIGIDA. LA PRIMERA LINEA DEBE SER SOLO EL NUMERO DE VERTICES.
//Output: MatrizAdy*; input: argv[x]
MatrizAdy* leerArchivoMatrizND(char* nombreArchivo);

//Muestra la matriz de la estructura lol. 
//Output: void; input: MatrizAdy*
void mostrarMatriz(MatrizAdy* ENL);

//Retorna e imprime por pantalla la fila y la columna con la mayor cant de 1s
//Output: un arreglo con malloc con los numeros de la fila y columna; input: MatrizAdy*
int* filaColumnaMayorCant1(MatrizAdy* si);

//Toma un numero X y verifica si la suma de la columna X es igual de la suma de la fila X
//Output: BoolInt; input: MatrizAdy* y numero X
int igualSumaColumnaFila(MatrizAdy* M, int x);

//Cuenta la cant de aristas de la matriz NO DIRIGIDA.
//Output: la cant de aristas; input: MatrizAdy*
int cuentaUnos(MatrizAdy* M);

//Verifica las columnas que tengan 1s en la fila x y retorna sus posiciones en una lista
//Output: Lista dinamica de TDAlistas; input: MatrizAdy* y un numero x
Lista* nombreEpico(MatrizAdy* M, int x);

//Verifica si la matriz de adyacencia es simetrica con respecto a la diagonal ppal (es decir, si el grafo es direccionado)
//Output: BoolInt; input: MatrizAdy*
int esDireccionadoMatriz(MatrizAdy* M);

//Cambia los 1s de la matriz por 0s
//Output: MatrizAdy*; input: MatrizAdy*
MatrizAdy* cambiaUnos(MatrizAdy* M);

//Agrega una arista entre 2 vertices a la matriz DIRIGIDA.
//Output: void; input: MatrizAdy* matriz a modificar, Arista* arista a agregar
void insertarAristaMatriz(MatrizAdy* M, Arista* A);

//Recorre en anchura (viendo para cada vértice sus adyacentes antes de pasar al siguiente vértice) un GRAFO CONEXO representado en una matriz de ady
//Output: int** arreglo con los arreglos conteniendo las distancias y los predecesores; input: MatrizAdy* M, int vértice de origen
int** BFSMatriz(MatrizAdy* M, int origen);

//AYUDA A LA FUNCIÓN DFSMatriz a realizar el recorrido por profundidad de un GRAFO NO NECESARIAMENTE CONEXO representado por una matriz de ady. Funcion auxiliar para DFS
//Output: void; input: MatrizAdy* M, int vértice, int visitados[] (arreglo con los vertices ya visitados)
void DFSMatrizBackT(MatrizAdy* M, int actual, int anterior, int* visitados, int* previo, int* distancia);

//USA LA FUNCIÓN DFSMatrizBackT para recorrer por profundidad (llega al final de un camino para hacer lo mismo con el vertice ady al primer vertice) un grafo NO NECESARIAMENTE CONEXO representado por una matriz de ady
//Output: int** arreglo con los arreglos conteniendo las distancias y los predecesores; input: MatrizAdy* M, int vértice de origen
int** DFSMatriz(MatrizAdy* M, int origen);

//Para un GRAFO CONEXO y dado un vértice de origen, encuentra el mínimo camino desde ese origen a cada otro vértice posible en un grafo representado por una matriz de ady
//Output: int** arreglo con los arreglos conteniendo las distancias y los predecesores; input: MatrizAdy* grafo en matriz de ady, int vértice de origen
int** DijkstraMatriz(MatrizAdy* M, int origen);

//Crea el árbol de expansión de costo mínimo o distancia mínima, viendo por cada vértice qué vértice adyacente no visitado tiene la menor distancia para posteriormente saltar a él y calcular las distancias del mismo a sus adyacentes, y en caso de ser menores a las que se tenían, reemplazarlas o "tomar esa rama del árbol" (algoritmo goloso)
//Output: int** arreglo con los arreglos conteniendo as distancias y los predecesores; input: MatrizAdy* grafo en matriz de ady, int vértice de origen
int** MSTPrimMatriz(MatrizAdy* M, int origen);


//_____________LISTAS______________*/

//Crea una lista de adyacencia vacía
//Output: ListaAdy*; input: numero de vertices
ListaAdy* crearListaAdyVacia(int n);

//Inserta una arista o conexión entre 2 vértices (v1 y v2) en una lista DIRIGIDA.
//Output: void; input: Lista* lista a la que añadira la arista, Arista* arista que añadira
void insertarAristaLista(ListaAdy* L, Arista* A);

//Lee una matriz de las otras y la convierte en una lista de adyacencia DIRIGIDA. LA PRIMERA LINEA DEBE SER SOLO EL NUMERO DE VERTICES (se puede implementar fácilmente para anular esto).
//Output: ListaAdy*; input: argv[x]
ListaAdy* leerArchivoLista(char* nombreArchivo);

//Lee una matriz de las otras y la convierte en una lista de adyacencia NO DIRIGIDA. LA PRIMERA LINEA DEBE SER SOLO EL NUMERO DE VERTICES (se puede implementar fácilmente para anular esto).
//Output: ListaAdy*; input: argv[x]
ListaAdy* leerArchivoListaND(char* nombreArchivo);

//Muestra la lista de adyacencia po q wea.
//Output: void; input: ListaAdy* lista a mostrar
void mostrarListaAdy(ListaAdy* L);

//Verifica si el grafo es direccionado a partir de su lista de adyacencia
//Output: BoolInt; input: ListaAdy*
int esDireccionadoLista(ListaAdy* L);

//Remueve la arista o conexión entre 2 vertices
//Output: void; input: ListaAdy* lista a trabajar, Arista* arista a eliminar
void removerAristaLista(ListaAdy* L, Arista* A);

//Remueve la arista o conexión entre 2 vertices 
//Output: void; input: ListaAdy* lista a trabajar y los 2 vértices entre los cuales se define la arista a eliminar
void removerAristaListaV2(ListaAdy* L, int v1, int v2);

//Crea el grafo complemento a partir de un grafo representado por su lista de ady, y devuelve su lista de ady
//Output: ListaAdy* el grafo complemento; input: ListaAdy* el grafo a complementar
ListaAdy* grafoComplementoLista(ListaAdy* L);

//Une 2 grafos representados por su lista de adyacencia, modificando la lista 2 y destruyendo la 1
//Output: ListaAdy* la lista 2 modificada; input: ListaAdy* lista 1 a unir, ListaAdy* lista 2 a unir
ListaAdy* unirGrafosLista(ListaAdy* L1, ListaAdy* L2);




//___________________________________________________________________________________________________________________________________

/*----------------------- operaciones -----------------------*/

/*_____________MISCELANEAS______________*/


Arista* crearArista(int v1, int v2, int peso){
	Arista* arista = (Arista*)malloc(sizeof(Arista));
	arista->v1 = v1;
	arista->v2 = v2;
	arista->peso = peso;
	return arista;
}

int quedanSinVisitar(int* A, int largo){
	for (int i=0; i<largo; i++){
		if (A[i] == 0){
			return 1;
		}
	}
	return 0;
}

int minimaDistanciaDijkstra(int* distancia, int* visitados, int largo){
	int menor;
	for (int j=0; j<largo; j++){
		if (visitados[j] == 0){
			menor = j;
		}
	}
	for (int i=0; i<largo; i++){
		if (visitados[i] == 0 && distancia[i] < distancia[menor]){
			menor = i;
		}
	}
	return menor;
}

ListaPrim* crearListaPrim(){
	ListaPrim* L = (ListaPrim*)malloc(sizeof(ListaPrim));
	L->head = NULL;
	return L;
}

NodoPrim* crearNodoPrim(int ind, int dist){
	NodoPrim* nodo = (NodoPrim*)malloc(sizeof(NodoPrim));
	nodo->ind = ind;
	nodo->dist = dist;
	nodo->sig = NULL;
	return nodo;
}

int estaEnListaPrim(ListaPrim* L, int ind){
	NodoPrim* aux = L->head;
	while (aux != NULL){
		if (aux->ind == ind){
			return 1;
		}
		aux = aux->sig;
	}
	return 0;
}

void enlistarPrim(ListaPrim* L, int ind, int* dist){
	NodoPrim* aux = L->head;
	NodoPrim* nuevoNodo = crearNodoPrim(ind, dist[ind]);
	if (L->head == NULL){
		L->head = nuevoNodo;
	}else{
		aux = L->head;
		while (aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nuevoNodo;
	}
}

void actualizarListaPrim(ListaPrim* L, int ind, int* dist){
	NodoPrim* aux = L->head;
	while (aux->ind != ind && aux != NULL){
		aux = aux->sig;
	}
	aux->dist = dist[ind];
}

//esta cosa me dio unos dolores de cabeza man
int minimaDistanciaPrim(ListaPrim* L, int* visitados){
	NodoPrim* aux = L->head;
	NodoPrim* aux2 = aux;
	NodoPrim* aux3 = aux;
	NodoPrim* aux4 = aux;
	int menor = aux->ind;
	int distanciaMenor = aux->dist;
	if (aux->sig == NULL){
		L->head = NULL;
		return menor;
	}
	while (aux != NULL){
		if (aux->dist < distanciaMenor){
			distanciaMenor = aux->dist;
			menor = aux->ind;
			aux4 = aux;
			aux3 = aux2;
		}
		aux2 = aux;
		aux = aux->sig;
	}
	if (aux3 == L->head && aux3 == aux4){
		L->head = L->head->sig;
		free(aux);
	}else{
		aux3->sig = aux3->sig->sig;
		free(aux3->sig);
	}
	return menor;
}

void mostrarListaPrim(ListaPrim* L){
	NodoPrim* aux = L->head;
	printf("la lista es:");
	while (aux != NULL){
		printf("|ind %d, dist %d|->", aux->ind, aux->dist);
		aux = aux->sig;
	}
	printf("\n");
}

/*_____________MATRICES______________*/

MatrizAdy* crearMatrizAdyVacia(int n) {
	MatrizAdy* estr = (MatrizAdy*)malloc(sizeof(MatrizAdy));
	estr->n = n;
	estr->m = 0;
	estr->MA = (int**)malloc(n*sizeof(int*));
	for (int i=0; i<n; i++){
		estr->MA[i] = (int*)malloc(n*sizeof(int));
		for (int j=0; j<n; j++){
			estr->MA[i][j] = 0;
		}
	}
	return estr;

}

MatrizAdy* leerArchivoMatriz(char *nombreArchivo){
	FILE* pf = fopen(nombreArchivo, "r");
	if (pf == NULL){
		fclose(pf);
		return NULL;
	}
	int n;
	fscanf(pf, "%d", &n);
	MatrizAdy* M = crearMatrizAdyVacia(n);
	M->m = n;
	int i, j, k, a;
	while(fscanf(pf, "%d%d%d", &j, &k, &a) == 3){
		M->MA[j][k] = a;	//si es sin peso, borra "a", pon fscanf == 2 en el while y aquí pon solo = 1;
	}

	fclose(pf);
	return M;
}

MatrizAdy* leerArchivoMatrizND(char* nombreArchivo){
	FILE* pf = fopen(nombreArchivo, "r");
	if (pf == NULL){
		fclose(pf);
		return NULL;
	}
	int n;
	fscanf(pf, "%d", &n);
	MatrizAdy* M = crearMatrizAdyVacia(n);
	M->m = n;
	int i, j, k, a;
	while(fscanf(pf, "%d%d%d", &j, &k, &a) == 3){
		M->MA[j][k] = a;	//si es sin peso, borra "a", pon fscanf == 2 en el while y aquí pon solo = 1;
		M->MA[k][j] = a;
	}

	fclose(pf);
	return M;
}

void mostrarMatriz(MatrizAdy* ENL) {
	int tope = ENL->n;
	for (int i=0; i<tope; i++){
		printf("[");
		for (int j=0; j<tope; j++){
			printf("%d ",ENL->MA[i][j]);
		}
		printf("]\n");
	}
}

int* filaColumnaMayorCant1(MatrizAdy* si){
	int counterColumna = 0;
	int counterFila = 0;
	int mayorColumna = 0;
	int mayorFila = 0;
	int fila = -1;
	int columna = -1;
	for (int i=0; i<si->n; i++){
		for (int j=0; j<si->m; j++){
			if (si->MA[i][j]==1){
				counterFila++;
			}
		}
		if (counterFila>mayorFila){
			mayorFila = counterFila;
			fila = i;
		}
		counterFila = 0;
		
	}
	for (int b=0; b<si->m; b++){
		for (int a=0; a<si->n; a++){
			if (si->MA[a][b]==1){
				counterColumna++;
			}
		}
		if (counterColumna>mayorColumna){
			mayorColumna = counterColumna;
			columna = b;
		}
		counterColumna = 0;
	}
	int* output = (int*)malloc(2*sizeof(int));
	output[1] = fila;
	output[2] = columna;
	printf("La fila con mayor cant de 1 es: %d, y la columna es: %d\n", fila, columna);
	return output;
}

int igualSumaColumnaFila(MatrizAdy* M, int x){
	int counterFila = 0;
	int counterColumna = 0;
	for (int i=0; i<M->n; i++){
		if (M->MA[i][x]==1){
			counterColumna++;
		}
	}
	for (int j=0; j<M->m; j++){
		if (M->MA[x][j]==1){
			counterFila++;
		}
	}
	if (counterFila == counterColumna){
		return 1;
	}
	return 0;
}

int cuentaUnos(MatrizAdy* M){
	int counter = 0;
	for (int i=0; i<M->n; i++){
		for (int j=0; j<M->m; j++){
			if (M->MA[i][j]!=0){
				counter++;
			}
		}
	}
	return counter;
}

Lista* nombreEpico(MatrizAdy* M, int x){
	Lista* output = crearLista();
	for (int i=0; i<M->m; i++){
		if (M->MA[x][i]==1){
			insertarFin(output, i);
		}
	}
	return output;
}

int esDireccionadoMatriz(MatrizAdy* M){
	int i = 0;
	int j = 1;
	int k = 1;
	while (i<M->n){
		while (j-1<(M->m)-k){
			if (M->MA[k-1][j] != M->MA[j][k-1]){
				return 1;
			}
			j++;
		}
		j = k+1;
		k++; 
		i++;
	}
	return 0;
}

MatrizAdy* cambiaUnos(MatrizAdy* M){
	for (int i=0; i<M->n; i++){
		for (int j=0; j<M->m; j++){
			if (M->MA[i][j]==0){
				M->MA[i][j] = 1;
			}else if (M->MA[i][j]==1){
				M->MA[i][j] = 0;
			}
		}
	}
	return M;
}

void insertarAristaMatriz(MatrizAdy* M, Arista* A){
	M->MA[A->v1][A->v2] = A->peso;
	//Adicionalmente si es no dirigida: M->MA[A->v2][A->v1] = A->peso;
}

int** BFSMatriz(MatrizAdy* M, int origen){
	int u;
	int** output = (int**)malloc(2*sizeof(int*));		//arreglo con las distancias y los predecesores finales de cada vértice
	int* visitados = (int*)malloc(M->n * sizeof(int));		//arreglo auxiliar para ver qué vértices hemos visitado (0 es no visitado, 1 es visitado pero no he visitado sus adyacentes y 2 es que lo visité y visité todos sus adyacentes)
	int* previo = (int*)malloc(M->n * sizeof(int));			//arreglo con el vértice del que viene cada vértice siguiendo el camino desde el origen
	int* distancias = (int*)malloc(M->n * sizeof(int));		//arreglo con las distancias (pesos) de cada vértice desde el origen
	Cola* Q = crear_cola();		//cola para decidir a qué vértice me moveré. Las colas son FIFO (first in first out), por lo que desde el origen veo los adyacentes y los pongo en la cola, y aunque me mueva a uno de ellos y ponga a sus adyacentes en la cola, el segundo adyacente del origen sigue teniendo mayor prioridad, porque entró antes.
	for (int i=0; i<M->n; i++){
		visitados[i] = 0;
		previo[i] = -1;
		distancias[i] = 999;
	}
	visitados[origen] = 1;		//marco como visitado el origen (a diferencia de con Dijkstra y con Prim)
	distancias[origen] = 0;
	enqueue(Q, origen);		//como visité al origen, lo agrego a la cola para poder ver sus adyacentes
	while (!cola_vacia(Q)){
		u = dequeue(Q);		//visitaré a los adyacentes del siguiente en la cola. Como en la cola solo van aquellos vértices a los cuales visitaré sus adyacentes, saco al que voy a ver de la cola, pues ya no podré ver mas adyacentes cuando termine de verlos todos (duh)
		for (int j=0; j<M->n; j++){		//recorro los adyacentes no visitados de este vértice
			if (visitados[j] == 0 && M->MA[u][j] != 0){
				visitados[j] = 1;
				distancias[j] = distancias[u] + 1;
				previo[j] = u;
				enqueue(Q, j);		//lo agrego a la cola para ver sus adyacentes (no visitados) en el futuro
			}
		}
		visitados[u] = 2;	//marco que ya visité todos los adyacentes de este vértice
	}
	output[0] = distancias;
	output[1] = previo;
	
	//libero memoria
	free(Q);
	free(visitados);
	return output;
}

void DFSMatrizBackT(MatrizAdy* M, int actual, int anterior, int* visitados, int* previo, int* distancia){
	visitados[actual] = 1;	//marcamos el vértice como visitado
	if (anterior == -1){
		distancia[actual] = 0;
	}else{
		previo[actual] = anterior;
		distancia[actual] = distancia[anterior] + 1;
	}
	for (int i=0; i<M->n; i++){		//desde este vértice, recorremos cada vértice adyacente que no haya sido visitado ya
		if (M->MA[actual][i] != 0 && visitados[i] == 0){
			DFSMatrizBackT(M, i, actual, visitados, previo, distancia);
		}
	}
}

int** DFSMatriz(MatrizAdy* M, int origen){
	int** output = (int**)malloc(2*sizeof(int*));		//arreglo con las distancias y los predecesores finales de cada vértice
	int* visitados = (int*)malloc(M->n * sizeof(int));		//arreglo auxiliar para verificar qué vértice hemos visitado (0 es no visitado, 1 es visitado)
	int* previo = (int*)malloc(M->n * sizeof(int));			//arreglo con el vértice del que viene cada vértice siguiendo el camino desde el origen
	int* distancias = (int*)malloc(M->n * sizeof(int));		//arreglo con las distancias (pesos) de cada vértice desde el origen
	for (int i=0; i<M->n; i++){
		visitados[i] = 0;
		previo[i] = -1;
		distancias[i] = 999;
	}
	distancias[origen] = 0;
	
	//para CADA VÉRTICE del grafo, recorremos por DFS si sus adyacentes no han sido visitados. Es por esto que funciona también para grafos no conexos.
	for (int j=0; j<M->n; j++){
		if (visitados[j] == 0){
			DFSMatrizBackT(M, j, -1, visitados, previo, distancias);
		}
	}
	output[0] = distancias;
	output[1] = previo;
	free(visitados);
	return output;
}

int** DijkstraMatriz(MatrizAdy* M, int origen){
	int u;
	int** output = (int**)malloc(2*sizeof(int*));		//arreglo con las distancias y los predecesores finales de cada vértice
	int* distancia = (int*)malloc(M->n*sizeof(int));	//arreglo con las distancias (pesos) de cada vértice desde el origen
	int* visitados = (int*)malloc(M->n*sizeof(int));	//arreglo auxiliar para ver qué vértices hemos visitado, es decir, aquellos a los que hallamos visto o estemos viendo sus adyacentes, que ya calculamos al menos una distancia pero NO necesariamente la distancia final (0 es no visitado, 1 es visitado)
	int* predecesor = (int*)malloc(M->n*sizeof(int));	//arreglo con el vértice del que viene cada vértice siguiendo el menor camino desde el origen
	for (int i=0; i<M->n; i++){
		distancia[i] = 999;
		visitados[i] = 0;
		predecesor[i] = -1;
	}
	distancia[origen] = 0;
	
	//no quiero marcar al origen como visitado aún (a diferencia de con BFS y de manera similar a Prim), pues quiero que primero el algoritmo elija al origen para ver sus adyacentes y empezar, y el algoritmo solo "se mueve" a vértices no visitados
	
	while (quedanSinVisitar(visitados, M->n) != 0){		//mientras hayan vértices por visitar... (es por esto que sólo funciona en grafos conexos)
		
		//elijo el vértice con la mínima distancia al origen y que no haya sido visitado para continuar por el camino mínimo. Tal vez no sea así para cada vértice adyacente a este vértice "u" eso si, y ahora lo descubriré
		u = minimaDistanciaDijkstra(distancia, visitados, M->n);
		
		visitados[u] = 1;	//lo marco como visitado y recorro sus adyacentes. Fijate que no marco como visitados los vértices adyacentes a este. Solo son visitados los vertices a los que "me muevo" (las "u")
		for (int j=0; j<M->n; j++){
			
			//si es adyacente y la distancia que tenía guardada (que había encontrado antes si es que había encontrado otra) es menor a la distancia hasta este vértice "u" más la distancia entre este vértice "u" y el que estoy viendo, "j"
			if (M->MA[u][j] != 0 && distancia[j] > distancia[u] + M->MA[u][j]){		//fijate que no es necesario que el vertice "j" no haya sido visitado, pues queremos sobreescribir su distancia encontrada si vemos que la que encontramos ahora es menor
				distancia[j] = distancia[u] + M->MA[u][j];		//sobreescribimos la distancia que teníamos guardada con la distancia menor que encontramos ahora
				predecesor[j] = u;		//finalmente, marcamos el nuevo predecesor
				//no coloco estos vertices como visitados, pues aunque calcule distancias para ellos, no me he "movido" a ellos (como dije antes). Estos son los vértices vistos, no visitados.
			}
		}
	}
	output[0] = distancia;
	output[1] = predecesor;
	free(visitados);	//libero la memoria que no es relevante
	return output;
}

int** MSTPrimMatriz(MatrizAdy* M, int origen){
	int u;
	int** output = (int**)malloc(2*sizeof(int*));		//arreglo con las distancias y los predecesores finales de cada vértice
	int* distancia = (int*)malloc(M->n*sizeof(int));	//arreglo con las distancias (pesos) de cada vértice desde el vértice adyacente más cercano
	int* visitados = (int*)malloc(M->n*sizeof(int));	//arreglo auxiliar para ver qué vértices hemos visitado, es decir, aquellos a los que hayamos visto o estemos viendo sus adyacentes, que ya calculamos su distancia mínima (0 es no visitado, 1 es visitado)
	int* predecesor = (int*)malloc(M->n*sizeof(int));	//arreglo con el vértice del que viene cada vértice siguiendo el menor árbol de expansión
	ListaPrim* L = crearListaPrim();	//lista con los índices y distancias de los adyacentes a los vértices visitados (la distancia es entre el ady y el vértice al que es ady)
	for (int i=0; i<M->n; i++){
		distancia[i] = 999;
		visitados[i] = 0;
		predecesor[i] = -1;
		enlistarPrim(L, i, distancia);		//enlisto a cada vértice como "por visitar", es decir, un vértice al que debo revisar sus adyacentes (NO significa que no lo haya visto antes o calculado una distancia antes, solo que no he visto sus adyacentes)
	}
	distancia[origen] = 0;
	//NO marco como visitado el origen (a diferencia de con BFS, pero de manera similar a Dijkstra)
	actualizarListaPrim(L, origen, distancia);		// actualizo la distancia del origen en la lista de Prim
	while (L->head != NULL){
		u = minimaDistanciaPrim(L, visitados);	//obtengo el adyacente a cualquier vértice ya visitado que tenga la menor distancia a ese respectivo vértice, y lo visito
		visitados[u] = 1;
		for (int j=0; j<M->n; j++){		//recorro los adyacentes de este vértice "u"
			
			//si es adyacente a "u", aún deben verse a sus adyacentes (está en la lista) y la distancia que tengo guardada entre el vértice "j" que estoy viendo y un adyacente suyo es menor a la distancia entre el vértice "j" que estoy viendo y el vértice "u" que estoy visitando
			if (M->MA[u][j] != 0 && estaEnListaPrim(L, j) == 1 && distancia[j] > M->MA[u][j]){
				distancia[j] = M->MA[u][j];		//cambio la distancia que tenía por la nueva, es decir, "incluyo la rama" menor (es decir la que acabo de encontrar) y "podo la rama mayor" (la que tenía)
				predecesor[j] = u;
				actualizarListaPrim(L, j, distancia);	//actualizo la distancia del vértice en la lista
			}
		}
	}
	
	//libero la memoria que no es relevante
	free(visitados);
	free(L);
	
	//EZ PZ (me compliqué la vida innecesariamente haciendo este)
	output[0] = distancia;
	output[1] = predecesor;
	return output;
}

//_____________LISTAS______________*/

ListaAdy* crearListaAdyVacia(int n){
	ListaAdy* lista = (ListaAdy*)malloc(sizeof(ListaAdy));
	lista->n = n;
	lista->LA = (Lista**)malloc(n*sizeof(Lista));
	for (int i=0; i<n; i++){
		lista->LA[i] = crearLista();
	}
	return lista;
}

void insertarAristaLista(ListaAdy* L, Arista* A){
	if (estaElem(L->LA[A->v1], A->v2) == 1 || A->v1 == A->v2){
		return;
	}
	insertarFin(L->LA[A->v1], A->v2);
	//Si es no dirigida: insertarFin(L->LA[A->v2], A->v1);
}

ListaAdy* leerArchivoLista(char* nombreArchivo){
	FILE* pf = fopen(nombreArchivo, "r");
	if (pf == NULL){
		fclose(pf);
		return NULL;
	}
	int n;
	fscanf(pf, "%d", &n);
	ListaAdy* L = crearListaAdyVacia(n);
	int j, k, a;
	while(fscanf(pf, "%d%d%d", &j, &k, &a) == 3){
		if (estaElem(L->LA[j], k) == 0){
			insertarAristaLista(L, crearArista(j, k, a));
		}
	}
	fclose(pf);
	return L;
}

ListaAdy* leerArchivoListaND(char* nombreArchivo){
	FILE* pf = fopen(nombreArchivo, "r");
	if (pf == NULL){
		fclose(pf);
		return NULL;
	}
	int n;
	fscanf(pf, "%d", &n);
	ListaAdy* L = crearListaAdyVacia(n);
	int j, k, a;
	while(fscanf(pf, "%d%d%d", &j, &k, &a) == 3){
		if (estaElem(L->LA[j], k) == 0){
			insertarAristaLista(L, crearArista(j, k, a));
			insertarAristaLista(L, crearArista(k, j, a));
		}
	}
	fclose(pf);
	return L;
}


void mostrarListaAdy(ListaAdy* L){
	for (int i=0; i<L->n; i++){
		printf("vertice %d: ", i);
		mostrarLista(L->LA[i]);
	}
}


int esDireccionadoLista(ListaAdy* L){
	Nodo* aux1;
	for (int i=0; i<L->n; i++){
		aux1 = L->LA[i]->head;
		while (aux1 != NULL){
			if (estaElem(L->LA[aux1->info], i) == 0){
				return 1;
			}
			aux1 = aux1->sig;
		}
	}
	return 0;
}

void removerAristaLista(ListaAdy* L, Arista* A){
	eliminarElem(L->LA[A->v1], A->v2);
}

void removerAristaListaV2(ListaAdy* L, int v1, int v2){
	eliminarElem(L->LA[v1], v2);
}


ListaAdy* grafoComplementoLista(ListaAdy* L){
	ListaAdy* output = crearListaAdyVacia(L->n);
	Nodo* aux;
	int* A = (int*)malloc(L->n*sizeof(int));
	Arista* arista = crearArista(-1, -1, 1);
	for (int i=0; i<L->n; i++){
		A[i] = 0;
	}
	for (int j=0; j<L->n; j++){
		aux = L->LA[j]->head;
		while (aux != NULL){
			A[aux->info] = 1;
			aux = aux->sig;
		}
		for (int x=0; x<L->n; x++){
			if (A[x] == 0){
				arista->v1 = j;
				arista->v2 = x;
				insertarAristaLista(output, arista);
			}
		}
		for (int k=0; k<L->n; k++){
			A[k] = 0;
		}
	}
	return output;
}


ListaAdy* unirGrafosLista(ListaAdy* L1, ListaAdy* L2){
	ListaAdy* output = crearListaAdyVacia(L1->n);
	Nodo* aux;
	for (int i=0; i<L1->n; i++){
		aux = L1->LA[i]->head;
		while (aux != NULL){
			if (estaElem(L2->LA[i], aux->info) != 1){
				insertarAristaLista(L2, crearArista(i, aux->info, 1));
			}
			aux = aux->sig;
		}
	}
	free(L1);
	return L2;
}