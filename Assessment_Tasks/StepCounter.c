#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <limits.h>  // Add this line for INT_MAX

#define MAX_FILENAME_LENGTH 100

int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE* file = NULL;

    // Display menu
    char option;
    do {
        printf("\nOptions:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");

        // Get user input
        printf("Select an option: ");
        scanf(" %c", &option);

        // Process user input
        switch (option) {
            case 'A':
                printf("Input filename: ");
                scanf("%s", filename);
                file = openFile(filename);
                if (file == NULL) {
                    printf("Error: could not open file\n");
                    return 1;
                }
                break;
            case 'B':
                if (file != NULL) {
                    int totalRecords = getTotalRecords(file);
                    printf("Total records: %d\n", totalRecords);
                } else {
                    printf("Error: no file opened\n");
                }
                break;
            case 'C':
                if (file != NULL) {
                    char fewestStepsDateTime[17];
                    findFewestSteps(file, fewestStepsDateTime);
                    printf("Fewest steps: %s\n", fewestStepsDateTime);
                } else {
                    printf("Error: no file opened\n");
                }
                break;
            case 'D':
                if (file != NULL) {
                    char largestStepsDateTime[17];
                    findLargestSteps(file, largestStepsDateTime);
                    printf("Largest steps: %s\n", largestStepsDateTime);
                } else {
                    printf("Error: no file opened\n");
                }
                break;
            case 'E':
                if (file != NULL) {
                    int meanSteps = calculateMeanSteps(file);
                    printf("Mean step count: %d\n", meanSteps);
                } else {
                    printf("Error: no file opened\n");
                }
                break;
            case 'F':
                if (file != NULL) {
                    char startTime[17], endTime[17];
                    findLongestPeriodAbove500(file, startTime, endTime);
                    printf("Longest period start: %s\n", startTime);
                    printf("Longest period end: %s\n", endTime);
                } else {
                    printf("Error: no file opened\n");
                }
                break;
        }
    } while (option != 'Q');

    return 0;
}
