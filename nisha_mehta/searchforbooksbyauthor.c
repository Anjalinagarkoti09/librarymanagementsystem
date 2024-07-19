#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_LENGTH 100

void searchBooksByAuthor(char titles[][MAX_LENGTH], char authors[][MAX_LENGTH], int count, const char* author);

int main() {
    char titles[MAX_BOOKS][MAX_LENGTH] = {
    
    };

    char authors[MAX_BOOKS][MAX_LENGTH] = {
        
    };

    char author[MAX_LENGTH];
    printf("Enter the author's name to search for books: ");
    fgets(author, MAX_LENGTH, stdin);
    author[strcspn(author, "\n")] = '\0'; 

    searchBooksByAuthor(titles, authors, MAX_BOOKS, author);

    return 0;
}

void searchBooksByAuthor(char titles[][MAX_LENGTH], char authors[][MAX_LENGTH], int count, const char* author) {
    int found = 0;
    printf("Books by %s:\n", author);
    for (int i = 0; i < count; i++) {
        if (strcmp(authors[i], author) == 0) {
            printf("- %s\n", titles[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by this author.\n");
    }
}
 