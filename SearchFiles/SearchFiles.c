#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

const char *targetFile = "co.txt";

void searchFile(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat statBuf;

    if (!(dir = opendir(dirPath))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        if (lstat(fullPath, &statBuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statBuf.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            searchFile(fullPath);
        } else if (S_ISREG(statBuf.st_mode)) {
            if (strcmp(entry->d_name, targetFile) == 0) {
                printf("Found: %s\n", fullPath);
            }
        }
    }

    closedir(dir);
}

int main() {
    searchFile("/");

    return 0;
}

/*
LINES 1-5: <stdio.h> for input/output, <stdlib.h> for memory allocation, <string.h> for string manipulation, <dirent.h> for directory-related functions, 
    and <sys/stat.h> for file status functions.
LINE 7: a constant string targetFile is declared and
    initialized with the value "SearchFiles.c". This is
    the hardcoded target file name the program is searching
    for.
LINES 9-17: This is the beginning of the searchFile
    function. It takes a directory path as a parameter.
    It uses the DIR and struct dirent types to represent
    a directory stream and an entry in that stream,
    respectively. It also uses struct stat to get
    information about a file. The function attempts
    to open the directory using opendir(). If it fails,
    it prints an error message using perror() and returns
    from the function.
LINES 19-26: This is a loop that iterates through each
    entry in the directory. For each entry, it constructs
    the full path by concatenating the directory path and
    the entry name. It then uses lstat() to get
    information about the file. If lstat() fails,
    it prints an error message using perror() and
    continues to the next iteration of the loop.
LINES 28-41: Inside the loop, it checks if the entry is a
    directory (S_ISDIR(statBuf.st_mode)). If it is, it
    skips the "." and ".." entries and recursively calls
    the searchFile function with the new directory path.
    If it's a regular file (S_ISREG(statBuf.st_mode)),
    it checks if its name matches the target file name.
    If it does, it prints a message indicating that the
    file is found.
LINES 43-47: the main function is simple. It calls the
    searchFile function, starting the search from the
    root directory ("/"). The program returns 0,
    indicating successful execution.

1. Header Files:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
These are the standard C header files included for input/output, memory allocation, string manipulation, directory operations, and file information.

2. Constant Declaration:

const char *targetFile = "co.txt";
This line declares a constant string targetFile with the value "co.txt", representing the file to be searched.

3. Function Declaration:

void searchFile(const char *dirPath);
This is a function prototype for searchFile, which will be defined later in the code. It takes a directory path as an argument.

4. Function Definition - searchFile:

void searchFile(const char *dirPath) {
    // Function body
}
This function is responsible for recursively searching for the target file in the specified directory and its subdirectories.

5. Directory and File Information Variables:


DIR *dir;
struct dirent *entry;
struct stat statBuf;
These variables are used to store information about directories and files during the search process.

6. Directory Opening and Error Handling:

if (!(dir = opendir(dirPath))) {
    perror("opendir");
    return;
}
Attempts to open the specified directory (dirPath). If unsuccessful, it prints an error message using perror and exits the function.

7. Directory Entry Loop:

while ((entry = readdir(dir)) != NULL) {
    // Loop body
}
Iterates through each entry (file or subdirectory) in the currently opened directory.

8. Building Full Path:

char fullPath[1024];
snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
Constructs the full path by combining the current directory path (dirPath) with the name of the entry.

9. File Information Retrieval:

if (lstat(fullPath, &statBuf) == -1) {
    perror("lstat");
    continue;
}
Retrieves information about the entry (file or directory) using lstat. If unsuccessful, it prints an error message and continues to the next entry.

10. Checking for Subdirectory:

if (S_ISDIR(statBuf.st_mode)) {
    // Subdirectory handling
}
Checks if the entry is a subdirectory.

11. Recursive Subdirectory Search:

searchFile(fullPath);
Recursively calls the searchFile function for the subdirectory.

12. Checking for Target File:

else if (S_ISREG(statBuf.st_mode)) {
    // Regular file handling
}
Checks if the entry is a regular file.

13.Found Target File:

if (strcmp(entry->d_name, targetFile) == 0) {
    printf("Found: %s\n", fullPath);
}
Prints a message if the current file matches the target file.

14. Directory Closing:

closedir(dir);
Closes the currently opened directory.

15. Main Function:

c
Copy code
int main() {
    searchFile("/");
    return 0;
}
Calls searchFile starting from the root directory ("/").
*/
