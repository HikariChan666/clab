#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void append(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

char * swapChars(char *s, int a, int b) {
    if (s[a] == ' ') a++;
    if (s[b] == ' ') b--;
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
    return s;
}

char *changeWords(char *s) {
    char *newString = " ";
    for (int i = 0; s[i] != '\0'; ++i) {
        int len = strlen(newString);
        for (int j = i; s[j] != '\0' && s[j] != ' ' && !ispunct(s[j]); ++j) {
            append(newString, s[j]);
            if (s[j + 1] == ' ' || ispunct(s[j + 1]) || s[j+1] == '\0') {
                newString = swapChars(newString,i+1, j+1);
                i = j;
            }
        }
        if (len != strlen(newString))
        append(newString, ' ');
    }
    return newString;
}


char *string(char *s) {
    char *newString = " ";
    for (int i = 0; s[i] != '\0'; ++i) {
        for (int j = i; s[j] != '\0' && s[j] != ' '; ++j) {
            if (j == i && islower(s[j])) {
                for (int k = j; s[k] != ' ' && !ispunct(s[k]); ++k) {
                    if (s[k + 1] == ' ' && ispunct(s[k + 1])) {
                        swapChars(s, i, k + 1);
                    }
                }
                i = j;
            } else if (!islower(s[j])) {
                for (int k = j; s[k] != ' ' && !ispunct(s[k]); ++k) {
                    if (s[k + 1] == ' ' && ispunct(s[k + 1])) {
                        swapChars(s, i, k + 1);
                    }
                    append(newString, s[k]);
                    j = k;
                }
                append(newString, ' ');
                i = j;
                break;
            }
            i = j;
        }
    }
    return newString;
}

int main() {
    puts("Input array: Sdasda Sadsaf ldsfd SSdd sdasf");
    printf("Changed array: ");
    puts(string("Sdasda Sadsaf ldsfd SSdd sdasf"));
    printf("Changed array: ");
    puts(changeWords("Sdasda Sadsaf ldsfd SSdd sdasf"));
    return 0;
}