#include <stdio.h>
#include <string.h>
#include <ctype.h>


int counting(char *string, char *word) {
    int count = 0;

    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == word[0]){
            int countLetters = 0;
            for (int j = i, k = 0; string[j] != ' ' && j < strlen(string) && string[j]==word[k]; ++j, k++) {
                countLetters++;
                i = j;
            }
            if (countLetters == strlen(word)) count++;
        }
    }

    return count;
}

int main() {
    char * string = "Clash of clans hack tool 2020";
    char * word = "clans";
    printf("%d", counting(string, word));
    return 0;
}