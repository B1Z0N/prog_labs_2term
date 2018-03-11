#include "2term.h"

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
unote *init_unote() {
    unote *temp = (unote *) malloc(sizeof(unote));

    return(temp);
}
int read_data(unote *un[]) {
    FILE* f;
    int length = -1;
    if((f = fopen("2ndfac.txt", "r")) == NULL) {
        fprintf(stderr,"Error reading 1st file");
        exit(-1);
    }
    while(!feof(f) && length < LAB2) {
        length++;
        fgets(un[length]->fac, LAB2, f);
    }
    fclose(f);

    if((f = fopen("2ndspec.txt", "r")) == NULL) {
        fprintf(stderr,"Error reading 2nd file");
        exit(-1);
    }
    int i = -1;
    while(!feof(f) && i < length) {
        i++;
        fgets(un[i]->spec, LAB2, f);
    }
    fclose(f);

    return(length - 1);
}
void sort_un(unote * un[], int length) {
    char temp1[LAB2];
    int temp2;
    for(int i = 0; i < length; i++) {
        temp2 = i;
        for(int j = i + 1; j <= length; j++)
            if(strcmp(un[temp2]->fac, un[j]->fac) > 0) 
                temp2 = j; 
        
        strcpy(temp1, un[temp2]->fac);
        strcpy(un[temp2]->fac, un[i]->fac);
        strcpy(un[i]->fac, temp1);

        strcpy(temp1, un[temp2]->spec);
        strcpy(un[temp2]->spec, un[i]->spec);
        strcpy(un[i]->spec, temp1);
    }
}
void show_un(unote * un[], int length) {
    for(int i = 0; i <= length; i++) {
        printf("%d|%s", i + 1, un[i]->fac);
        printf("    %s\n", un[i]->spec);
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
    unote *un[LAB2];
    for(int i = 0; i < LAB2; i++)
        un[i] = init_unote();

    char str[LAB2];
    int i = read_data(un);

    printf("First condition\n");
    show_un(un, i);

    while(1) {
      fflush(stdin);

      printf("Enter faculty, to stop - '6'\n");
      fgets(str, LAB2, stdin);
      if(str[0] == '6') break;
      strcpy(un[i + 1]->fac, str);

      printf("Enter speciality\n");
      fgets(str, LAB2, stdin);
      strcpy(un[i + 1]->spec, str);

      i++;
    }
    printf("%d\n", i);
    sort_un(un, i);
    printf("Second condition\n");
    show_un(un, i);

    for(int s = 0; s <= i; s++)
        free(un[s]);
  }
void lab3() {

}
void lab4() {

}
void lab5() {

}
