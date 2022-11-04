#include <stdlib.h>
#include <stdio.h>
#define TABSIZE 1000

int rand (void);

// the partition function

int partition(int list[], int left, int right){
    int i = left; // the index 
    int x = left; // the pivot
    while (i <= right){
        if( list[i] < list[x] && x < i){
            int e = list[i];
            int y = i;
            for(y;y>x; y--){
                list[y] = list[y - 1];
            }
            list[x] = e;
            x += 1;
        }
        
        else
        {
            i += 1;
        }
        
    }

    return x;
}

// the quicksort recursive function

void quick_sort(int list[], int left, int right){
    if (left >= right){
        return;
    }
    int x = partition(list,left,right);
    quick_sort(list, left, x-1);
    quick_sort(list, x+1, right);

}

// the quicksort function for integers

void quicksort_int(int *tab, unsigned int nelem){
    quick_sort(tab, 0, nelem - 1);
}

int main(){
    int list[TABSIZE], x;
    for(x = 0; x< TABSIZE;x++){
        list[x] = rand()%TABSIZE;
    }
    
    quicksort_int(list, TABSIZE);
    
    for(x = 0; x< TABSIZE;x++){
        printf("%d ", list[x]);
    }
    
    
    return 0;
}