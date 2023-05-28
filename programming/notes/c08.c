#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Να γραφεί συνάρτηση η οποία θα δέχεται ως όρισμα έναν πίνακα χαρακτήρων και
// θα επιστρέφει τη συχνότητα του κάθε κεφαλαίου χαρακτήρα του λατινικού
// αλφάβητου μέσα σε αυτόν.
unsigned *find_letter_freq(char const *const);

int main() {
  char const *const text = "MY STARS";

  unsigned *letter_counts = find_letter_freq(text);
  for (int i = 0; i < 26; i++) {
    if (letter_counts[i] > 0)
      printf("%c: %d\n", 'A' + i, letter_counts[i]);
  }
  free(letter_counts);
  return 0;
}

unsigned *find_letter_freq(char const *const str) {
  unsigned *freq_array = (unsigned *)calloc(26, sizeof(unsigned));

  {
    char const *ch = str;
    while (*ch != '\0') {
      if (*ch >= 'A' && *ch <= 'Z') {
        freq_array[*ch - 'A']++;
      }
      ch++;
    }
  }

  return freq_array;
}
