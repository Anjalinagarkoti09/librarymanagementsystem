#include<stdio.h>
#include<string.h>

#define MAX_BOOKS 100
#define MAX_AUTHORS 50

char books[MAX_BOOKS][50];
char authors[MAX_AUTHORS][50];
int availability[MAX_BOOKS] = {0};

int totalBooks = 0;
int totalAuthors = 0;

void addBook() {
char bookTitle[50];
char authorName[50];

printf("Enter the title of the book: ");
scanf(" %[^\n]s", &bookTitle);

printf("Enter the author of the book: ");
scanf(" %[^\n]s",&authorName);

strcpy(books[totalBooks], bookTitle);

int authorExists = 0;

for (int i = 0; i < totalAuthors; i++) {
if (strcmp(authors[i], authorName) == 0) {
authorExists = 1;
break;
}
}

if (!authorExists) {
strcpy(authors[totalAuthors], authorName);
totalAuthors++;
}

availability[totalBooks] = 1;
totalBooks++;

printf("Book added successfully!\n");
}

int main() {
int choice;

do {
printf("\nLibrary Management System\n");
printf("1. Add a new book\n");
printf("2. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
addBook();
break;
case 2:
printf("Exiting program. Thank you!\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 2);

return 0;
}