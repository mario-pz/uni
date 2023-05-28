#include <stdio.h>
#include <stdlib.h>
int main(void) {

  int N = 0;
  printf("Δώσε ακέραιο αριθμό επαναλήψεων:");
  scanf("%d", &N);

  int *content = (int *)malloc(sizeof(int) * N);

  int i = 0;
  do {
    int temp = 0;
    printf("Δώσε αριθμό:");
    scanf("%d", &temp);
    *(content + i++) = temp;
  } while (i < N);

  int j = 0;

  int mut_m_3 = 1;
  int mut_o_4 = 1;
  int neg_mut = 1;

  do {
    int temp = *(content + j++);

    printf("%d", temp);
    if (temp < 0) {
      neg_mut *= temp;
      printf("%d", neg_mut);
      continue;
    }

    if (temp % 3 == 0) {
      mut_m_3 *= temp;
    }

    if (temp % 2 == 0) {
      mut_o_4 *= temp;
    }

  } while (j < N);

  printf("Πλήθος αριθμών που δόθηκαν ως είσοδο: %d\n", N);
  printf("Μ.O των πολλαπλασιασμών του τρία: %d\n", mut_m_3 / N);
  printf("Το γινόμενο των πολλαπλασίων του 4: %d\n", mut_o_4);
  printf("Το γινόμενο των αρνητικών αριθμών: %d\n", neg_mut);

  free(content);
  return 0;
}
