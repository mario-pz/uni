#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Να γραφεί συνάρτηση η οποία θα επιστρέφει ένα τυχαίο ακέραιο αριθμό μεταξύ
// δύο ορίων που δίνονται ως ορίσματα.
int r_range(int, int);

int main(void) {
  srand(time(NULL));
  printf("%d \n", r_range(1, 5));
  return 0;
}
int r_range(int lower, int upper) {
  return (rand() % (upper - lower + 1)) + lower;
}
