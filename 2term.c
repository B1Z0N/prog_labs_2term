#include <stdio.h>
void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
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
void lab1() {

}
void lab2() {

}
void lab3() {

}
void lab4() {

}
void lab5() {

}
