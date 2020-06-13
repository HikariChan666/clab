#include <locale.h>
#include <stdio.h>
#include "windows.h"
int kk(int a, int d, int n) {
    if (n + 1 <= 1) return 0;
    printf(" %d ", (a));
    return (a + kk(a + d, d, n - 1));
}
int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    printf("%d ", kk(1, 2, 10));
    return 0;
}