#define NOBELPRIZE
/* the length max of the array of nomines*/
#define MAXTAB 1000

/* define of max length for struct attribute */
#define MAXDOMAINE 22
#define MAXNAME 90
#define MAXNATIONALITY 30
#define MAXGENDER 6

/* define type structure to represent the winner */
typedef struct Nobel_winner Nomine_s; 

struct Nobel_winner{
    int date;
    char domaine[MAXDOMAINE]; // the max length of domaine
    char name[MAXNAME]; // in the line 28 name is so long
    int birth_day, birth_month, birth_year;
    char birth_nationality[MAXNATIONALITY];
    char gender[MAXGENDER];
};

/* creat a Nomine_s object with the following datas */
Nomine_s creat_nomin(int, char[], char[], int[], char[], char[]);

/* fill the data of winner in an array of type Nomine_s, the data from standard input*/
int ConstruireTableaux(Nomine_s[]);

/* comapre the ages of two nobel prize winner */
int CompareNomineParAgeDObtention(const void*, const void*);