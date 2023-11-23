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
    int num_of_records = 0;     //initializes a variable called num_of_records, to be used later
    char line_buffer[buffer_size];      //creates a string variable called line_buffer, with predefined size
    
    FILE *csv_file = fopen("FitnessData_2023.csv", "r");        //opens the file in read mode
    if (csv_file == NULL) {     //If the file an't be opened, print an error and end it.
        perror("Error opening file");
        return 1;
    }

    // Count and print the number of records in the file
    while (fgets(line_buffer, buffer_size, csv_file) != NULL) { //reads the file line-by-line; while it can still do this, the function is executed
        num_of_lines++;         //while the file can be read from, add 1 to the number of lines variable
    }
    printf("Number of records in file: %d\n", num_of_lines);    //prints the number of lines

    rewind(csv_file);   //sends the line-by-line reader back to the beginning of the file.

    while (num_of_records < 3 && fgets(line_buffer, sizeof(line_buffer), csv_file) != NULL) {
        char date[11];
        char time[6];
        int steps;

        // Parse the line into date, time, and steps
        tokeniseRecord(line_buffer, ",", date, time, &steps); //stores the data into 3 variables; data, time and steps.

        // Print the formatted output
        printf("%s/%s/%d\n", date, time, steps);    //prints data, time and steps.

        num_of_records++;      //increments number of records.
    }

    fclose(csv_file);   //closes the file
    return 0;
}
