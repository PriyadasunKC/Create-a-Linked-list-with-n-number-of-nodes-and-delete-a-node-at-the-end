#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

void display(struct node *);
struct node *insertNodes(int);
struct node *deleteAtEnd(struct node *);

struct node *insertNodes(int size)
{

    struct node *head = NULL;
    struct node *newNode = NULL;
    struct node *currunt = NULL;

    for (int i = 0; i < size; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value %d : ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            currunt = head;
        }
        else
        {
            currunt->next = newNode;
            currunt = currunt->next;
        }
    }
    printf("\nBefore delete Last node,\n");
    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *toDel = NULL;
    struct node *lastNode = NULL;

    toDel = head;
    lastNode = head;
    if (head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while (toDel->next != NULL)
        {
            lastNode = toDel;
            toDel = toDel->next;
        }

        if (toDel == head)
        {
            head = NULL;
        }
        else
        {
            lastNode->next = NULL;
        }

        free(toDel);

        printf("\nAfter delete Last node,\n");
    }

    return head;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int size = 0;
    struct node *head = NULL;

    printf("Enter the size : ");
    scanf("%d", &size);

    head = insertNodes(size);
    display(head);

    head = deleteAtEnd(head);
    display(head);

    return 0;
}
