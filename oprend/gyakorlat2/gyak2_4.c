#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    FILE *file = fopen("time_storage.txt", "w");

    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon + 1;
    int day = timeinfo->tm_mday;

    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;
    int second = timeinfo->tm_sec;

    fprintf(file, "Current local time and date: %04d-%02d-%02d %02d:%02d:%02d\n", 
            year, month, day, hour, minute, second);  

    fclose(file);

    printf("Successfully wrote the current time and date to time_storage.txt\n");

    return 0;
}