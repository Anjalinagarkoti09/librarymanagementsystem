#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100

char titles[MAX_BOOKS][MAX_TITLE_LENGTH];
int borrowed[MAX_BOOKS] = {0}; 

int num_books = 0; 

void borrowBook(char title[]) 
{
    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(titles[i], title) == 0) {
            if (borrowed[i] == 0) {
                borrowed[i] = 1; 
                printf("Book '%s' borrowed successfully.\n", title);
                return;
            } else {
                printf("Sorry, book '%s' is already borrowed.\n", title);
                return;
            }
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}
int main() 
{
    int choice;
    char title[MAX_TITLE_LENGTH];

    do {
        printf("\nLibrary Management System\n");
         printf("2. Borrow a book\n");
          printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

switch (choice) {
case 2:
                printf("Enter the title of the book to borrow: ");
                getchar(); 
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; 
                borrowBook(title);
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