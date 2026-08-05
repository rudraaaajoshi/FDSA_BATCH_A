#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    char longest[50], word[50];
    int i = 0, j = 0, maxLen = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    while (1) {
        if (sentence[i] == ' ' || sentence[i] == '\0' || sentence[i] == '\n') {
            word[j] = '\0';

            if (j > maxLen) {
                maxLen = j;
                strcpy(longest, word);
            }

            j = 0;

            if (sentence[i] == '\0' || sentence[i] == '\n')
                break;
        } else {
            word[j++] = sentence[i];
        }

        i++;
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLen);

    return 0;
}