#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root=NULL;

void appendAtLast()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    printf("Node created at end");
}

int totalNodes()
{
    int count=0;
    
    if(root!=NULL)
    {
        struct node *temp;
        temp = root;
        while (temp!= NULL)
        {
            ++count;
            temp = temp->link;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int choice;
SingleLinkedListMenu:
    system("cls");
    printf("Single Linked List Operations : \n\n");
    printf("1. Append at End\n");
    printf("2. Append at Begin\n");
    printf("3. Append at Node\n");
    printf("4. Length\n");
    printf("5. Display\n");
    printf("6. Delete\n");
    printf("7. Quit\n");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        appendAtLast();
        break;
    case 2:
        //appendAtBegin();
        break;
    case 3:
        //appendAtNode();
        break;
    case 4:
        printf("Total nodes are %d",totalNodes());
        break;
    case 5:
        //displayNodes();
        break;
    case 6:
        //deleteNode();
        break;
    case 7:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto SingleLinkedListMenu;
}