#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

void appendAtLast()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    system("cls");
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;

        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }

    printf("Node created at end");
}

void appendAtBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    system("cls");
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        temp->right = root;
        root = temp;
    }

    printf("Node created at begin");
}

void displayNodes()
{
    if (root == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        struct node *temp;
        temp = root;

        printf("Data in Nodes : ");
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->right;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
DoubleLinkedListMenu:
    system("cls");
    printf("Single Linked List Operations : \n\n");
    printf("1. Append at End\n");
    printf("2. Append at Begin\n");
    printf("3. Append at Node\n");
    printf("4. Length\n");
    printf("5. Display\n");
    printf("6. Delete\n");
    printf("7. Swap Adjacent Nodes\n");
    printf("8. Swap Nodes\n");
    printf("9. Quit\n");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        appendAtLast();
        break;
    case 2:
        appendAtBegin();
        break;
    case 3:
        //appendAtNode();
        break;
    case 4:
        //printf("Total nodes are %d", totalNodes());
        break;
    case 5:
        displayNodes();
        break;
    case 6:
        //deleteNode();
        break;
    case 7:
        //swapAdjacentNodes();
        break;
    case 8:
        //SwapNodes();
        break;
    case 9:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto DoubleLinkedListMenu;
}