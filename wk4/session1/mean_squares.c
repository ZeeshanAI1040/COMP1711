#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100] = "squares.dat";
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int total = 0;
    int num_of_lines = 0;
    
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total += atoi(line_buffer);
        num_of_lines++;
    }

    printf("%d", total / num_of_lines);

    fclose(file);
    return 0;
}
