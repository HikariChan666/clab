#include <stdio.h>
#include <locale.h>
#include "windows.h"
int A(int m, int n) {
    return (factorial(n) / factorial(n - m));
}
int factorial(int n) {
    if (n < 1) return 1;
    return n * factorial(n - 1);
}
int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    printf("%d ", A(2, 4));
    return 0;
}