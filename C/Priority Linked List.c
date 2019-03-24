#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct node
{
    short int data, priority;
    struct node *link;
};

struct node *root = NULL;

void addNode()
{
    system("cls");
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &new_node->data);
    printf("\nPriority : ");
    scanf("%d", &new_node->priority);
    system("cls");
    new_node->link = NULL;

    if (root == NULL || new_node->priority < root->priority)
    {
        new_node->link = root;
        root = new_node;
    }
    else
    {
        struct node *temp = root;
        while ((temp->link != NULL) && (temp->link->priority <= new_node->priority))
        {
            temp = temp->link;
        }

        new_node->link = temp->link;
        temp->link = new_node;
    }

    printf("Node inseted");
}

void delNode()
{
    if (root == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        struct node *temp = root;
        root = root->link;
        temp->link = NULL;
        printf("Node with data %d & priority %d deleted from list", temp->data, temp->priority);
        free(temp);
    }
}

void displayNodes()
{
    system("cls");

    if (root == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        struct node *temp = root;
        printf("Data\tPriority\n\n");
        while (temp != NULL)
        {
            printf("%d\t%d\n", temp->data, temp->priority);
            temp = temp->link;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
PriorityLinkedListMenu:
    system("cls");
    printf("Priority Linked List Operations : \n\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("\nChoice : ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        addNode();
        break;
    case 2:
        delNode();
        break;
    case 3:
        displayNodes();
        break;
    case 4:
        exit(0);
    default:
        break;
    }

    printf("\n\n");
    system("pause");
    goto PriorityLinkedListMenu;
}