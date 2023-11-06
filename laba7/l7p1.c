#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char input_string[1000]; // Максимальная длина входной строки
    char word[100]; // Максимальная длина слова
    char shortest_word[100]; // Переменная для хранения самого короткого слова
    int shortest_length = 1000; // Начальное значение для длины самого короткого слова
    bool inside_word = false; // Флаг, указывающий, находимся ли мы внутри слова

    fgets(input_string, sizeof(input_string), stdin);

    for (int i = 0; i < strlen(input_string); i++) {
        char c = input_string[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            word[strlen(word)] = c; // Добавляем символ к текущему слову
            inside_word = true;
        } else if (inside_word) {
            // Завершаем текущее слово и выводим его
            word[strlen(word)] = '\0';
            printf("%s\n", word);

            // Проверяем, является ли текущее слово короче самого короткого слова
            if (strlen(word) < shortest_length) {
                shortest_length = strlen(word);
                strcpy(shortest_word, word);
            }

            // Очищаем буфер для текущего слова
            memset(word, 0, sizeof(word));

            inside_word = false;
        }
    }

    // Выводим самое короткое слово
    if (shortest_length < 1000) {
        printf("\n");
        printf("%s\n", shortest_word);
    }

    return 0;
}
