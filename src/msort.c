#include <stdio.h>

#ifndef MSORT
#include "msort.h"
#endif


int read_lines(Line lines[NMAXLINE]){
    Line ligne;
    int total, nb_chr;
    char c;
    total = 0;
    nb_chr = 0;
    while(1){
        c = getchar();
        if((c == '\n') || (c == EOF)){
            ligne.chrs_line[nb_chr] = '\0';
            lines[total] = ligne;
            total++;
            nb_chr = 0;
            if(total >= NMAXLINE) return -1;
            if(c == EOF) {total-- ; break;}
        }
        else{
            ligne.chrs_line[nb_chr] = c;
            nb_chr++;
            if(nb_chr >= NMAXCHAR) return -1; 
            /* if we have characters more than max then return -1*/
        }
    }
    return total;
}


int compare_lines(const void* lv1, const void* lv2){
    Line * l1 = (Line * )lv1;
    Line * l2 = (Line * )lv2;
    int x;
    for( x = 0; x < NMAXCHAR; x++){
        if(l1->chrs_line[x] > l2->chrs_line[x]) return 1;
        if(l1->chrs_line[x] < l2->chrs_line[x]) return -1;
    }
    return 0;
}