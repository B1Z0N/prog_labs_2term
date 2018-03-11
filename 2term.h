#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LAB1 80
#define LAB2 40
//for second lab
typedef struct university_note {
    char fac[LAB2];
    char spec[LAB2];
} unote;

unote *init_unote();
void show_un(unote * un[], int length);
void sort_un(unote * un[], int length);
int read_data(unote * un[]);

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
