#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Manga {
    int mangaID;
    char mangaTitle[100];
    char alternativeTitle[100];
    char mangaAuthor[30];
    char mangaStatus[10];
    int yearManga;
};

void newManga(struct Manga [], int *);
void displayManga(const struct Manga [], int);
void mangaUpdate(struct Manga [], int);
void deleteManga(struct Manga [], int *);

int main(void) {
    struct Manga collection[100];

    int mangaBooks = 0;         //Assuming Manga book is 0

    int choice;
    printf("");
    do {
        printf("Menu:");
        printf("\n  1. Add a manga book");
        printf("\n  2. Display manga books");
        printf("\n  3. Update manga book");
        printf("\n  4. Delete a manga book");
        printf("\n  5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                newManga(collection, &mangaBooks);
                break;
            case 2:
                displayManga(collection, mangaBooks);
                break;
            case 3:
                mangaUpdate(collection, mangaBooks);
                break;
            case 4:
                deleteManga(collection, &mangaBooks);
                break;
            case 5:
                printf("Program Termenated...");
                break;
            default:
                printf("Invalid choice");
                Sleep(1000);
                system("cls");
        }
    } while(choice!= 5);
    
    return 0;
}
//* To add new manga
void newManga(struct Manga book[], int *mangaBooks) {
    int numManga = 0;
    //Asking the user how many manga he/she want to enter
    printf("How many new manga you want to enter?: ");
    scanf("%d", &numManga);

    int c;
    while( (c = getchar()) != '\n' && c != EOF);   //To clear input buffer

    for(int i = 1; i <= numManga; i++) {
        printf("Enter the details of the new manga (%d)\n", i);
        //Manga Number list
        printf("Enter manga ID: ");
        scanf("%d", &book[*mangaBooks].mangaID);
        while((c = getchar()) != '\n' && c != EOF);       //To clear input buffer
        //Manga title
        printf("Enter Manga title: ");
        fgets(book[*mangaBooks].mangaTitle, 100, stdin);
        book[*mangaBooks].mangaTitle[strlen(book[*mangaBooks].mangaTitle) - 1] = '\0';
        //Alternative title
        printf("Enter the alternative title: ");
        fgets(book[*mangaBooks].alternativeTitle, 100, stdin);
        book[*mangaBooks].alternativeTitle[strlen(book[*mangaBooks].alternativeTitle) - 1] = '\0';
        //Manga author
        printf("Enter the author of the manga: ");
        fgets(book[*mangaBooks].mangaAuthor, 30, stdin);
        book[*mangaBooks].mangaAuthor[strlen(book[*mangaBooks].mangaAuthor) - 1] = '\0';
        //The current status of the manga
        printf("Enter the current status of the manga: ");
        fgets(book[*mangaBooks].mangaStatus, 10, stdin);
        book[*mangaBooks].mangaStatus[strlen(book[*mangaBooks].mangaStatus) - 1] = '\0';
        //Year published
        printf("Enter the year of the manga published: ");
        scanf("%d", &book[*mangaBooks].yearManga);
        (*mangaBooks)++;                                        //incrementing the number og manga 
        Sleep(1000);
        system("cls");
    }
    printf("New manga added successfully!\n");
    system("pause");
    system("cls");
}
//* For displaying manga 
void displayManga(const struct Manga book[], int mangaBooks) {
    int choice = 0;
    do {
        printf("Choose: ");
        printf("\n1. Do you want to display it all?\n2. Display the specific one you want?");
        printf("\nEnter a numebr: ");
        scanf("%d", &choice);
        Sleep(500);
        system("cls");
    }while(choice != 1 && choice != 2);
    if(choice != 1){
        int mangaID;
        //Asking the user what manga details he/she wanted to look
        printf("Enter the Id you want to dispaly: ");
        scanf("%d", &mangaID);
        //Manga finder 
        int foundIndex = -1;
        for(int i = 0; i < mangaBooks; i++) {
            if(mangaID == book[i].mangaID) {
                printf("Manga found");
                foundIndex = i;
                break;
            }
        }
        //Dislpay the manga if found
        if(foundIndex != -1) {
            printf("\nManga ID:                           %d", book[foundIndex].mangaID);
            printf("\nManga title:                        %s", book[foundIndex].mangaTitle);
            printf("\nAlternative name:                   %s", book[foundIndex].alternativeTitle);
            printf("\nManga's author:                     %s", book[foundIndex].mangaAuthor);
            printf("\nYear manga published:               %d", book[foundIndex].yearManga);
            printf("\nThe current status of the manga:    %s\n", book[foundIndex].mangaStatus);
            system("pause");
            system("cls");
        } else {
            printf("Manga not found!\n");
            Sleep(1000);
            system("cls");
        }
    } else {
        if(mangaBooks == 0) {
            printf("Please add a manga first to display\n");
            Sleep(1000);
            system("cls");
        } else {
            //To Display all the manga
            for(int i = 0; i < mangaBooks; i++) {
                printf("Manga ID:                           %d", book[i].mangaID);
                printf("\nManga title:                        %s", book[i].mangaTitle);
                printf("\nAlternative name:                   %s", book[i].alternativeTitle);
                printf("\nManga's author:                     %s", book[i].mangaAuthor);
                printf("\nYear manga published:               %d", book[i].yearManga);
                printf("\nThe current status of the manga:    %s\n", book[i].mangaStatus);
            }
            system("pause");
            system("cls");
        }
    }
}
//* To update a manga
void mangaUpdate(struct Manga book[], int mangaBooks) {
    int mangaID = 0;
    //Asking the user what manga he/she wanted to update
    printf("Enter the manga ID to update: ");
    scanf("%d", &mangaID);
    //Manga finder 
    int foundIndex = -1;
    //Manga finder
    for(int i = 0; i < mangaBooks; i++) {
        if(mangaID == book[i].mangaID ) {
            printf("Manga found");
            foundIndex = i;
            break;
        }
    }
    if(foundIndex != -1) {
        int choice = 0;
        do {
            printf("\nWhat Do want to update? ");
            printf("\n1. Manga Title");
            printf("\n2. Manga alternative name");
            printf("\n3. Manga author");
            printf("\n4. Year published");
            printf("\n5. Manga status");
            printf("\nEnter the numebr: ");
            scanf("%d", &choice);
            Sleep(500);
            system("cls");
        }while(choice < 1 || choice > 5);
        int c;
        while((c = getchar()) != '\n' && c != EOF);          //To clear input buffer
        switch(choice) {
            case 1:
                //To update the title of the manga
                printf("Enter the new manga title: ");
                fgets(book[foundIndex].mangaTitle, 100, stdin);
                book[foundIndex].mangaTitle[strlen(book[foundIndex].mangaTitle) - 1] = '\0';
                break;
            case 2:
                //To update the alternative title of the manga
                printf("Enter the new alternative title: ");
                fgets(book[foundIndex].alternativeTitle, 100, stdin);
                book[foundIndex].alternativeTitle[strlen(book[foundIndex].alternativeTitle) - 1] = '\0';
                break;
            case 3:
                //To update the author of the manga
                printf("Enter the new author of the manga: ");
                fgets(book[foundIndex].mangaAuthor, 30, stdin);
                book[foundIndex].mangaAuthor[strlen(book[foundIndex].mangaAuthor) - 1] = '\0';
                break;
            case 4: 
                //To update the status of the manga
                printf("Enter the new current status of the manga: ");
                fgets(book[foundIndex].mangaStatus, 10, stdin);
                book[foundIndex].mangaStatus[strlen(book[foundIndex].mangaStatus) - 1] = '\0';
                break;
            case 5:
                //To update the year published
                printf("Enter the new year of the manga published: ");
                scanf("%d", &book[foundIndex].yearManga);
                break;
            default:
                printf("Default is not going to executte");
        }
        printf("Manga updated successfully!\n");
        system("pause");
        system("cls");
    } else {
        printf("Manga not found!\n");
        Sleep(1000);
        system("cls");
    }
}
//* To delete a manga
void deleteManga(struct Manga book[], int *mangaBooks) {
    int mangaID = 0;
    //Asking the user what manga he/she wanted to delete
    printf("Enter the manga ID to update: ");
    scanf("%d", &mangaID);
    int foundIndex = -1;
    //Manga finder
    for(int i = 0; i < mangaBooks; i++) {
        if(mangaID == book[i].mangaID) {
            printf("Manga found");
            foundIndex = i;
            break;
        }
    }
    if(foundIndex != -1) {
        //shift elements to fill the gap
        for(int i = foundIndex; i < *mangaBooks - 1; i++) {
            book[i] = book[i + 1];
        }
        (*mangaBooks)--;    //decrement the number of manga
        printf("Manga successfully deleted!\n");
        system("pause");
        system("cls");
    } else {
        printf("Manga not found!\n");
        Sleep(1000);
        system("cls");
    }
}