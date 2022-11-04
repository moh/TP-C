#include <stdlib.h>
#include <stdio.h>

#ifndef NOBELPRIZE
#include "nobel_prize.h"
#endif


/* function to copy an array to the other */

void copy_array(char a1[], char a2[], int size){
    for(int x = 0; x < size; x++){
        a1[x] = a2[x];
    }
}


Nomine_s creat_nomin(int date, char domaine[], char name[], int birth[], char nationality[], char gender[]){
    Nomine_s person;

    person.date = date;
    copy_array(person.domaine, domaine, MAXDOMAINE);
    copy_array(person.name, name, MAXNAME);   
    person.birth_day = birth[2];
    person.birth_month = birth[1];
    person.birth_year = birth[0];
    copy_array(person.birth_nationality, nationality, MAXNATIONALITY);
    copy_array(person.gender, gender, MAXGENDER);
    return person;
    
}


/* transform the date to integer*/
int date_to_int(char date[]){
    int sum = 0;
    int d = 1000;
    for(int x = 0; x < 4; x++){
        sum += (date[x] - 48)*d;
        d = d/10;
    }
    return sum;
}

/* transform the ligne containing the winner information to a variable of type Nomine_s*/
Nomine_s ligne_to_data(char ligne[]){
    char date_array[4] = {ligne[0],ligne[1],ligne[2],ligne[3]};
    int date = date_to_int(date_array);
    int x,y;
    char domaine[MAXDOMAINE], c;


    for(x = 0; x< MAXDOMAINE; x++){
        c = ligne[6 + x];
        if(c == '"') {domaine[x]='\0';break;}
        domaine[x] = c;
    }
    
    x += 3 + 6; /* to go to the name " "  the 3 represent "\t" */
    char name[MAXNAME]; /* len of name now 90 should be 50*/
    for(y = 0; y< MAXNAME; y++){
        c = ligne[x + y];
        if(c == '"') {name[y]='\0';break;}
        name[y] = c;
    }
    
    x += 3 + y;

    char birth_date[8] = {ligne[x],ligne[x+1],ligne[x+2],ligne[x+3],
    ligne[x+5],ligne[x+6],ligne[x+8],ligne[x+9]};

    int birth_parts[] = {(birth_date[0] - 48)*1000 + (birth_date[1] - 48)*100 + (birth_date[2] - 48)*10 + (birth_date[3] - 48), (birth_date[4] - 48)*10 + (birth_date[5] - 48), (birth_date[6] - 48)*10 + (birth_date[7] - 48)};
    
    x += 9 + 13 + 1;

    char nationality[MAXNATIONALITY];
    for(y = 0; y < MAXNATIONALITY; y++){
        c = ligne[x + y];
        if(c == '"') {nationality[y]='\0';break;}
        nationality[y] = c;
    }
    
    x += y + 3;

    char gender[MAXGENDER];
    for(y = 0; y < MAXGENDER; y++){
        c = ligne[x + y];
        if(c == '"') {gender[y]='\0';break;}
        gender[y] = c;
    }

    return creat_nomin(date, domaine, name, birth_parts, nationality, gender);
}

int ConstruireTableaux(Nomine_s winners[]){
    char ligne[200], c; /* variable to containe a line*/
    int total = 0, len = 0;
    Nomine_s person;

    while(1){
        c = getchar();
        if(c == EOF) break;
        if(c == '\n'){
            if(len != 0){
                person = ligne_to_data(ligne);
                winners[total] = person;
                total += 1;
                len = 0;
            }
        }
        else{
            ligne[len] = c;
            len += 1;
        }
        
    }
    return total;
}

int CompareNomineParAgeDObtention(const void *pv1, const void *pv2){
    Nomine_s * p1 = (Nomine_s *)pv1;
    Nomine_s * p2 = (Nomine_s *)pv2;
    if(p1->birth_year > p2->birth_year) return 1;
    else if(p1->birth_year == p2->birth_year){
        if(p1->birth_month > p2->birth_month) return 1;
        else if(p1->birth_month == p2->birth_month){
            if(p1->birth_day > p2->birth_day)return 1;
            else if(p1->birth_day < p2->birth_day) return -1;
            return 0;
        }
        return -1;
    }
    return -1;
}
