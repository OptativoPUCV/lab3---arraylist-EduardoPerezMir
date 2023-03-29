#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *auxArrayList = NULL;
    auxArrayList = (ArrayList *) malloc(sizeof(ArrayList));
    auxArrayList->data = NULL;
    auxArrayList->data = (void **) malloc(sizeof(void*) * 2);
    auxArrayList->capacity = 2;
    auxArrayList->size = 0;
    return auxArrayList;
}

void append(ArrayList * l, void * data){
    if (l->size > l->capacity - 1)
    {
        l->data = (void **) realloc(l->data, sizeof(void*) * l->capacity * 2);
        l->capacity *= 2;
    }
    
    l->data[l->size] = data;
    (l->size)++;
}

void push(ArrayList * l, void * data, int i){
    if (i > l->size - 1)
        return;
    
    if (l->size == l->capacity)
    {
        l->data = (void **) realloc(l->data, sizeof(void*) * l->capacity * 2);
        l->capacity *= 2;
    }

    for (int j = l->capacity - 1; j != i;j--)
        l->data[j] = l->data[j-1];

    l->data[i] = data;
    (l->size)++;
}

void* pop(ArrayList * l, int i){
    if (l->size == 0)
        return NULL;
    
    if (i < 0)
            i = l->size + i;
    
    void* aux = l->data[i];
    
    for (int j = i; j < l->size - 1; j++)
        l->data[j] = l->data[j + 1];
    
    (l->size)--;
    
    return aux;
}

void* get(ArrayList * l, int i){
    if (i>=l->capacity)
        return NULL;
    else
    {
        if (i < 0)
            i = l->size + i;

        return l->data[i];
    }
}

int get_size(ArrayList * l){
    int cont = 0;
    
    for (int i = 0; i < l->capacity || l->data[i] == NULL; i++)
        cont++;
    
    l->size = cont;
    
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
