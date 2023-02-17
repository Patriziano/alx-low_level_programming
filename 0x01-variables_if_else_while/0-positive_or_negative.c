#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Determines if a number is positive, negative or zero.
 *
 * Return: Always 0 (Success)
 */

int main(void) 
{
    int n;

    srand(time(NULL)); 
    n = rand() % 201 - 100; 
    printf("%d ", n);
    if (n > 0) {
        printf("is positive\n");
    } else if (n == 0) {
        printf("is zero\n");
    } else {
        printf("is negative\n");
    }
    return (0);
}

