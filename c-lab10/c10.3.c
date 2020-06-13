#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int ** Matrix(int** a, int n, int m) {
    const int min = -100, max = 100;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
    return a;
}
void PrintMatrixArray(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf(" A[%d][%d] - %d", i, j, a[i][j]);
        }
    }
}

int minimal(int ** array, int n, int m){
    int min = 100;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (min > array[i][j]){
                min = array[i][j];
            }
        }
    }

    return min;
}
int maximal(int ** array, int n, int m){
    int max = -100;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (max < array[i][j]){
                max = array[i][j];
            }
        }
    }

    return max;
}

int swap(int** array, int n, int m) {
    int min = minimal(array, n, m), max = maximal(array, n, m);
    array[0][0] = max;
    array[n-1][m-1] = min;
    return array;
}

int main() {
    printf("Enter column count: ");
    int m, n, k = NULL, p = NULL;
    scanf("%d", &m);
    printf("Enter rows count: ");
    scanf("%d", &n);
    int** a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("\nError dynamic memory.\n");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(m * sizeof(int));
        if (a == NULL) {
            printf("\nError dynamic memory.\n");
            return -1;
        }
    }
    a = Matrix(a, n, m);
    printf("\nGenerated array: ");
    PrintMatrixArray(a, n, m);
    printf("\nChanged array: ");
    PrintMatrixArray(swap(a, n, m), n, m);
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
    return 0;
}