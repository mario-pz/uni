
#include <stdio.h>

int main(void) {
  int columns = 0;

  printf("Αριθμός γραμμών:");
  scanf("%d", &columns);

  // 1
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < i; j++)
      putchar('*');
    putchar('\n');
  }

  putchar('\n');

  // 2
  for (int i = columns; i > 0; i--) {
    for (int j = i; j > 0; j--)
      putchar('*');
    putchar('\n');
  }

  putchar('\n');

  // 3
  int k = 0;
  for (int i = 1; i <= columns; ++i, k = 0) {
    for (int space = 1; space <= columns - i; ++space) {
      putchar(' ');
    }
    while (k++ != 2 * i - 1) {
      (k == i) ? putchar('.') : putchar('*');
    }
    putchar('\n');
  }

  putchar('\n');

  for (int i = 1; i <= columns; i++) {
    for (int j = 1; j <= columns; j++) {
      if (i == 1 || i == columns || j == 1 || j == columns - i + 1 || i == j ||
          j == columns) {
        putchar('*');
      } else {

        putchar(' ');
      }
    }
    putchar('\n');
  }

  return 0;
}
