#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int get_choice()
{
    int choice;
    system("cls");
    printf("Array Operations\n\n");
    printf("1. Display Array Elements\n");
    printf("2. Exit");
    printf("\nChoice : ");
    scanf("%d", &choice);
    return choice;
}

void display_array_elements(int *array, int array_elements_count)
{
    system("cls");
    printf("Array elements are : \n");
    for (int index = 0; index < array_elements_count; index++)
    {
        printf("%d ", array[index]);
    }
}

int main(int argc, char const *argv[])
{
    int *array, array_elements_count, choice;
    printf("Enter no of array elements : ");
    scanf("%d", &array_elements_count);
    array = (int *)calloc(array_elements_count, sizeof(int));

    system("cls");
    printf("Enter array elements : \n");
    for (int loop = 0; loop < array_elements_count; loop++)
    {
        scanf("%d", &array[loop]);
    }

array_operations:
    choice = get_choice();
    switch (choice)
    {
    case 1:
        display_array_elements(array, array_elements_count);
        break;
    case 0:
        exit(0);
        break;
    default:
        break;
    }

    printf("\n");
    system("pause");
    goto array_operations;
}