// FitnessDataStruct.c

#include "FitnessDataStruct.h"
#include <limits.h>
#include <string.h>

FILE* openFile(char* filename) {
    FILE* file = fopen(filename, "r");
    return file;
}

int getTotalRecords(FILE* file) {
    int totalRecords = 0;
    FitnessRecord record;

    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(FitnessRecord), 1, file) == 1) {
        totalRecords++;
    }

    return totalRecords;
}

void findFewestSteps(FILE* file, char* dateAndTime) {
    int minSteps = INT_MAX;
    FitnessRecord record;
    char minStepsDateTime[17];

    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(FitnessRecord), 1, file) == 1) {
        if (record.steps < minSteps) {
            minSteps = record.steps;
            sprintf(minStepsDateTime, "%s %s", record.date, record.time);
        }
    }

    strcpy(dateAndTime, minStepsDateTime);
}

void findLargestSteps(FILE* file, char* dateAndTime) {
    int maxSteps = 0;
    FitnessRecord record;
    char maxStepsDateTime[17];

    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(FitnessRecord), 1, file) == 1) {
        if (record.steps > maxSteps) {
            maxSteps = record.steps;
            sprintf(maxStepsDateTime, "%s %s", record.date, record.time);
        }
    }

    strcpy(dateAndTime, maxStepsDateTime);
}

int calculateMeanSteps(FILE* file) {
    int totalSteps = 0;
    int totalRecords = 0;
    FitnessRecord record;

    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(FitnessRecord), 1, file) == 1) {
        totalSteps += record.steps;
        totalRecords++;
    }

    if (totalRecords == 0) {
        return 0; // To avoid division by zero
    }

    return totalSteps / totalRecords;
}

void findLongestPeriodAbove500(FILE* file, char* startTime, char* endTime) {
    int currentSteps = 0;
    int maxSteps = 0;
    char currentStartTime[17], currentEndTime[17];
    char maxStartTime[17], maxEndTime[17];
    FitnessRecord record;

    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(FitnessRecord), 1, file) == 1) {
        if (record.steps > 500) {
            if (currentSteps == 0) {
                // Start a new period
                sprintf(currentStartTime, "%s %s", record.date, record.time);
            }
            currentSteps += record.steps;
            sprintf(currentEndTime, "%s %s", record.date, record.time);
        } else {
            if (currentSteps > maxSteps) {
                maxSteps = currentSteps;
                strcpy(maxStartTime, currentStartTime);
                strcpy(maxEndTime, currentEndTime);
            }
            currentSteps = 0; // Reset for a new period
        }
    }

    // Check if the last period is the longest
    if (currentSteps > maxSteps) {
        maxSteps = currentSteps;
        strcpy(maxStartTime, currentStartTime);
        strcpy(maxEndTime, currentEndTime);
    }

    strcpy(startTime, maxStartTime);
    strcpy(endTime, maxEndTime);
}
