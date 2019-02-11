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

struct node *fetchDataLocation(int data)
{
    struct node *temp = root;
    while (temp->link != NULL)
    {
        if (data == temp->data)
        {
            return temp;
        }
        temp = temp->link;
    }
    return NULL;
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

void swapAdjacentNodes()
{
    if (root == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        int loc;
        printf("Enter the location of node : ");
        scanf("%d", &loc);
        system("cls");
        if (loc > totalNodes())
        {
            printf("Node doest not exist in that location");
        }
        else
        {
            if (loc + 1 > totalNodes())
            {
                printf("Adjacent node does not exist");
            }
            else
            {
                int count = 1;
                struct node *p, *q, *r;
                p = root;

                while (count < (loc - 1))
                {
                    ++count;
                    p = p->link;
                }

                q = p->link;
                r = q->link;

                q->link = r->link;
                p->link = r;
                r->link = q;

                printf("Node swapped with adjacent one");
            }
        }
    }
}

void SwapNodes()
{
    if (root == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        int loc1, loc2;
        printf("Enter 1st Node location : ");
        scanf("%d", &loc1);
        system("cls");

        if (loc1 > totalNodes())
        {
            printf("1st Node does not exist in that location");
        }
        else
        {
            printf("Enter 2nd Node Location : ");
            scanf("%d", &loc2);
            system("cls");

            if (loc2 > totalNodes())
            {
                printf("2nd Node does not exist in that location");
            }
            else if ((loc1 + 1) == loc2)
            {
                printf("Try adjacent node swapping");
            }
            else
            {
                int count;
                struct node *a, *b, *c, *d, *temp;
                a = root;
                c = root;
                temp = (struct node *)malloc(sizeof(struct node));

                count = 1;
                while (count < (loc1 - 1))
                {
                    ++count;
                    a = a->link;
                }
                b = a->link;

                count = 1;
                while (count < (loc2 - 1))
                {
                    ++count;
                    c = c->link;
                }
                d = c->link;

                temp->link = d->link;
                d->link = b->link;
                b->link = temp->link;
                a->link = d;
                c->link = b;

                printf("Nodes swapped");
            }
        }
    }
}

void ReverseNodesData()
{
    if (root == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        int i = 0, j, count, temp;
        j = totalNodes() - 1;
        struct node *p, *q;
        p = q = root;

        while (i < j)
        {
            count = 0;
            while (count < j)
            {
                ++count;
                q = q->link;
            }
            temp = p->data;
            p->data = q->data;
            q->data = temp;
            p = p->link;
            q = root;
            i++;
            --j;
        }

        printf("Data in Nodes Swapped");
    }
}

void ReverseNodesConnection()
{
    struct node *temp, *temp_root;
    temp = temp_root = root;
    int total_nodes = totalNodes();
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    root = temp;

    for (int count = 1; count < total_nodes; count++)
    {
        temp = temp_root;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        temp->link->link = temp;
        temp->link = NULL;
    }

    printf("Connection between nodes reversed");
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
    printf("7. Swap Adjacent Nodes\n");
    printf("8. Swap Nodes\n");
    printf("9. Reverse Data in Nodes\n");
    printf("10. Reverse Nodes Connection\n");
    printf("11. Quit\n");
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
        swapAdjacentNodes();
        break;
    case 8:
        SwapNodes();
        break;
    case 9:
        ReverseNodesData();
        break;
    case 10:
        ReverseNodesConnection();
        break;
    case 11:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto SingleLinkedListMenu;
}