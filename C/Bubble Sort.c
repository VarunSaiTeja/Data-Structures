#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define capacity 5

int main(int argc, char const *argv[])
{
    int num[capacity];
    printf("Enter 5 numbers : ");
    scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

    int choice;
SortMenu:
    system("cls");
    printf("Sort in : \n\n");
    printf("1. Asecnding order\n");
    printf("2. Descending order\n");
    printf("3. Quit\n");
    printf("\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    if (choice == 1 || choice == 2)
    {
        int temp;
        for (int i = 0; i < (capacity - 1); i++)
        {
            for (int j = 0; j < (capacity - 1 - i); j++)
            {
                if (choice == 1)
                {
                    if (num[j] > num[j + 1])
                    {
                        temp = num[j];
                        num[j] = num[j + 1];
                        num[j + 1] = temp;
                    }
                }
                else
                {
                    if (num[j] < num[j + 1])
                    {
                        temp = num[j];
                        num[j] = num[j + 1];
                        num[j + 1] = temp;
                    }
                }
            }
        }

        (choice == 1) ? printf("Accending Order : ") : printf("Descending Order : ");
        printf("%d %d %d %d %d", num[0], num[1], num[2], num[3], num[4]);
    }
    else
    {
        if (choice == 3)
        {
            exit(0);
        }
        else
        {
            system("cls");
            printf("Invalid Choice\n");
        }
    }

    printf("\n\n\n");
    system("pause");
    goto SortMenu;
    system("pause");
}