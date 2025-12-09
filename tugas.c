#include <stdio.h>
#include <stdlib.h>

// Functions Prototype
void createDataMahasiswa();
void readDataMahasiswa();
void updateDataMahasiswa();
void deleteDataMahasiswa();

int main () {
    int choice;

    while(1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Add Data\n");
        printf("2. View Data\n");
        printf("3. Update Data\n");
        printf("4. Clear Data\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1:
                createDataMahasiswa();
                break;
            case 2:
                readDataMahasiswa();
                break;
            case 3:
                updateDataMahasiswa();
                break;
            case 4:
                deleteDataMahasiswa();
                break;
            case 5:
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

void createDataMahasiswa() {
    char nama[100];
    double NIM; 

    printf("Enter name: ");
    fgets(nama, sizeof(nama), stdin);
    trimNewline(nama);
}
