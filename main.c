#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef (*operator)(int, int);

int parse_number(char **Ptr);
int parse_operator(char **Ptr);
double add (int left, int right);
double sub (int left, int right);
double mul (int left, int right);
double divio (int left, int right);
void error ();

/* Überprüfen des Operators */
int parse_operator(char **Ptr) {
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
    char sArray[] = "+ 16 2 2 2";
    char *sPtr  = sArray;
    char *zPtr  = sArray;
    operator op = NULL;
    int number  = 0;
    int erg     = 0;

    puts(sArray);

    for(;*sPtr !='\0';sPtr++) {
        /* Leerzeichen */
        if(*sPtr == ' ') {
            /* Zwischen Zeiger wird auf akuelle pos gesetzt -> wird benötigt um Zahlen zu trennen */
            zPtr = sPtr;
           continue;
        }
        /* Operatoren */
        if( op == NULL) {
            op = parse_operator(&sPtr);
            continue;
        }
        /* Prozess */
        if (sPtr == (zPtr+1)) {
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
        number = parse_numb(&sPtr,number);
    }

    erg = op(erg, number);

    printf("\ndone: %2d \n", erg);

    return 0;
}


/* Funktionen um Datei zu öffnen bzw neu anlegen bzw erstellen bzw lesen */

void file_open_funktion () {
FILE *PTR
}
void file_read_funktion () {

}
void file_write_funktion () {

}







