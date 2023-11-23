#include <stdio.h>

void Get_Filename(char* User_Input, int size) {
    printf("Enter your filename: ");
    fgets(User_Input, size, stdin);
}

int main() {
    char file_name[100];  // Assuming a maximum filename length of 100 charcters

    Get_Filename(file_name, 100);

    printf("Filename: %s", file_name);

    return 0;
}
