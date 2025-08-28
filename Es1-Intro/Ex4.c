#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 0; i <= num - 1; i++) // Loop for rows
    {
        if (i == 0 || i == num - 1) // Print first and last row with all "*"
        {
            for (int cont = 0; cont < num; cont++) // Loop to print "*"
                printf("*");
            printf("\n"); // Add newline after printing the row of "*"
        }
        else
        {
            for (int j = 0; j <= num - 1; j++) // Loop for single row
            {
                if (j == 0 || j == num - 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
