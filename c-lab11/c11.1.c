#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void append(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

int * stringToInteger(char * string, int n){//String array {1 2 0 4} to Integer array
    int * integerArray = calloc(n, sizeof(int));
    if (integerArray == NULL){printf("\nMemory error\n");return 0;}
    for (int i = 0, p = 0; p<n;i++, p++){
        char * tempChar = (char*)malloc(10*sizeof(char ));
        if (tempChar == NULL){printf("\nMemory error\n");return 0;}
        for (int d = 0; string[i]!=' ' && string[i]!='\0'; i++, d++){
            tempChar[d] = string[i];
        }
        *(integerArray+p) = atoi(tempChar);
        free(tempChar);
    }
    return integerArray;
}
void addStrToFile(char * filePATH, char * str){
    FILE * file = NULL;
    file = fopen(filePATH, "at+");
    if (file != NULL){
        printf("\nFile \"%s\" successfully opened.", filePATH);
        fputs(str, file);
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
bool isTriangular(int * array){
    int a = array[0], b = array[1], c = array[2];
    if (a + b > c && a + c > b && b + c > a ) return true;
    return false;
}
int main(){
    char * filePATH = "..//lab-11-1.txt";
    char * file = openFile(filePATH);
    printf("\nFile context: %s", file);
    int * integerArray = stringToInteger(file, 3);
    if (isTriangular(integerArray)) {
        printf("\n is triangular");
        addStrToFile(filePATH," true");
        return 0;
    }
    puts(file);
    printf("\n Is not triangular.");
    addStrToFile(filePATH," false");
    return 0;
}