#include <stdio.h>

// Functions Prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int modulus(int a, int b);

void saveToFile(const char *operation, int a, int b, float result);
void viewHistory();
void clearHistory();

int main() {
    int choice, a, b;
    float result;

    while (1) {
        printf("\n=== CALCULATOR MENU ===\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. View Calculation History\n");
        printf("7. Clear History\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 8) {
            printf("Exiting...\n");
            break;
        }

        if (choice >= 1 && choice <= 5) {
            printf("Enter number 1: ");
            scanf("%d", &a);
            printf("Enter number 2: ");
            scanf("%d", &b);
        }

        switch (choice) {
            case 1:
                result = add(a, b);
                printf("Result: %.2f\n", result);
                saveToFile("Addition", a, b, result);
                break;

            case 2:
                result = subtract(a, b);
                printf("Result: %.2f\n", result);
                saveToFile("Subtraction", a, b, result);
                break;

            case 3:
                result = multiply(a, b);
                printf("Result: %.2f\n", result);
                saveToFile("Multiplication", a, b, result);
                break;

            case 4:
                if (b == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = divide(a, b);
                    printf("Result: %.2f\n", result);
                    saveToFile("Division", a, b, result);
                }
                break;

            case 5:
                if (b == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    result = modulus(a, b);
                    printf("Result: %.2f\n", result);
                    saveToFile("Modulus", a, b, result);
                }
                break;

            case 6:
                viewHistory();
                break;

            case 7:
                clearHistory();
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// === BASIC OPERATIONS ===

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float) a / b;
}

int modulus(int a, int b) {
    return a % b;
}

// === FILE HANDLING ===

void saveToFile(const char *operation, int a, int b, float result) {
    FILE *fp = fopen("history.txt", "a");
    if (fp == NULL) {
        printf("Unable to open history file!\n");
        return;
    }

    fprintf(fp, "%s: %d and %d = %.2f\n", operation, a, b, result);
    fclose(fp);
}

void viewHistory() {
    FILE *fp = fopen("history.txt", "r");
    if (fp == NULL) {
        printf("No history found.\n");
        return;
    }

    char line[200];
    printf("\n=== CALCULATION HISTORY ===\n");

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
}

void clearHistory() {
    FILE *fp = fopen("history.txt", "w");
    if (fp == NULL) {
        printf("Failed to clear history.\n");
        return;
    }

    fclose(fp);
    printf("History cleared successfully.\n");
}

