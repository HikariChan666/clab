#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void append(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}
char * prepend(char * string, char * word){
    strcat(word, string);
    return word;
}
void addStrToFile(char * filePATH, char * str){
    FILE * file = NULL;
    file = fopen("..//lab-11-2.txt", "wb+");
    if (file != NULL){
        fputs(str, file);
        printf("\nSuccessfully added.");
        fclose(file);
    } else{printf("Error opening file.");exit(0);}
}

char * openFile(char * filePATH){
    FILE * file = NULL;
    file = fopen(filePATH, "r");
    char * tempString = (char *)malloc(250+sizeof(char));
    char * string = "";
    if (file != NULL){
        printf("\nFile \"%s\" successfully opened.", filePATH);
        do {
            fgets(tempString,250,file);
            strcat(string, tempString);
        } while (!feof(file));
        free(tempString); fclose(file);
        append(string, ' ');
        return string;
    } else{printf("Error opening file.");exit(0);}
}
int main(){
    char * word = "word ";
    char * filePATH = "..//lab-11-2.txt";
    char * file = openFile(filePATH);
    printf("\nFile context: %s", file);
    addStrToFile(filePATH, prepend(file, word));
    return 0;
}