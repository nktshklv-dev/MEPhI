#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для поиска строк с последним словом по алфавиту
void findLastWords() {
    int line_number = 1;
    int max_line_number = 0;
    char last_word[21] = "";
    char current_word[21];

    while (1) {
        int word_count = 0;
        int max_word = 0;
        int c;

        while ((c = fgetc(stdin)) != EOF && c != '\n' && word_count < 20) {
            if (isalpha(c)) {
                current_word[word_count++] = tolower(c);
                if (word_count > max_word) {
                    max_word = word_count;
                    current_word[max_word] = '\0';
                }
            } else if (word_count > 0) {
                word_count = 0;
            }
        }

        if (word_count > 0 && strcmp(current_word, last_word) > 0) {
            max_line_number = line_number;
            strcpy(last_word, current_word);
        }

        if (c == EOF) {
            break;
        } else if (c == '\n') {
            line_number++;
        }
    }

    rewind(stdin);

    fprintf(stdout, "%d ", max_line_number);
    line_number = 1;

    while (1) {
        int word_count = 0;
        int c;

        while ((c = fgetc(stdin)) != EOF && c != '\n' && word_count < 20) {
            if (isalpha(c)) {
                current_word[word_count++] = tolower(c);
            } else if (word_count > 0) {
                current_word[word_count] = '\0';

                if (line_number == max_line_number && strcmp(current_word, last_word) == 0) {
                    fprintf(stdout, "%d ", line_number);
                }

                word_count = 0;
            }
        }

        if (c == EOF) {
            break;
        } else if (c == '\n') {
            line_number++;
        }
    }

    fprintf(stdout, "\n");
}

// Функция для создания текстовой гистограммы гласных букв
void createVowelHistogram() {
    int vowelCounts[6] = {0};
    int c;

    while ((c = fgetc(stdin)) != EOF) {
        if (isalpha(c)) {
            switch (tolower(c)) {
                case 'a':
                    vowelCounts[0]++;
                    break;
                case 'e':
                    vowelCounts[1]++;
                    break;
                case 'i':
                    vowelCounts[2]++;
                    break;
                case 'o':
                    vowelCounts[3]++;
                    break;
                case 'u':
                    vowelCounts[4]++;
                    break;
                case 'y':
                    vowelCounts[5]++;
                    break;
                default:
                    break;
            }
        }
    }

    fprintf(stdout, "a ");
    for (int i = 0; i < vowelCounts[0] / 3; i++) {
        fprintf(stdout, "*");
    }
    if (vowelCounts[0] % 3 == 2) {
        fprintf(stdout, "*");
    }
    fprintf(stdout, " %d\n", vowelCounts[0]);

    fprintf(stdout, "e ");
    for (int i = 0; i < vowelCounts[1] / 3; i++) {
        fprintf(stdout, "*");
    }
    if (vowelCounts[1] % 3 == 2) {
        fprintf(stdout, "*");
    }
    fprintf(stdout, " %d\n", vowelCounts[1]);

    fprintf(stdout, "i ");
    for (int i = 0; i < vowelCounts[2] / 3; i++) {
        fprintf(stdout, "*");
    }
    if (vowelCounts[2] % 3 == 2) {
        fprintf(stdout, "*");
    }
    fprintf(stdout, " %d\n", vowelCounts[2]);

    fprintf(stdout, "o ");
    for (int i = 0; i < vowelCounts[3] / 3; i++) {
        fprintf(stdout, "*");
    }
    if (vowelCounts[3] % 3 == 2) {
        fprintf(stdout, "*");
    }
    fprintf(stdout, " %d\n", vowelCounts[3]);

    fprintf(stdout, "u ");
    for (int i = 0; i < vowelCounts[4] / 3; i++) {
        fprintf(stdout, "*");
    }
    if (vowelCounts[4] % 3 == 2) {
        fprintf(stdout, "*");
    }
    fprintf(stdout, " %d\n", vowelCounts[4]);

    fprintf(stdout, "y ");
    for (int i = 0; i < vowelCounts[5] / 3; i++) {
        fprintf(stdout, "*");
    }
    if (vowelCounts[5] % 3 == 2) {
        fprintf(stdout, "*");
    }
    fprintf(stdout, " %d\n", vowelCounts[5]);
}

int main() {
    findLastWords();
    createVowelHistogram();

    return 0;
}
