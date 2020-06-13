#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdarg.h>
#include <time.h>
#include "windows.h"
int** InitialMatrix(int** c, int n, int m) {
    const int MAX = 100, MIN = -100;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = MIN + rand() % (MAX - MIN + 1);
        }
    }
    return c;
}
int k(int** c, int n, int m) {
    int counter = 0;
    int* b = (int*)malloc(n * m * sizeof(int));
    b = MatrixToArray(c, n, m);
    b = SortArray(b, n, m);
    for (int i = 0; i < n * m; i++) {
        if (b[i + 1] != b[i]) {
            counter++;
        }
    }
    return counter;
}
int SortArray(int* a, int n, int m) {
    int temp = 0;
    for (int i = 0; i < n*m; i++) {
        for (int j = 0; j < n * m; j++) {
            if (a[j] > a[j + 1] && j+1 != n * m) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}

int MatrixToArray(int** a, int n, int m) {
    int d = 0;
    int* b = (int)malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[d] = a[i][j];
            d++;
        }
    }
    return b;
}
void qq(int** c, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("[%d]\t", c[i][j]);
        }
    }
}
int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i <= n; i++) {
        a[i] = (int**)malloc(m * sizeof(int));
    }
    int** d = InitialMatrix(a, n, m);
    qq(d, n, m);
    printf("\n Number of different elements in matrix - %d", k(d, n, m));
    return 0;
}