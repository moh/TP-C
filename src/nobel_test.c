#include "nobel_prize.h"
#include "quicksort_generic.h"
#include <stdio.h>

int rand (void);


int main(void){
    /* an array to hold the structs that represent the winner */
    
    Nomine_s Winners[MAXTAB];
    int number_winner = ConstruireTableaux(Winners);
    int x;
    quicksort(Winners, number_winner, sizeof(Nomine_s), CompareNomineParAgeDObtention);
    for(x = 0; x < number_winner; x++){
        printf("x = %d  name = %s et age = %d/%d/%d \n", x, Winners[x].name,Winners[x].birth_day,Winners[x].birth_month, Winners[x].birth_year);
    }
    return 0;
}
