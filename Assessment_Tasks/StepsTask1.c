#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here
int num_of_lines;
int buffer_size = 24;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Outputs: date character array; time character array; steps integer
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, int *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        *steps = atoi(token); // Convert the string to an integer
    }
    
    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main() {
    int num_of_records = 0;
    char line_buffer[buffer_size];
    
    FILE *csv_file = fopen("FitnessData_2023.csv", "r");
    if (csv_file == NULL) {
        perror("Error opening file");
        return 1;
    }


    printf("Number of lines in the file: %d\n", num_of_lines);

    while (num_of_records < 3 && fgets(line_buffer, sizeof(line_buffer), csv_file) != NULL) {
        char date[11];
        char time[6];
        int steps;

        // Parse the line into date, time, and steps
        tokeniseRecord(line_buffer, ",", date, time, &steps);

        // Print the formatted output
        printf("%s/%s/%d\n", date, time, steps);

        num_of_records++;
    }

    while (fgets(line_buffer, buffer_size, csv_file) != NULL) {
        num_of_lines++;
    }

    fclose(csv_file);
    return 0;
}

