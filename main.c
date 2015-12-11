// Simple Scheme Compiler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double (*operator)(int, int);

int parse_number(char **Ptr);
operator parse_operator(char **Ptr);
double add (int left, int right);
double sub (int left, int right);
double mul (int left, int right);
double divio (int left, int right);


void error ();

/* Überprüfen des Operators */
operator parse_operator(char **Ptr) {
    if ((**Ptr) == '+') {
        return add;
    }
    if ((**Ptr) == '-') {
        return sub;
    }
    if ((**Ptr) == '*') {
        return mul;
    }
    if ((**Ptr) == '/') {
        return divio;
    }
}
/* addition funktion */
double add (int left, int right) {
    return left+right;
}
/* sub funk */
double sub (int left, int right) {
    return left-right;
}
/* mul funk */
double mul (int left, int right) {
    return left*right;
}
/* div funk */
double divio (int left, int right) {
  return left/right;
}
/* Numern zusammenzählen */
int parse_numb(char **Ptr, int number) {

    if ((**Ptr) >= '0' && (**Ptr) <= '9') {
        number = number*10 + ((**Ptr) - '0');
        return number;
    }
    error();
}
/* error func */
void error () {
    printf("fehler");
    exit(0);
}
 
int main()
{
 
    char *zPtr  = NULL;
    operator op = NULL;
    int number  = 0;
    int erg     = 0;
    int buffer_size = 0;
    int n=0;
    FILE *fp = fopen("./data", "r");

    if (fp == NULL) {
      error();
    }

    fseek(fp, 0, SEEK_END);
    buffer_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("size of buffer: %i\n", buffer_size);
    
    char *content_buffer = malloc(buffer_size);

    if (content_buffer == NULL) {
      error();
    }
    
    fgets(content_buffer, buffer_size+1, fp);

    printf("buffer content: %s\n",content_buffer);


    printf("\nPos. \t read number \t memory ");
    
    for(;n < buffer_size ;n++) {
        /* Leerzeichen */
        if(*content_buffer == ' ') {
            printf("\n-----------------------------------");
            zPtr=content_buffer;
            content_buffer++;
        continue;
        }
      
        /* Operatoren */
        if( op == NULL) {
            op = parse_operator(&content_buffer);
            content_buffer++;
            continue;
        }
        
        /* Prozess */
        if( content_buffer == (zPtr+1)) {
            /* Überprüfen ob eine Zahl im Speicher vorhanden ist */
            if(erg == 0) {
                erg = number;
                number = 0;  /* Zwischenspeicher auf Null setzten */
            }
            else {
                erg = op(erg, number); /* Berrechnung der neuen Zahl */
                number = 0; /* Zwischenspeicher auf Null setzten */
            }
        }
        /* number parse */
        
        number = parse_numb(&content_buffer,number);
        printf("\n%i \t %d \t\t %d ", n, number, erg);
        content_buffer++;
    }

    printf("\n-----------------------------------");
    
    erg = op(erg, number);

    printf("\nfinal result: %2d \n", erg);

    free(fp);
    
    return 0;
}







