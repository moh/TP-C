#include <stdlib.h>
#include <stdio.h>

#ifndef QUICKSORT_GENERIC
#include "quicksort_generic.h"
#endif

void * partition(void *left, void *right, int size, int(*compar)(const void *, const void *)){
    char * i = (char *) left;
    char * x = (char *) left;
    char * r = (char *) right;
    while(i <= r){
        int comp = compar(i, x);
        if((comp < 0) && (x < i)){
            // this part is to copy the value that start in i to e 
            char e[size];
            for(int index = 0; index < size; index++){
                e[index] = *(i + index);
            }
            // end copy
            // this part is to decale the part before i
            char * y = i + size - 1;
            for(;y >= (x + size); y--){
                *y = *(y - size);
            }
            // end decalation
            // part of copying e (previous i) to the place x 
            for(int index = 0; index < size; index++){
                *(x + index) = e[index];
            }
            // end copying
            // increment x by size bytes
            x += size;
        }
        else{
            i += size;
        }
    }
    return x;
}

void quicksort_part(void *left, void *right, int size, int(*compar)(const void *, const void *)){
    if(left >= right) return;
    char * x = (char *) partition(left, right, size, compar);
    quicksort_part(left, x - size, size, compar);
    quicksort_part(x + size, right, size, compar);
}

void quicksort(void *base, int nelem, int size,
                   int(*compar)(const void *, const void *))
{
    char * first = (char *)base;
    char * end = first + (nelem - 1)*size;
    quicksort_part(first, end, size, compar);
}