#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;

int totalNodes();

void appendAtLast()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
    printf("Node created at end");
}

void appendAtBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link = root;
        root = temp;
    }

    printf("Node created at begin");
}

void appendAtNode()
{
    if (totalNodes())
    {
        int loc;
        printf("Enter location of node to append : ");
        scanf("%d", &loc);

        if (loc > totalNodes())
        {
            printf("Invalid to location to append");
        }
        else
        {
            int count = 1;
            struct node *temp, *p, *q;
            temp = (struct node *)malloc(sizeof(struct node));

            system("cls");
            printf("Enter data : ");
            scanf("%d", &temp->data);

            p = root;
            while (count < loc)
            {
                ++count;
                p = p->link;
            }
            temp->link = p->link;
            p->link = temp;
            printf("Node appended at desired location");
        }
    }
    else
    {
        printf("Nodes are Empty");
    }
}

void deleteNode()
{
    if (root == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        int loc;
        printf("Enter location of node to delete : ");
        scanf("%d", &loc);
        system("cls");

        if (loc > totalNodes() || loc == 0)
        {
            printf("Node doest not exist at %d location", loc);
        }
        else if (loc == 1)
        {
            struct node *temp;
            temp = root;
            root = temp->link;
            temp->link = NULL;
            printf("Node deleted at desired location");
        }
        else
        {
            int count = 1;
            struct node *p, *q;
            p = root;

            while (count < (loc - 1))
            {
                ++count;
                p = p->link;
            }

            q = p->link;
            p->link = q->link;
            q->link = NULL;
            free(q);
            printf("Node deleted at desired location");
        }
    }
}

int totalNodes()
{
    int count = 0;

    if (root != NULL)
    {
        struct node *temp;
        temp = root;
        while (temp != NULL)
        {
            ++count;
            temp = temp->link;
        }
    }

    return count;
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
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
    }
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
        appendAtBegin();
        break;
    case 3:
        appendAtNode();
        break;
    case 4:
        printf("Total nodes are %d", totalNodes());
        break;
    case 5:
        displayNodes();
        break;
    case 6:
        deleteNode();
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