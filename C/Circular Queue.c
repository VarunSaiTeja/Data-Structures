#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define capacity 5

int cqueue[capacity], rear = -1, front = -1;

void insertItem()
{
    int num;
    if (front == 0 && rear == capacity - 1 || rear + 1 == front)
    {
        printf("Circular Queue is Full");
    }
    else
    {
        printf("Enter an item : ");
        scanf("%d", &num);

        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            if (rear == capacity - 1)
            {
                rear = 0;
            }
            else
            {
                ++rear;
            }
        }
        cqueue[rear] = num;
        printf("Item inserted to Circular Queue");
    }
}

void deleteItem()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty");
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            if (front == capacity - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }

        printf("Last inserted Item deleted from Circular Queue");
    }
}

void displayItems()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        if (rear >= front)
        {
            for (int index = front; index <= rear; index++)
            {
                printf("%d,", cqueue[index]);
            }
        }
        else
        {
            for (int index = front; index < capacity; index++)
            {
                printf("%d,", cqueue[index]);
            }

            for (int index = 0; index <= rear; index++)
            {
                printf("%d,", cqueue[index]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
CircularQueueMenu:
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
    goto CircularQueueMenu;
}