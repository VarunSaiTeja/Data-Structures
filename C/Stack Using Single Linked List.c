#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

int main(int argc, char const *argv[])
{
    int choice;
StackUsingSingleLinkedListMenu:
    system("cls");
    printf("Single Linked List Operations : \n\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        //PushNode();
        break;
    case 2:
        //PopNode();
        break;
    case 3:
        //PeekNode();
        break;
    case 4:
        //DisplayNodes();
        break;
    case 5:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto StackUsingSingleLinkedListMenu;
}