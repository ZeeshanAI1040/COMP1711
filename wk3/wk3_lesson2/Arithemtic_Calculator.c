#include <stdio.h>

float addition(int a, int b)
{
    int answer;
    answer = a + b;
    return answer;
}

float subtraction(int a, int b)
{
    int answer;
    answer = a - b;
    return answer;
}

float multiplication(int a, int b)
{
    int answer;
    answer = a * b;
    return answer;
}

float division(int a, int b)
{
    int answer;
    answer = a / b;
    return answer;
}


int main() 
{
    float one;
    float two;
    char option;

    printf("Enter your numbers (first number, then enter, then second on the new line):\n ");
    scanf("%f %f" , &one, &two);
    printf("\n");
    
    printf ("Select + to add\n");
    printf ("Select - to subtract\n");
    printf ("Select * multiply\n");
    printf ("Select / divide\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option);

    switch (option)
    {
        case '+': printf ("Added: %f\n", addition(one, two));
                  break;

        case '-': printf ("Subtracted: %f\n", subtraction(one, two));
                  break;

        case '*': printf ("Multiplied: %f\n", multiplication(one, two));
                  break; 

        case '/': printf ("Divided: %f\n", division(one, two));
                  break;         

        case 'Q': break;

        default:  break;
    }

    return 0;

}