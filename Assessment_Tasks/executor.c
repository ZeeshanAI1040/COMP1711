#include "header.h"
#include <string.h>
#include <stdio.h>


int main() {

    //code for switch function
    char choice;
    printf("MENU: \n A: Specify Filename \n B: Display Number of Records \n C: Timeslot with Fewest Steps \n D: Timeslot with Most Steps \n E: Mean Step Count of all Timeslots \n F: Longest Continuous Period where Step Count is greater than 500 \n G: Quit \n");
    printf("Choose your letter from the options listed above: ");
    scanf(" %c", &choice);

    switch(choice){
        case 'A':       //Obtaining filename and checking the file is accessible (part A)
        Get_Filename();
        printf("%s \n", global_file_name);

        case 'Q':
            return 0;
            break;
    }

    char print_filename();
        printf("%s \n", global_file_name);

    print_filename();
    return 0;
}
