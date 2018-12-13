#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define capacity 5

int top = -1, stack[capacity];

void PushItem();
void PopItem();
void PeekItem();
void DisplayItems();
int isFull();
int isEmpty();

int isFull()
{
    if((top+1)==capacity)
    return TRUE;
    else
    return FALSE;
}

int isEmpty()
{
    if (top == -1)
        return TRUE;
    else
        return FALSE;
}

void PushItem()
{
    if(isFull())
    {
        printf("Stack is Full");
    }
    else
    {
        printf("Enter an item : ");
        scanf("%d",stack[++top]);
        system("cls");
        printf("Item pushed to stack");
    }
}

void DisplayItems()
{
    if(isEmpty())
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Stack items are : ");
        for(int loop=0;loop<top;loop++)
        {
            printf("%d  ",stack[loop]);
        }
    }
}

void main(int argc, char const *argv[])
{
    int choice;
StackMenu:
    system("cls");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display Items\n5. Quit");
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