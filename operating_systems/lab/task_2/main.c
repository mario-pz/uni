/*
    The program aims to perform word lookup in a "leksiko.txt" file based on a
    user-provided sentence. The user is prompted to enter a sentence, which is
   then tokenized into individual words. For each word in the sentence, a
   separate thread is created to perform a lookup in the "leksiko.txt" file.

    The "leksiko.txt" file is assumed to contain a list of words, with each word
   on a separate line. The program opens the file and reads each line to compare
   it against the words from the user's sentence. If a match is found, the
   program prints "Found: <word>". If a word is not found in the file, it prints
   "Not found: <word>".

    To achieve parallel execution and speed up the lookup process, the program
    creates a separate thread for each word in the sentence. Each thread is
    responsible for looking up a single word in the file. The threads execute
    concurrently, allowing for multiple word lookups to occur simultaneously.

    After creating all the threads, the program waits for each thread to finish
   its execution using the pthread_join function. Once all the threads have
   completed, the program closes the "leksiko.txt" file and terminates.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
  FILE *file;
  char *word;
} ThreadData;

void *lookupWord(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  FILE *file = data->file;
  char *word = data->word;

  char line[MAX_LENGTH];
  int found = 0;

  // Reset the file pointer to the beginning of the file
  rewind(file);

  // Iterate through each line in the file
  while (fgets(line, MAX_LENGTH, file) != NULL) {
    // Remove newline character from the line
    line[strcspn(line, "\n")] = '\0';

    // Check if the word matches the line
    if (strcmp(word, line) == 0) {
      printf("Found: %s\n", word);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Not found: %s\n", word);
  }

  pthread_exit(NULL);
}

int main() {
  char sentence[MAX_LENGTH];
  printf("Enter a sentence: ");
  fgets(sentence, MAX_LENGTH, stdin);

  // Replace the newline character with a null terminator
  sentence[strcspn(sentence, "\n")] = '\0';

  char *token = strtok(sentence, " ");

  // Open the "leksiko.txt" file
  FILE *file = fopen("leksiko.txt", "r");
  if (file == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  // Array to store thread IDs
  pthread_t threads[MAX_LENGTH];

  int count = 0;

  while (token != NULL) {
    // Create a thread for each word
    ThreadData *data = (ThreadData *)malloc(sizeof(ThreadData));
    data->file = file;
    data->word = token;

    pthread_create(&threads[count], NULL, lookupWord, (void *)data);

    // Move to the next word
    token = strtok(NULL, " ");

    count++;
  }

  // Wait for all threads to finish
  for (int i = 0; i < count; i++) {
    pthread_join(threads[i], NULL);
  }

  // Close the file
  fclose(file);

  return 0;
}
