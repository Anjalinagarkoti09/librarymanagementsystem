#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100

char titles[MAX_BOOKS][MAX_TITLE_LENGTH];
int borrowed[MAX_BOOKS] = {0}; 
int num_books = 0;

void returnBook(char title[]) {
    if (num_books == 0) {
        printf("Library is empty. No books to return.\n");
        return;
    }

    
    title[strcspn(title, "\n")] = '\0';

    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(titles[i], title) == 0) {
            if (borrowed[i] == 1) {
                borrowed[i] = 0; 
                printf("Book '%s' returned successfully.\n", title);
                return;
            } else {
                printf("Book '%s' is not currently borrowed.\n", title);
                return;
            }
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];

    do {
        printf("\nLibrary Management System\n");
     
        printf("4. Return a book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while(getchar() != '\n');

        switch (choice) {
           
            case 4:
                printf("Enter the title of the book to return: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; 
                returnBook(title);
                break;
          
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
