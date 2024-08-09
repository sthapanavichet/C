// Name: Sthapanavichet Long 
// Student ID: 1375802215
// email: slong17@myseneca.ca

#include "Book.h"


int main(void) {
    struct Book books[NUM_BOOKS];
    FILE *bookFile = NULL;
    bookFile = fopen("Book.txt", "r");

    if (bookFile == NULL) {
        printf("Error! File cannot be opened\n");
    }
    else {
        for(int i = 0; i < NUM_BOOKS; i++) { // input
            getBook(books[i].name, bookFile);
            getBook(books[i].author, bookFile);
            books[i].year = getBookDec(bookFile);
            books[i].price = getBookDec(bookFile);
        }
        fclose(bookFile);
        int longestName = longestNameLength(books); //longest length of name
        int longestAuthor = longestAuthorLength(books); //longest length of author
        int lengthToCenter = (longestName + longestAuthor + 5 + 5 + 3 - 16) / 2; // legth from left/right side to the center, 3 spaces between all category

        printf("%*s%s%-*s\n\n", lengthToCenter, "", "BOOK INFORMATION", lengthToCenter, ""); // center aligning the text 
        printf("%-*s %-*s %-5s %-5s\n", longestName, "NAME", longestAuthor,"AUTHOR", "YEAR", "PRICE"); // output
        for(int i = 0; i < NUM_BOOKS; i++) {
            printf("%-*s %-*s %-5d %-5.2f\n", longestName, books[i].name, longestAuthor, books[i].author, books[i].year, books[i].price);
        }
    }
    
    return 0;
}

void getBook(char *token, FILE *file) { //function for parsing (string)
    int index = 0;
    while(fgetc(file) != ';' && feof(file) == 0) {
        fseek(file, -1, SEEK_CUR); // decrementing file pointer
        if(fgetc(file) != '\n') { // checking for \n
            fseek(file, -1, SEEK_CUR);
            token[index] = fgetc(file);
            printf("%c", token[index]);
            index++;
        }     
    }
    token[index] = '\0';
}

double getBookDec(FILE *file) { //function for parsing (int, float or double)
    int index = 0;
    char tmp[MAX_STR];
    while(fgetc(file) != ';' && feof(file) == 0) { // not checking for \n because atof wont convert \n
        fseek(file, -1, SEEK_CUR); // decrementing pointer
        tmp[index] = fgetc(file);
        index++;
    }
    tmp[index] = '\0';
    return atof(tmp);
}

int longestNameLength(struct Book *books) { // function for finding length of the longest name
    int maxLength = 0;
    for(int i = 0; i < NUM_BOOKS; i++) {
        int length = 0;
        while(books[i].name[length] != '\0') {
            length++;
        }
        if(length > maxLength) { // check for longest length
            maxLength = length;
        }
        length = 0;
    }
    return maxLength;
}

int longestAuthorLength(struct Book *books) { // function for finding length of the longest author's name
    int maxLength = 0;
    for(int i = 0; i < NUM_BOOKS; i++) {
        int length = 0;
        while(books[i].author[length] != '\0') {
            length++;
        }
        if(length > maxLength) { // check for longest length
            maxLength = length;
        }
        length = 0;
    }
    return maxLength;
}