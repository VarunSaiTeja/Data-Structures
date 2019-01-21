#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;
struct node *end = NULL;

int totalNodes();

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
        end = temp;
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
        end = temp;
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
        end = temp;
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

void appendAtNode()
{
    if (totalNodes())
    {
        int loc;
        printf("Enter location of node to append : ");
        scanf("%d", &loc);
        system("cls");

        if (loc > totalNodes())
        {
            printf("Invalid location to append");
        }
        else if (loc == totalNodes())
        {
            printf("Trying to append at end of node\n\nTry \"Append at End\" option");
        }
        else
        {
            int count = 1;
            struct node *temp, *p;
            temp = (struct node *)malloc(sizeof(struct node));

            system("cls");
            printf("Enter data : ");
            scanf("%d", &temp->data);
            system("cls");
            temp->left = NULL;
            temp->right = NULL;

            p = root;
            while (count < loc)
            {
                ++count;
                p = p->right;
            }

            temp->right = p->right;
            p->right->left = temp;
            temp->left = p;
            p->right = temp;

            printf("Node appended at desired location");
        }
    }
    else
    {
        printf("Nodes are Empty");
    }
}

void displayNodesDataReverse()
{
    if (end == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        struct node *temp;
        temp = end;

        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->left;
        }
    }
}

displayNodesDataAndReverse()
{
    if (end == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        struct node *temp;
        temp = end;
        printf("\nEnd of Node = %u\n\n\n", end);
        while (temp != NULL)
        {
            printf("%u = %u -> %d -> %u\n\n", temp, temp->left, temp->data, temp->right);
            temp = temp->left;
        }
    }
}

void displayNodesData()
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

void displayNodesDataAndLinks()
{
    if (root == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        struct node *temp;
        temp = root;

        printf("\nRoot of Node = %u\n\n\n", root);

        while (temp != NULL)
        {
            printf("%u = %u -> %d -> %u\n\n", temp, temp->left, temp->data, temp->right);
            temp = temp->right;
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
            temp = temp->right;
        }
    }

    return count;
}

void deleteNode()
{
    if (totalNodes())
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
            if (root->right == NULL)
            {
                root = NULL;
                end = NULL;
                free(root);
            }
            else
            {
                struct node *temp;
                temp = root;
                root = temp->right;
                temp->right->left = NULL;
                temp->right = NULL;
                free(temp);
            }

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
                p = p->right;
            }

            q = p->right;
            if (q->right != NULL)
            {
                p->right = q->right;
                q->right->left = p;
            }
            else
            {
                p->right = NULL;
                end = p;
            }
            q->right = NULL;
            q->left = NULL;
            free(q);

            printf("Node deleted at desired location");
        }
    }
    else
    {
        printf("Nodes are Empty");
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
            if ((loc + 1) > totalNodes())
            {
                printf("Adjacent node does not exist");
            }
            else
            {
                int count = 1;
                struct node *a, *b, *c;
                a = root;

                while (count < (loc - 1))
                {
                    ++count;
                    a = a->right;
                }

                b = a->right;

                if (loc == 1)
                {
                    if ((loc + 1) == totalNodes())
                    {
                        a->right = NULL;
                    }
                    else
                    {
                        a->right = b->right;
                        b->right->left = a;
                    }

                    b->left = NULL;
                    b->right = a;
                    a->left = b;
                    root = b;
                }
                else
                {
                    c = b->right;

                    if ((loc + 1) != totalNodes())
                    {
                        c->right->left = b;
                        b->right = c->right;
                    }
                    else
                    {
                        b->right = NULL;
                    }

                    a->right = c;
                    c->left = a;
                    b->left = c;
                    c->right = b;
                }

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
            printf("Enter 2nd Node location : ");
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
                    a = a->right;
                }
                b = a->right;

                count = 1;
                while (count < (loc2 - 1))
                {
                    ++count;
                    c = c->right;
                }
                d = c->right;

                b->left = c;
                d->left = a;
                b->right->left = d;
                d->right->left = b;

                temp->right = d->right;
                d->right = b->right;
                b->right = temp->right;
                a->right = c->right;
                c->right = b;

                printf("Nodes swapped");
            }
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
    printf("5. Display only Nodes Data\n");
    printf("6. Display with Nodes Data & Links\n");
    printf("7. Display only Nodes Data From back\n");
    printf("8. Display with Nodes Data & Links From back\n");
    printf("9. Delete\n");
    printf("10. Swap Adjacent Nodes\n");
    printf("11. Swap Nodes\n");
    printf("12. Quit\n");
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
        displayNodesData();
        break;
    case 6:
        displayNodesDataAndLinks();
        break;
    case 7:
        displayNodesDataReverse();
        break;
    case 8:
        displayNodesDataAndReverse();
        break;
    case 9:
        deleteNode();
        break;
    case 10:
        swapAdjacentNodes();
        break;
    case 11:
        SwapNodes();
        break;
    case 12:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto DoubleLinkedListMenu;
}