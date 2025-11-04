#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;

    // Get input and output file names
    printf("Enter the source file name (e.g., input.txt): ");
    scanf("%s", sourceName);

    printf("Enter the destination file name (e.g., output.txt): ");
    scanf("%s", destName);

    // Open the source file for reading
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file '%s'\n", sourceName);
        exit(1);
    }

    // Create or open the destination file for writing
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file '%s'\n", destName);
        fclose(sourceFile);
        exit(1);
    }

    // Copy contents character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully from '%s' to '%s'.\n", sourceName, destName);

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}