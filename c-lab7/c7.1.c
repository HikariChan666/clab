#include <stdio.h>
#include <locale.h>
#include "windows.h"
#define n 6
int qq(int* a, int nn) {
    int counter = 0;
    for (int i = 1; i <= nn; i++) {
        for (int j = i; a[j] == a[i]; j++) {
            if (a[j + 1] != a[i]) {
                i = j;
                counter++;
                break;
            }
        }
    }
    return counter;
}
int SortArray(int* a, int nn) {
    int temp=0;
    for (int j = 0; j < nn*nn; j++){
        for (int i = 0; i < nn; i++) {
            if (a[i] > a[i + 1] && i + 1 != nn + 1) {
                temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
            }
        }
    }
    return a;
}
int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    int a[n + 1], * b = a;
    for (int i = 1; i <= n; i++) {
        printf("Enter a[%d] - ", i);
        scanf("%d", &b[i]);
    }
    printf("Number of different elements - %d", qq(SortArray(b, n), n));
    return 0;
}