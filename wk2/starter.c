#include <stdio.h>
int main() {

    int num1, num2;
    printf("Enter two numbers ");
    scanf("%d %d", num1, num2);

    int num3 = num1 + num2;

    printf("The sum is %d", &num3);

return 0;

}