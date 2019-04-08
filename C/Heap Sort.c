#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define capacity 10

int array[capacity], n = 0;
int sorted[capacity], n_sort = 0;

void add_element()
{
    int element, ptr, par;
    printf("Enter element : ");
    scanf("%d", &element);
    n = n + 1;
    ptr = n;
    while (ptr > 1)
    {
        par = ptr / 2;

        if (element <= array[par])
        {
            array[ptr] = element;
            return;
        }

        array[ptr] = array[par];
        ptr = par;
    }
    array[1] = element;
}

void delete_element()
{
    int deleting_item = array[1];
    sorted[++n_sort] = deleting_item;
    int last_item = array[n];
    int loc = 1, left = 2, right = 3;
    --n;

    while (right <= n)
    {
        if (last_item >= array[left] && last_item >= array[right])
        {
            array[loc] = last_item;
            return;
        }

        if (array[right] > array[left])
        {
            array[loc] = array[right];
            loc = right;
        }
        else
        {
            array[loc] = array[left];
            loc = left;
        }

        left = 2 * loc;
        right = 2 * loc + 1;
    }

    if (left == n && last_item < array[left])
    {
        array[loc] = array[left];
        loc = left;
    }
    array[loc] = last_item;
}

void display_elements()
{
    printf("Elements are : ");
    for (int index = 1; index <= n; index++)
    {
        printf("%d ", array[index]);
    }
    printf("\n\n");
}

void display_sorted()
{
    printf("Sorted Elements are : ");
    for (short int index = 1; index <= n_sort; index++)
    {
        printf("%d ", sorted[index]);
    }
    printf("\n\n");
}

int main()
{
    int choice;
menu:
    system("cls");
    printf("1. Add Element\n");
    printf("2. Delete Element\n");
    printf("3. Display Heap\n");
    printf("4. Display Sorted Array\n");
    printf("5. Exit\n");
    printf("\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        add_element();
        system("cls");
        printf("Element Inserted\n");
        break;
    case 2:
        delete_element();
        break;
    case 3:
        display_elements();
        break;
    case 4:
        display_sorted();
        break;
    case 5:
        exit(0);
    default:
        break;
    }
    system("pause");
    goto menu;
}