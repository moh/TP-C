#define MSORT

#define NMAXLINE 100 
#define NMAXCHAR 100

typedef struct Line_data Line;

struct Line_data{
    char chrs_line[NMAXCHAR];
};

/* read lines of the file and stock them in array passed in parameter, return number lines*/
int read_lines(Line[]);

/* compare two lines  */
int compare_lines(const void*, const void*);