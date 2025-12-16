#include <stdio.h>
#include <string.h>

// Function Prototypes
void createDataMahasiswa();
void readDataMahasiswa();
void updateDataMahasiswa();
void deleteDataMahasiswa();
void purgeDataMahasiswa();
void trimNewline(char *str);

int main () {
    int choice;

    while(1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Add Data\n");
        printf("2. View Data\n");
        printf("3. Update Data\n");
        printf("4. Delete Data Based on NIM\n");
        printf("5. Purge Data \n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: createDataMahasiswa(); break;
            case 2: readDataMahasiswa(); break;
            case 3: updateDataMahasiswa(); break;
            case 4: deleteDataMahasiswa(); break;
            case 5: purgeDataMahasiswa(); break;
            case 6: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

// remove trailing newline from fgets()
void trimNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void createDataMahasiswa() {
    char nama[100];
    char jurusan[100];
    char NIM[100];
    float IPK; 

    printf("Enter name: ");
    fgets(nama, sizeof(nama), stdin);
    trimNewline(nama);

    printf("Enter NIM: ");
    fgets(NIM, sizeof(NIM), stdin);
    trimNewline(NIM);

    printf("Enter IPK: ");
    scanf("%f", &IPK);
    getchar();

    printf("Enter Major: ");
    fgets(jurusan, sizeof(jurusan), stdin);
    trimNewline(jurusan);

    FILE *fp = fopen("daftar_mahasiswa.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s;%s;%s;%0.2f\n", nama, NIM, jurusan, IPK);
    fclose(fp);

    printf("Data added successfully!\n");
}

void readDataMahasiswa() {
    FILE *fp = fopen("daftar_mahasiswa.txt", "r");
    if (fp == NULL) {
        printf("No data found.\n");
        return;
    }

    char line[300];
    printf("\n===== DATA MAHASISWA =====\n");

    while (fgets(line, sizeof(line), fp)) {
        char *nama = strtok(line, ";");
        char *nim  = strtok(NULL, ";");
        char *jurusan = strtok(NULL, ";");
        char *ipk = strtok(NULL, ";");

        printf("Name    : %s\n", nama);
        printf("NIM     : %s\n", nim);
        printf("Major   : %s\n", jurusan);
        printf("IPK     : %s\n", ipk);
        printf("------------------------\n");
    }

    fclose(fp);
}

void updateDataMahasiswa() {
    FILE *fp = fopen("daftar_mahasiswa.txt", "r");
    if (!fp) {
        printf("No data available to update.\n");
        return;
    }

    // Show existing data first
    printf("\n===== AVAILABLE DATA =====\n");

    char line[300];
    while (fgets(line, sizeof(line), fp)) {
        char *nama = strtok(line, ";");
        char *nim = strtok(NULL, ";");
        char *jurusan = strtok(NULL, ";");
        char *ipk = strtok(NULL, ";");

        printf("Name   : %s\n", nama);
        printf("NIM    : %s\n", nim);
        printf("Major  : %s\n", jurusan);
        printf("IPK    : %s\n", ipk);
        printf("-------------------------\n");
    }

    fclose(fp);

    // Ask for target NIM
    char targetNIM[100];
    printf("Enter the NIM you want to update: ");
    fgets(targetNIM, sizeof(targetNIM), stdin);
    trimNewline(targetNIM);

    fp = fopen("daftar_mahasiswa.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("File error!\n");
        return;
    }

    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char nama[100], nim[100], jurusan[100];
        float ipk;

        sscanf(line, "%99[^;];%99[^;];%99[^;];%f", nama, nim, jurusan, &ipk);

        if (strcmp(nim, targetNIM) == 0) {
            found = 1;

            printf("\n=== UPDATE DATA ===\n");

            printf("New name: ");
            fgets(nama, sizeof(nama), stdin);
            trimNewline(nama);

            printf("New major: ");
            fgets(jurusan, sizeof(jurusan), stdin);
            trimNewline(jurusan);

            printf("New IPK: ");
            scanf("%f", &ipk);
            getchar();

            fprintf(temp, "%s;%s;%s;%0.2f\n", nama, nim, jurusan, ipk);
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("daftar_mahasiswa.txt");
    rename("temp.txt", "daftar_mahasiswa.txt");

    if (found)
        printf("Data updated successfully!\n");
    else
        printf("NIM not found.\n");
}


void deleteDataMahasiswa() {
    FILE *fp = fopen("daftar_mahasiswa.txt", "r");
    if (!fp) {
        printf("No data available to delete.\n");
        return;
    }

    printf("\n===== AVAILABLE DATA =====\n");

    char line[300];
    while (fgets(line, sizeof(line), fp)) {
        char *nama = strtok(line, ";");
        char *nim = strtok(NULL, ";");
        char *jurusan = strtok(NULL, ";");
        char *ipk = strtok(NULL, ";");

        printf("Name   : %s\n", nama);
        printf("NIM    : %s\n", nim);
        printf("Major  : %s\n", jurusan);
        printf("IPK    : %s\n", ipk);
        printf("-------------------------\n");
    }
    fclose(fp);

    // Ask user which NIM to delete
    char targetNIM[100];
    printf("Enter the NIM you want to DELETE: ");
    fgets(targetNIM, sizeof(targetNIM), stdin);
    trimNewline(targetNIM);

    fp = fopen("daftar_mahasiswa.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("File error!\n");
        return;
    }

    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char nama[100], nim[100], jurusan[100];
        float ipk;

        sscanf(line, "%99[^;];%99[^;];%99[^;];%f", nama, nim, jurusan, &ipk);

        if (strcmp(nim, targetNIM) == 0) {
            found = 1;
            printf("\nDeleting data for NIM: %s...\n", nim);
            // Skip writing to file → this is the "delete"
        } else {
            fprintf(temp, "%s;%s;%s;%0.2f\n", nama, nim, jurusan, ipk);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("daftar_mahasiswa.txt");
    rename("temp.txt", "daftar_mahasiswa.txt");

    if (found)
        printf("Data deleted successfully!\n");
    else
        printf("NIM not found.\n");
}

void purgeDataMahasiswa() {
    char confirm[10];

    printf("\nWARNING: This will DELETE ALL DATA permanently.\n");
    printf("Are you sure? (yes/no): ");
    fgets(confirm, sizeof(confirm), stdin);
    trimNewline(confirm);

    if (strcmp(confirm, "yes") != 0) {
        printf("Purge cancelled.\n");
        return;
    }

    FILE *fp = fopen("daftar_mahasiswa.txt", "w");
    if (!fp) {
        printf("Error clearing file.\n");
        return;
    }

    fclose(fp);

    printf("All data has been purged successfully!\n");
}

