#include <stdio.h>
#include "msort.h"
#include "quicksort_generic.h"

int main(void){
    Line lines[NMAXLINE];
    int nb_lines = read_lines(lines);
    int x;
    if(nb_lines == -1){
        printf("Error found in reading files ! Length more then MAX \n");
        return 0;
    }
    quicksort(lines, nb_lines, sizeof(Line), compare_lines);
    for(int y = 0; y < nb_lines; y++){
        printf("%s \n", lines[y].chrs_line);
    }
    return 0;
}
