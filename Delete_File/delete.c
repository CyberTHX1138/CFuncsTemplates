#include <stdio.h>

int main() {
    // Hardcoded file name
    const char *file_path = "/path/to/your/file.txt";

    // Remove file & check if successful
    if (remove(file_path) == 0) {
        printf("File %s deleted successfully.\n", file_path);
    } else {
        perror("Error deleting file");
        return 1;
    }

    return 0;
}        
