#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LAB1 80
#define LAB2 40

typedef struct university_notes {//for second lab
    char fac[LAB2][LAB2];
    char spec[LAB2][LAB2];
    int am;
} unotes;

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
unotes *init_unote();
void show_un(unotes * un);
void sort_un(unotes * un);
void sort_un(unotes * un);
void read_data(unotes *un);

int main() {
    int choice;
    while(1) {
        printf("Choose the lab you`d like to review. Enter '6' to stop.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: lab1();
                break;
            case 2: lab2();
                break;
            case 3: lab3();
                break;
            case 4: lab4();
                break;
            case 5: lab5();
                break;
            default: return (0);
        }
    }

    return (0);
}
unotes *init_unote() {
    unotes *temp = (unotes *) malloc(sizeof(unotes));
    temp->am = -1;

    return(temp);
}
void read_data(unotes *un) {
    FILE* f;

    if((f = fopen("2ndfac.txt", "r")) == NULL) {
        fprintf(stderr,"Error reading 1st file");
        return;
    }
    while(!feof(f) && un->am < LAB2) {
        un->am++;
        fgets(un->fac[un->am], LAB2, f);
    }
    fclose(f);

    if((f = fopen("2ndspec.txt", "r")) == NULL) {
        fprintf(stderr,"Error reading 2nd file");
        return;
    }
    int i = -1;
    while(!feof(f) && i <= un->am) {
        i++;
        fgets(un->spec[i], LAB2, f);
    }
    fclose(f);
    un->am--;
}
void sort_un(unotes * un) {
    for(int k = 0; k < un->am; k++) {
        int small = k;
        for(int i = k; i < un->am; i++) {
            if(strcmp(un->fac[i], un->fac[i+1]) > 0)
              small = i + 1;
        }
        if(small != k) {
        char temp[LAB2];

        strcpy(temp, un->fac[k]);
        strcpy(un->fac[k], un->fac[small]);
        strcpy(un->fac[small], temp);

        strcpy(temp, un->spec[k]);
        strcpy(un->spec[k], un->spec[small]);
        strcpy(un->spec[small], temp);
      }
    }
}
void show_un(unotes * un) {
    for(int i = 0; i <= un->am; i++) {
        printf("%d|%s", i + 1, un->fac[i]);
        printf("    %s\n", un->spec[i]);
    }
}
void lab1() {
    FILE *f;
    int i = 0;
    char s[LAB1];
    if((f = fopen("1st.txt", "r")) == NULL) {
        fprintf(stderr, "Error reading file");
        return;
    }
    while(!feof(f)) {
        fgets(s, LAB1, f);
        if(strlen(s) > i) i = strlen(s);
    }
    rewind(f);
    while(!feof(f)) {
        fgets(s, LAB1, f);
        if(strlen(s) == i) {
            printf("The longest string in file: %s", s);
            break;
        }
    }
    fclose(f);
}
void lab2() {
    unotes * un = init_unote();
    char str[LAB2];

    read_data(un);
    printf("First condition\n");

    show_un(un);
    while(1) {
      fflush(stdin);
      printf("Enter faculty, to stop - '6'\n");

      fgets(str, LAB2, stdin);
      if(str[0] == '6') break;
      strcpy(un->fac[un->am + 1], str);

      printf("Enter speciality\n");
      fgets(str, LAB2, stdin);
      strcpy(un->spec[un->am + 1], str);

      un->am++;
    }

    sort_un(un);
    printf("Second condition\n");
    show_un(un);
    free(un);
  }
void lab3() {

}
void lab4() {

}
void lab5() {

}
