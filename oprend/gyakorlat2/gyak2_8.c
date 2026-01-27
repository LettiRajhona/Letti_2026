#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Add a directory name as an argument.\n");
        return 1;
    }

    DIR* directory = opendir(argv[1]);
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent* entry;
    struct stat fileStat;
    char filePath[1024];

    while ((entry = readdir(directory)) != NULL) {
        // skip "." and ".." entries (parent directories)
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // create the full file path
        snprintf(filePath, sizeof(filePath), "%s/%s", argv[1], entry->d_name);

        // get file statistics
        if (stat(filePath, &fileStat) == -1) {
            perror("Error: file statistics are not accessible");
            continue;
        }

        // get the type of the file
        if (S_ISDIR(fileStat.st_mode)) {
            printf("[DIR] ");
        } else if (S_ISLNK(fileStat.st_mode)) {
            printf("[LINK] ");
        } else {
            printf("[FILE] ");
        }

        printf("%s | ", entry->d_name);
        printf("size: %lld bytes | ", fileStat.st_size);
        printf("inode: %llu | ", fileStat.st_ino);

        printf("permissions: ");
        printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

        printf("\n");
    }

    closedir(directory);

    return 0;
}