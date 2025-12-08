#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tambahBuku();
void lihatBuku();
void clearBuku();

int main() {
    int choice;

    while (1) {
        printf("\n===== LIBRARY MENU =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Clear Books History\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1:
                tambahBuku();
                break;
            case 2:
                lihatBuku();
                break;
            case 3:
                 clearBuku();
                 break;
            case 4:
                 printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void trimNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void tambahBuku() {
    char judul[100], penulis[100];
    int tahun;

    printf("Enter book title: ");
    fgets(judul, sizeof(judul), stdin);
    trimNewline(judul);

    printf("Enter author name: ");
    fgets(penulis, sizeof(penulis), stdin);
    trimNewline(penulis);

    printf("Enter publication year: ");
    scanf("%d", &tahun);
    getchar(); // clear newline

    FILE *fp = fopen("daftar_buku.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Store in clean format without extra newlines inside fields
    fprintf(fp, "%s;%s;%d\n", judul, penulis, tahun);

    fclose(fp);

    printf("Book successfully added!\n");
}

void lihatBuku() {
    FILE *fp = fopen("daftar_buku.txt", "r");

    if (fp == NULL) {
        printf("No book data found. File does not exist.\n");
        return;
    }

    char line[300];
    int isEmpty = 1;

    printf("\n===== LIST OF BOOKS =====\n");

    while (fgets(line, sizeof(line), fp)) {
        isEmpty = 0;

        // Remove newline if exists
        line[strcspn(line, "\n")] = '\0';

        // Split into parts
        char *judul = strtok(line, ";");
        char *penulis = strtok(NULL, ";");
        char *tahun = strtok(NULL, ";");

        if (judul && penulis && tahun) {
            printf("%s – %s (%s)\n", judul, penulis, tahun);
        }
    }

    if (isEmpty) {
        printf("No book data.\n");
    }

    fclose(fp);
}

void clearBuku() {
    FILE *fp = fopen("daftar_buku.txt", "w");  // open in write mode

    if (fp == NULL) {
        printf("Error clearing file!\n");
        return;
    }

    // Opening with "w" automatically clears the file
    fclose(fp);

    printf("All book data has been cleared!\n");
}
