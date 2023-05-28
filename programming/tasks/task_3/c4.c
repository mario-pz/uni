#include <stdio.h>

int main(void) {
  unsigned int month;

  printf("Δώσε τον αριθμό του μήνα (1-12):");
  scanf("%d", &month);

  switch (month == 0) {
  case 1:
    month = 1;
  }

  switch (month > 12) {
  case 1:
    month = 12;
  }

  unsigned int year;
  printf("Δώσε έτος:");
  scanf("%d", &year);

  switch (month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    printf("31 Μέρες\n");
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    printf("30 Μέρες\n");
    break;

  case 2:
    printf("28/29 Μέρες\n");
    break;
  }
}
