#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

void insertNode()
{
    struct node *temp, *parent;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data : ");
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
        struct node *current;
        current = root;

        while (current)
        {
            parent = current;
            if (temp->data > current->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }

        if (temp->data > parent->data)
        {
            parent->right = temp;
        }
        else
        {
            parent->left = temp;
        }
    }

    printf("Node added to Binary Search Tree");
}

void inOrder(struct node *temp)
{
    if (temp->left)
    {
        inOrder(temp->left);
    }

    printf("%d  ", temp->data);

    if (temp->right)
    {
        inOrder(temp->right);
    }
}

void displayNodes()
{
    if (root == NULL)
    {
        printf("Binary Search Tree is Empty");
    }
    else
    {
        int choice;
        system("cls");
        printf("1. In-Order\n2. Pre-Order\n3. Post-Order");
        printf("\n\nChoice : ");
        scanf("%d", &choice);
        system("cls");

        switch (choice)
        {
        case 1:
            inOrder(root);
            break;
        case 2:
            //preOrder();
            break;
        case 3:
            //postOrder();
            break;
        default:
            system("cls");
            printf("Invalid Choice, Try again");
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
BinarySearchTreeMenu:
    system("cls");
    printf("Binary Search Tree Operations : \n\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Quit\n");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        insertNode();
        break;
    case 2:
        //deleteNode();
        break;
    case 3:
        displayNodes();
        break;
    case 4:
        exit(0);
    default:
        system("cls");
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto BinarySearchTreeMenu;
}