#include "classify_chars.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* tenemos que clasificar un string en vocales y consonantes */
/* para eso tenemos que setear el campo 
    typedef struct classifier_s {
        char** vowels_and_consonants;
        char* string;
    } classifier_t;
 vowels_and_consonants de manera que : 
 vowels and consonants[0] queden todas las vocales del string
 vowels and consonants[1] queden las consonantes.
*/

int esVocal(char letra){
    switch (letra)
    {
    case 'a': 
        return 1;
    case 'e':
        return 1;
    case 'i':
        return 1;
    case 'o':
        return 1;
    case 'u':
        return 1;
    default:
        return 0;
    }
}

int longitud_de_string(char* string) {
	int i = 0;
	
	if (string == NULL){
		return 0;
	}
	while (string[i] != '\0'){
		i++;
	}
	
	return i;
}

void classify_chars_in_string(char* string, char** vowels_and_cons) {
    /* inicializamos el arreglo de vocales */
    /* le ponemos + 1 por si son todas vocales y necesitamos agregar al final el '\0' */
    char *vocales = calloc(65, sizeof(char));
    
    /* inicializamos el arreglo de consonantes */
    /* le ponemos + 1 por si son todas consonantes y necesitamos agregar al final el '\0' */
    char *consonantes = calloc(65, sizeof(char));
    
    /* llevamos contadores de las posiciones disponibles */
    int v = 0;
    int c = 0;

    /* clasificamos */
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (esVocal(string[i]) == 1)
        {
            vocales[v] = string[i];
            v++;
        } else if (string[i] != ' ')
        {
            consonantes[c] = string[i];
            c++;
        }
    }
    /* tenemos que poner el ultimo caracter en '\0' */
    vocales[v] = '\0';
    consonantes[c] = '\0';

    /* asignamos los punteros al lugar que corresponde al inicio de los arreglos */
    vowels_and_cons[0] = vocales;
    vowels_and_cons[1] = consonantes;

}

void classify_chars(classifier_t* array, uint64_t size_of_array) {
    for (uint64_t i = 0; i < size_of_array; i++)
    {
        array[i].vowels_and_consonants = malloc(2 * sizeof(char*));
        classify_chars_in_string(array[i].string , array[i].vowels_and_consonants);
    }

    
    
}


