// FitnessDataStruct.h

#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define the structure for fitness data
typedef struct {
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
    int steps;
} FitnessRecord;

// Function prototypes
FILE* openFile(char* filename);
int getTotalRecords(FILE* file);
void findFewestSteps(FILE* file, char* dateAndTime);
void findLargestSteps(FILE* file, char* dateAndTime);
int calculateMeanSteps(FILE* file);
void findLongestPeriodAbove500(FILE* file, char* startTime, char* endTime);

#endif // FITNESS_DATA_STRUCT_H