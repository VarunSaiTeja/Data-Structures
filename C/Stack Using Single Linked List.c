#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void PushNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->link = top;
    top = temp;
    system("cls");
    printf("Node Pushed to Stack");
}

void PopNode()
{
    if (top == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = temp->link;
        temp->link = NULL;
        free(temp);
        printf("Last Node insertes was Popped");
    }
}

int main(int argc, char const *argv[])
{
    int choice;
StackUsingSingleLinkedListMenu:
    system("cls");
    printf("Single Linked List Operations : \n\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        PushNode();
        break;
    case 2:
        PopNode();
        break;
    case 3:
        //DisplayNodes();
        break;
    case 4:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto StackUsingSingleLinkedListMenu;
}