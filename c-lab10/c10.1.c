#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int sum(int * array, int n){
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i%2!=0){
            sum+=array[i];
        }
    }
    return sum;
}

int sumIn(int * array, int n){
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (array[i]>0){
            for (int j = i; array[i]<100 && j < n; ++j) {
                sum+=array[i];
            }
            return sum;
        }
    }

    return sum;
}

int * generateRandomArray(int n, int min, int max){
    int * array = (int * )calloc(n, sizeof(int));
    if (array == NULL) exit(2);
    for (int i = 0; i < n; ++i) {
        array[i] = min + rand() %(max- min +1);
    }
    return array;
}

int main() {
    srand(time(NULL));
    int n = 100, min = -100, max = 100;
    int * array = generateRandomArray(n, min, max);
    printf("The sum of the elements of the array with odd numbers - %d", sum(array, n));
    printf("\nThe sum of the element array located between the first and second positive elements. - %d", sumIn(array, n));
free(array);
    return 0;
}