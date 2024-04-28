#include <stdio.h> //printf
#include <stdlib.h> //rand & srand
#include <string.h> //strcat, strcpy
#include <time.h> //seeding random

// Function to concatenate words and form a sentence
void concatenateWords(char* result, const char* word) {
  strcat(result, " "); // Add a space between words
  strcat(result, word);
}

int main() {
      // Seed the random number generator
  srand(time(NULL));

      // Arrays of pointers to char
  char* article[] = {"the", "a", "one", "some", "any"};
  char* noun[] = {"boy", "girl", "dog", "town", "car"};
  char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
  const char* preposition[] = {"to", "from", "over", "under", "on"};

      // Variables for sentence generation
  char sentence[1000]; // Array to hold the entire sentence
  int i;

      // Generate 20 sentences
  for (i = 1; i <= 20; i++) {
            // Clear the sentence array
    sentence[0] = '\0';

            // Capitalize the first letter of the sentence
    char firstWord[10];
    strcpy(firstWord, article[rand() % 5]); // Select a random article
    firstWord[0]-=32; // Capitalize the first letter by decrementing by 32 in char (capitalizes a lowercase letter char)
    strcat(sentence, firstWord);

            // Concatenate words to form the rest of the sentence
    concatenateWords(sentence, noun[rand() % 5]);
    concatenateWords(sentence, verb[rand() % 5]);
    concatenateWords(sentence, preposition[rand() % 5]);
    concatenateWords(sentence, article[rand() % 5]);
    concatenateWords(sentence, noun[rand() % 5]);

            // Append a period at the end of the sentence
    strcat(sentence, ".");

            // Display the generated sentence
    printf("Sentence %d: %s\n", i, sentence);
  }

  return 0;
}

