#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define capacity 5

int top = -1, stack[capacity];

void PushItem();
void PopItem();
void PeekItem();
void DisplayItems();

void main(int argc, char const *argv[])
{
    int choice;
StackMenu:
    system("cls");
    printf("1. Push\n2. Pop\n3. Peek\n4. Transverse\n5. Quit");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        PushItem();
        break;
    case 2:
        PopItem();
        break;
    case 3:
        PeekItem();
        break;
    case 4:
        DisplayItems();
    case 5:
        exit(0);
    default:
        system("cls");
        printf("Invalid Choice\n");
    }

    printf("\n\n\n");
    system("pause");
    goto StackMenu;
}