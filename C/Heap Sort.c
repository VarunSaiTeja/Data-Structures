#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int array[10], n = 0;

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

int main()
{
    int choice;
menu:
    system("cls");
    printf("1. Add Element\n");
    printf("2. Delete Element\n");
    printf("3. Display\n");
    printf("4. Exit\n");
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
        //delete_element();
        break;
    case 3:
        //display_elements();
        break;
    case 4:
        exit(0);
    default:
        break;
    }
    system("pause");
    goto menu;
}