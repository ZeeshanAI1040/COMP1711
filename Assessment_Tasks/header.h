#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

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

//FOR TASK PART A:
char global_file_name[100];  // Declare a global variable to store the filename

int Get_Filename() {
    printf("Enter your filename: ");
    
    while (getchar() != '\n'); // Clear the input buffer
    
    fgets(global_file_name, sizeof(global_file_name), stdin);
    
    int length = strlen(global_file_name);
    if (length > 0 && global_file_name[length - 1] == '\n') {
        global_file_name[length - 1] = '\0';
    }

    FILE *file = fopen(global_file_name, "r");

    if (file == NULL) {
        perror("Error: could not open file \n");
        return 1;
    } 

    fclose(file);
    return 0;
}


int count_lines(){
    char* csv_file = Get_Filename();
    int num_of_lines = 0;
    int buffer_size;
    char line_buffer[buffer_size];

    FILE *csv_file = fopen(csv_file, "r");
    if (csv_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line_buffer, buffer_size, csv_file) != NULL){
        num_of_lines++;
    }

    printf("Number of Records in File")

}

