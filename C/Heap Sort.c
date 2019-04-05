#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int array[10], n = 0;

int main()
{
    int choice;
menu:
    system("cls");
    printf("1. Add Element\n");
    printf("2. Delete Element\n");
    printf("3. Display\n");
    printf("\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        //add_element();
        break;
    case 2:
        //delete_element();
        break;
    case 3:
        //display_elements();
        break;
    default:
        break;
    }
    system("pause");
}