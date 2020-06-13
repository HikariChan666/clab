#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdarg.h>
#include "windows.h"
#include <string.h>
int* qq(int n) {
	const int max = 100, min = -100;
	int *a = (int*)malloc(n*sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++){
		a[i] = min + rand() % (max - min + 1);
	}
	return a;
}
int sum(int n, int* a) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			counter += a[i];
		}
	}
	return counter;
}
int sum1(int n, int* a) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0 && a[i+1]<0) {
			while (a[i + 1] < 0) {
				counter += a[i+1];
				i++;
			}
			break;
		}
	}
	return counter;
}
void result(int* a,int n) {
	for (int i = 0; i < n; i++) {
		printf(" [%d] ", a[i]);
	}
}
int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int n,*a;
	n:
	printf("Enter n - ");
	scanf("%d", &n);
	if (n < 2) {
		printf("Error. Array must contain more than 1 element. \n");
		goto n;
	}
	a = qq(n);
	result(a, n);
	printf("\n sum - %d", sum(n, a));
	printf("\n sum1 - %d", sum1(n, a));
	return 0;
}