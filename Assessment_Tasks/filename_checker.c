#include "FitnessDataStruct.h"
#include <stdio.h>

int main() {
    char file_name[100]; //assuming 100 is the maximum file size (may need to be increased, unlikely tho)
    Get_Filename(file_name, 100);
    printf("The name of your file is: %s", file_name);
}
