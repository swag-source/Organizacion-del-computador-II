#include "lista_enlazada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


lista_t* nueva_lista(void) {
    lista_t *ptrListaEnlazada;
    ptrListaEnlazada = malloc(sizeof(lista_t));

    if (ptrListaEnlazada == NULL)
    {
        return NULL; //salvamos el caso en el que malloc me devuelva un puntero a NULL.
    }
    ptrListaEnlazada->head = NULL;
    return ptrListaEnlazada;
}


uint32_t longitud(lista_t* lista) {
    // definimos la variable longitud la cual llevará cuenta de la cantidad de nodos por la que pasé
    uint32_t longitud = 0;
    nodo_t* actual = lista->head;

    while (actual != NULL) // checkear tema NULL
    {
        actual = actual->next;
        longitud++;        
    }

    return longitud;
}

void agregar_al_final(lista_t* lista, uint32_t* arreglo, uint64_t longitud) {

    /* Pido memoria para el nuevo nodo */
    nodo_t* nuevo = (nodo_t*)malloc(sizeof(nodo_t));
    nodo_t* actual = lista->head;

    /* si la lista está vacía? si no? */
    if (actual == NULL)
    {
        lista->head = nuevo;
    }
    
    while (actual->next != NULL)
    {
        actual = actual->next;
    }
    /* asigno los valores que me pide asignar : arreglo y len */
    actual = nuevo;

    actual->next = NULL;
    actual->longitud = longitud;
    actual->arreglo = arreglo;
    
}

nodo_t* iesimo(lista_t* lista, uint32_t i) {
    // definimos donde comenzamos a buscar el i-ésimo elemento (head de la lista)
    nodo_t* actual = lista->head;
    // definimos un contador el cual itera sobre la lista y comparamos con el i.
    uint32_t j = 0;

    // salvamos el caso en que nos pasen un i que no esté en rango
    if (i >= longitud(lista) || i < 0)
    {
        return NULL;
    } // ToniusRetonius 
    
    while (j != i && actual != NULL)
    {
        actual = actual->next;
        j++;
    }
    // cuando llegamos al i-esimo nodo, salimos del while y devolvemos el nodo donde estamos parados
    return actual;
}

uint64_t cantidad_total_de_elementos(lista_t* lista) {    
    uint64_t sumaTotal = 0;
    nodo_t* actual = lista->head;

    while(actual != NULL){
        sumaTotal += actual->longitud;
        actual = actual->next;
    }
    return sumaTotal;    
}

void imprimir_lista(lista_t* lista) {
    nodo_t* actual = lista->head;
    uint64_t cantidad;
    // implemento cantidad total de elementos de forma recursiva.
    /*
         | "NULL"    si actual = NULL
    f(n) | 
         | "| longitud(actual) |" + imprimir_lista(actual.siguiente) si actual != NULL
    */
    
}

// Función auxiliar para lista_contiene_elemento
int array_contiene_elemento(uint32_t* array, uint64_t size_of_array, uint32_t elemento_a_buscar) {

}

int lista_contiene_elemento(lista_t* lista, uint32_t elemento_a_buscar) {

}


// Devuelve la memoria otorgada para construir la lista indicada por el primer argumento.
// Tener en cuenta que ademas, se debe liberar la memoria correspondiente a cada array de cada elemento de la lista.
void destruir_lista(lista_t* lista) {
    
}