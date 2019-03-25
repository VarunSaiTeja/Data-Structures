#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;

void PushNode()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &new_node->data);
    new_node->link = NULL;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        struct node *temp = root;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new_node;
    }

    system("cls");
    printf("Node Pushed to Stack");
}

int main(int argc, char const *argv[])
{
    int choice;
QueueUsingSingleLinkedListMenu:
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
        //PopNode();
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
    goto QueueUsingSingleLinkedListMenu;
}