#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TRUE 1
#define FALSE 0

int get_choice()
{
    int choice;
    system("cls");
    printf("Array Operations\n\n");
    printf("1. Display Array Elements\n");
    printf("2. Linear Search\n");
    printf("3. Binary Search\n");
    printf("4. Exit\n");
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

int linear_search(int *array, int array_elements_count, int element, int *location)
{
    for (int index = 0; index < array_elements_count; index++)
    {
        if (element == array[index])
        {
            *location = index;
            return TRUE;
        }
    }
    return FALSE;
}

int binary_search(int *array, int array_elements_count, int element, int *location)
{
    int start = 0, end = array_elements_count - 1, middle;

    while (start <= end)
    {
        middle = (start + end) / 2;
        if (element == array[middle])
        {
            *location = middle;
            return TRUE;
        }
        else
        {
            if (element > array[middle])
            {
                start = ++middle;
            }
            else
            {
                end = --middle;
            }
        }
    }

    return FALSE;
}

int main(int argc, char const *argv[])
{
    int *array, array_elements_count, choice;
    printf("Enter count of array elements : ");
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
    case 2:
    {
        int element, location;
        system("cls");
        printf("Enter array element to search : ");
        scanf("%d", &element);
        if (linear_search(array, array_elements_count, element, &location))
        {
            system("cls");
            printf("Element found at index location : %d", location);
        }
        else
        {
            printf("Element not found");
        }

        break;
    }
    case 3:
    {
        int element, location;
        system("cls");
        printf("Enter array element to search : ");
        scanf("%d", &element);
        if (binary_search(array, array_elements_count, element, &location))
        {
            system("cls");
            printf("Element found at index location : %d", location);
        }
        else
        {
            printf("Element not found");
        }

        break;
    }
    case 4:
        exit(0);
        break;
    default:
        break;
    }

    printf("\n\n");
    system("pause");
    goto array_operations;
}