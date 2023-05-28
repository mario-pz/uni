#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_words(char *, char *, int, int);
int read_words(FILE *, char **, unsigned int);
void free_array(char **, unsigned int);

void horizontal_search(char **, char **, int, int);
void vertical_search(char **, char **, int, int);

void diagonal_search(char **, char **, int, int);

void inverse_diagonal_search(char **, char **, int, int);

int main(int argc, char **argv) {
  if (argc != 2) {
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  unsigned int matrix_rows, matrix_cols;
  fscanf(fp, "%u,%u\n", &matrix_rows, &matrix_cols);
  char **matrix = (char **)calloc(matrix_rows, sizeof(char *));
  read_words(fp, matrix, matrix_rows);

  unsigned int number_of_words;
  fscanf(fp, "%u\n", &number_of_words);
  char **words = (char **)calloc(number_of_words, sizeof(char *));
  read_words(fp, words, number_of_words);

  horizontal_search(matrix, words, matrix_rows, number_of_words);

  vertical_search(matrix, words, matrix_rows, number_of_words);

  diagonal_search(matrix, words, matrix_cols, number_of_words);

  inverse_diagonal_search(matrix, words, matrix_cols, number_of_words);

  free_array(matrix, matrix_rows);
  free_array(words, number_of_words);
  fclose(fp);

  return 0;
}

void find_words(char *word_a, char *word_b, int size, int line) {
  // printf("Comparing %s with %s\n", word_a, word_b);
  int is_word = 0;
  for (unsigned int i = 0; i < size; i++) {
    // printf("%c != %c\n", word_a[i], word_b[i]);
    if (word_a[i] != word_b[i])
      is_word = -1;
  }
  if (is_word == 0)
    printf("%s FOUND in line %d\n", word_a, line + 1);
}

void horizontal_search(char **matrix, char **words, int matrix_rows,
                       int number_of_words) {
  for (int i = 0; i < matrix_rows; i++) {
    for (int j = 0; j < number_of_words; j++) {
      find_words(matrix[i], words[j], matrix_rows, i);
    }
  }
}

void vertical_search(char **matrix, char **words, int matrix_rows,
                     int number_of_words) {

  for (int i = 0; i < matrix_rows; i++) {
    for (int j = 0; j < number_of_words; j++) {
      // printf("(%s, %c)\n", words[j], matrix[i][j]);
      int is_word = 0;
      for (int k = 0; k < strlen(words[j]) - 1; k++) {
        if (words[j][k] != matrix[k][i]) {
          is_word = -1;
        }
        // printf("%c != %c is %d\n", words[j][k], matrix[k][i], is_word);
      }

      // putchar('\n');

      if (is_word == 0)
        printf("%s FOUND in column %d \n", words[j], i + 1);
    }
  }
}

void inverse_diagonal_search(char **matrix, char **words, int matrix_cols,
                             int number_of_words) {
  for (int w = 0; w < number_of_words; w++) {
    int is_word = 0;
    int k = 0;
    for (int j = 0; j < matrix_cols; j++) {
      // printf("%c != %c\n", matrix[k][j], words[w][j]);
      if (words[w][j] != matrix[k][j])
        is_word = -1;
      k++;
    }

    if (is_word == 0)
      printf("%s FOUND in column %d \n", words[w], k + 1);
  }
}

void diagonal_search(char **matrix, char **words, int matrix_cols,
                     int number_of_words) {
  for (int w = 0; w < number_of_words; w++) {
    int is_word = 0;
    int k = 0;
    for (int j = matrix_cols - 1; j >= 0; j--) {
      // printf("%c != %c\n", matrix[k][j], words[w][j]);
      if (words[w][k] != matrix[k][j])
        is_word = -1;
      k++;
    }

    if (is_word == 0)
      printf("%s FOUND in column %d \n", words[w], k + 1);
  }
}

int read_words(FILE *fp, char **strs, unsigned int rows) {
  if (!strs) {
    return 1;
  }
  for (unsigned int i = 0; i < rows; i++) {
    size_t size;
    if (getline(&strs[i], &size, fp) == -1) {
      for (unsigned int j = 0; j < rows; j++) {
        if (strs[j]) {
          free(strs[j]);
          strs[j] = NULL;
        }
      }
      return -1;
    }
  }
  return 0;
}

void free_array(char **array, unsigned int rows) {
  for (unsigned int i = 0; i < rows; i++) {
    if (array[i]) {
      free(array[i]);
    }
  }
  free(array);
}
