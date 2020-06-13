#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * string(char *s) {
    char * nString = "";
    for (int i = 0; i<strlen(s); i++) {
        nString[i] = (char)(((int)s[i])+2);
    }
    return nString;
}

int main() {
   char * s = " ";
    printf("\nEnter string: ");
    scanf ("%s", s);
    printf("\nEncrypted string: ");
    puts(string(s));
    return 0;
}