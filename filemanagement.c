#include <stdio.h>
#include <stdlib.h>

void createFile();
void readFile();
void updateFile();
void deleteFile();

int main() {
    int choice;

    while (1) {
        // Display the menu
        printf("\nFile Management System\n");
        printf("1. Create a new file\n");
        printf("2. Read data from a file\n");
        printf("3. Update data in a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                updateFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void createFile() {
    char filename[50];
    FILE *file;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
    } else {
        printf("File created successfully.\n");
        fclose(file);
    }
}

void readFile() {
    char filename[50];
    char ch;
    FILE *file;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
    } else {
        printf("File contents:\n");
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    }
}

void updateFile() {
    char filename[50];
    char data[100];
    FILE *file;

    printf("Enter the name of the file to update: ");
    scanf("%s", filename);

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
    } else {
        printf("Enter the data to append (max 100 characters): ");
        scanf(" %[^\n]", data);
        fprintf(file, "%s\n", data);
        printf("Data updated successfully.\n");
        fclose(file);
    }
}

void deleteFile() {
    char filename[50];

    printf("Enter the name of the file to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting the file.\n");
    }
}
