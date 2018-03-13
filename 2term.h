#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//first lab

#define LAB1 80

void lab1();

//second lab

#define LAB2 40

void lab2();

typedef struct university_note {
    char fac[LAB2];
    char spec[LAB2];
} unote;

unote *init_unote();
void show_un(unote * un[], int length);
void sort_un(unote * un[], int length);
int read_data(unote * un[]);

//third lab

void lab3();

//fourth lab

void lab4();

//fifth lab

void lab5();

typedef struct node {
    struct node * next;
    int key;
} node;

node * init_node(int key);
void add_node(int key, node ** root);
int search_node(node * root, int key);
int list_len(node * root);

//end

