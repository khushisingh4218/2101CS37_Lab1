#include<stdio.h>
void add(float m,float n);
void subtract(float m,float n);
void multiply(float m,float n);
void divide(float m,float n);
int main()
{
    printf("1. Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    printf("Enter the operation(1/2/3/4):\n");
    int choice;
    scanf("%d", &choice);
    // taking input of choice of operation
    float a, b;
    printf("Enter first number a:\n");
    scanf("%f", &a);
    printf("Enter second number b:\n");
    scanf("%f", &b);
    // taking input of numbers
    switch (choice)
    {
    case 1:
        add(a, b);
        break;

    case 2:
        subtract(a, b);
        break;

    case 3:
        multiply(a, b);
        break;

    case 4:
        if (b == 0)
        {
            printf("Division by zero is not possible!");
        }
        else
        {
            divide(a, b);
        }
        break;

    default:
        printf("Invalid operation!\n");
        break;
    }
    return 0;
}

// addition function
void add(float m, float n)
{
    printf("calculating a+b:\n%f + %f = %f", m, n, m + n);
}

// subtraction function
void subtract(float m, float n)
{
    printf("calculating a-b:\n%f - %f = %f", m, n, m - n);
}

// multiplication function
void multiply(float m, float n)
{
    printf("calculating a*b:\n%f * %f = %f", m, n, m * n);
}

// division function
void divide(float m, float n)
{
    printf("calculating a/b:\n%f / %f = %f", m, n, m / n);
}