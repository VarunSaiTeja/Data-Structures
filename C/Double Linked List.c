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
    }
    else
    {
        temp->left = end;
        end->right = temp;
    }
    end = temp;
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
        root->left = temp;
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

void displayNodesDataAndReverse()
{
    if (end == NULL)
    {
        printf("Nodes are Empty");
    }
    else
    {
        struct node *temp;
        temp = end;
        printf("\nEnd of Linked List = %u\n\n\n", end);
        while (temp != NULL)
        {
            printf("%u = %u -> %d -> %u\n\n", temp, temp->left, temp->data, temp->right);
            temp = temp->left;
        }
        printf("\nRoot of Linked List = %u\n", root);
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
        printf("\nRoot of Linked List = %u\n\n\n", root);
        while (temp != NULL)
        {
            printf("%u = %u -> %d -> %u\n\n", temp, temp->left, temp->data, temp->right);
            temp = temp->right;
        }
        printf("\nEnd of Linked List = %u\n", end);
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

void appendAfterNodeData()
{
    int data;
    printf("Enter data of previous Node : ");
    scanf("%d", &data);
    system("cls");

    struct node *p = root;
    while (p->data != data)
    {
        p = p->right;
    }

    if (data != p->data)
    {
        printf("Incorrect Node Data");
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->left = NULL;
        temp->right = NULL;
        printf("Enter data for new Node : ");
        scanf("%d", &temp->data);
        system("cls");

        if (p->right != NULL)
        {
            p->right->left = temp;
        }
        temp->left = p;
        temp->right = p->right;
        p->right = temp;
        printf("New Node Inserted at desired location");
    }
}

int main(int argc, char const *argv[])
{
    int choice;
DoubleLinkedListMenu:
    system("cls");
    printf("Double Linked List Operations : \n\n");
    printf("1. Append at End\n");
    printf("2. Append at Begin\n");
    printf("3. Insert at Location\n");
    printf("4. Append after Node Data\n");
    printf("5. Length of Linked List\n");
    printf("6. Display only Nodes Data\n");
    printf("7. Display with Nodes Data & Links\n");
    printf("8. Display only Nodes Data From back\n");
    printf("9. Display with Nodes Data & Links From back\n");
    printf("10. Delete\n");
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
        appendAfterNodeData();
        break;
    case 5:
        printf("Total nodes are %d", totalNodes());
        break;
    case 6:
        displayNodesData();
        break;
    case 7:
        displayNodesDataAndLinks();
        break;
    case 8:
        displayNodesDataReverse();
        break;
    case 9:
        displayNodesDataAndReverse();
        break;
    case 10:
        deleteNode();
        break;
    case 11:
        exit(0);
    default:
        printf("Invalid Choice, Try again");
    }

    printf("\n\n");
    system("pause");
    goto DoubleLinkedListMenu;
}