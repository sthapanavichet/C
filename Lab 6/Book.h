#define MAX_STR 64
#define NUM_BOOKS 6
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char name[MAX_STR];
    char author[MAX_STR];
    int year;
    float price;
};
// functions prototype
void getBook(char *token, FILE *file);
double getBookDec(FILE *file);
int longestNameLength(struct Book *books);
int longestAuthorLength(struct Book *books);
