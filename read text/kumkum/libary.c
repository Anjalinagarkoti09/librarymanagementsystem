#include <stdio.h>  
#define MAX_BOOKS 5 
#define TITLE_LEN 50
#define AUTHOR_LEN 50 

char books[2][50];
char authors[2][50];

int available_books = 2;  

void display_default_books()
 {
    printf("Available Books:\n");
    printf("==================================================\n");
    printf("%s\t\t %s\n", "Title",        "Author");
    printf("\n");
    
    for (int i = 0; i < available_books; i++)
     {
        printf("%s\t\t %s\n\n", books[i], authors[i]);
     }

    printf("==================================================\n");
}

void search_by_title()
 {
    char search_title[TITLE_LEN];
    int found = 0;

    printf("\nEnter a keyword to search by title (minimum 3 characters): ");
    fgets(search_title, TITLE_LEN, stdin);

   
    for (int i = 0; i < TITLE_LEN; i++)
     {
        if (search_title[i] == '\n')
         {
            search_title[i] = '\0';
            break;
        }
    }

    printf("\nSearch Results:\n");
    printf("==================================================\n");
    printf("%s\t\t %s\n", "Title", "Author");
    printf("==================================================\n");

    for (int i = 0; i < available_books; i++)
     {
        int match = 1;
        for (int j = 0; search_title[j] != '\0'; j++) {
            if (books[i][j] == '\0' || search_title[j] != books[i][j])
             {
                match = 0;
                break;
            }
        }
        if (match)
         {
            printf("%s\t\t %s\n", books[i], authors[i]);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("No books found with title '%s'.\n", search_title);
    }
    printf("==================================================\n");
}

void choices()
 {
    printf("\nPlease enter your choice:\n");
    printf("2: Display Available Books\n");
    printf("5: Search Books by Title\n");
    printf("0: Exit\n");
}

int main()
 {
    int choice;

    printf("\n\t****** Project 03 -  Library Management System ******\n\n");

    while (1) 
    {
        choices();
        printf("Please enter your choice: ");
        if (scanf("%d", &choice) != 1)
         {
            printf("Invalid choice. Please enter a number.\n");
            while (getchar() != '\n');  
            continue;
        }
        getchar();  
        switch (choice) {
            case 2:
                display_default_books();
                break;
            case 5:
                search_by_title();
                break;
            case 0:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
