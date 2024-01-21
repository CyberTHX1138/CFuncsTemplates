#include <stdio.h>

int main() {
    FILE *filePointer;

    filePointer = fopen("WritableFile.txt", "w");

    if (filePointer == NULL) {
        printf("Error opening the new file.\n");
        return 1;
    }

    fprintf(filePointer, "FILE CONTENT WRITTEN IN C!!!");

    fclose(filePointer);

    return 0;

}

/*
    LINE 4: "FILE" initializes the pointer with a data type. It could be "int", "char", etc.. |o| the "*filePointer" initializes the pointer's name
    LINE 6: "fopen" is used to open a file named "WritableFile.txt" with the writing mode indicated by "w"
    LINES 8-11: if our "filePointer" address is assigned NULL, meaning the "fopen" function failed, print out the error message
    LINE 15: We close the created file to avoid any memory leaks. + Data written to the file might be displayed properly if not closed. + File Locking Issues.
*/
