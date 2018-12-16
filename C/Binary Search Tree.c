#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

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
        //insertNode();
        break;
    case 2:
        //deleteNode();
        break;
    case 3:
        //displayNodes();
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