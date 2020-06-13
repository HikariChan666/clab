#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char * author;
    char * name;
    char * distributor;
    int year;
}Book;
int main(){
    int n = 1;
    Book * book = (Book *)malloc(10 * sizeof(Book));
    for (int j = 0; j < 1; ++j) {
        char * temp = " ";
        printf("\nInput author author: ");
        scanf("%s", temp);
        book[j].author = temp;
        printf("\nInput author name: ");
        scanf("%s", temp);
        book[j].name = temp;
        printf("\nInput author distributor: ");
        scanf("%s", temp);
        book[j].distributor = temp;
        printf("\nInput author year: ");
        scanf("%d", &book[j].year);
    }

    printf("-------------------------------------------------\n");
    printf("Execution time of some programs that use parallel algorithms\n");
    printf("-------------------------------------------------\n");
    printf("| Name\t| Author | Distributor | Year |\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < 1; i++) {
        printf("| %s | %s | %s\t| %d\t|\n",book[i].name, book[i].author, book[i].distributor, book[i].year);
        printf("-------------------------------------------------\n");
    }
    return 0;
}