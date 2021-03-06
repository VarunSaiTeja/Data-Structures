#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define capacity 5

int queue[capacity],rear=0,front=0;

void insertItem();
void deleteItem();
void displayItems();
int isFull();
int isEmpty();

int isFull()
{
    if(rear==capacity)
    return TRUE;
    else
    return FALSE;
}

int isEmpty()
{
    if(rear)
    return FALSE;
    else
    return TRUE;
}

void insertItem()
{
    if(isFull())
    {
        printf("Queue is Full");
    }
    else
    {
        printf("Enter an item  : ");
        scanf("%d",&queue[rear++]);
        system("cls");
        printf("Item inserted to Queue");
    }
}

void displayItems()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue items are : ");
        for (int loop = 0; loop < rear; loop++)
        {
            printf("%d  ", queue[loop]);
        }
    }
}

void deleteItem()
{
    if(isEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        --rear;

        for(int loop = 0; loop < rear; loop++)
        {
            queue[loop]=queue[loop+1];
        }
        
        printf("Item removed from queue");
    }
}

int main(int argc, char const *argv[])
{
    int choice;
QueueMenu:
    system("cls");
    printf("Queue Operations : \n\n");
    printf("1. Insert an item\n");
    printf("2. Delete an item\n");
    printf("3. Display all items\n");
    printf("4. Quit");
    printf("\n\nChoice : ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        insertItem();
        break;
    case 2:
        deleteItem();
        break;
    case 3:
        displayItems();
        break;
    case 4:
        exit(0);
    default:
        break;
    }

    printf("\n\n");
    system("pause");
    goto QueueMenu;
}