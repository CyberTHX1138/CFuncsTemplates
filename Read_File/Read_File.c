#include <stdio.h>

int main() {
    FILE *filePointer;

    filePointer = fopen("FILE_PATH", "r");

    if (filePointer == NULL) {
        printf("Reading Failed!");
        return 1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), filePointer) !=NULL) {
        printf("%s", buffer);
    }
    fclose(filePointer);
    return 0;
}

/*
    LINE 4: "FILE" initializes the pointer with a data type. It could be "int", "char", etc.. |o| the "*filePointer" initializes the pointer's name
    LINE 6: "fopen" is used to open a file named "FILE_PATH" in a different director path with the reading mode indicated by "r"
    LINES 8-11: if our "filePointer" address is assigned NULL, meaning the "fopen" function failed, print out the error message
    LINES 15-17: "fgets" function gets strings from the meant file, "buffer" is the space array where what is read will be stored, "sizeof(buffer)" is the maximum
        amount of characters, and "filePointer" is simply the name of the file we assigned to be read. All of this is being done in a while loop to ensure that
        everything in the file gets printed out even if it's larger than our assigned buffer size.
*/
