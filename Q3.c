// Write a C program to create a linked list P, then write a ‘C’ function named split to
// create two linked lists Q & R from P So that Q contains all elements in odd positions of
// P and R contains the remaining elements. Finally print both linked lists i.e. Q and R.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createll(struct node *ptr, int n)
{
    struct node *prev;
    printf("Node 1: ");
    scanf("%d", &ptr->data);
    prev = ptr;
    ptr->next = NULL;

    for (int i = 2; i <= n; i++)
    {
        struct node *new;
        new = (struct node *)malloc(sizeof(struct node));
        printf("Node %d: ", i);
        scanf("%d", &new->data);
        prev->next = new;
        prev = new;
        new->next = NULL;
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void split(struct node *ptr)
{
    struct node *Q, *R, *temp;
    int index = 1, count1 = 0, count2 = 0;
    while (ptr != NULL)
    {
        if (index % 2 == 0)
        {
            if (count1 <= 0)
            {
                R = ptr;
                ptr = ptr->next;
                R->next = NULL;
                count1++;
            }
            else
            {
                temp = ptr;
                ptr = ptr->next;
                temp->next = R;
                R = temp;
            }
        }

        else
        {
            if (count2 <= 0)
            {
                Q = ptr;
                ptr = ptr->next;
                Q->next = NULL;
                count2++;
            }
            else
            {
                temp = ptr;
                ptr = ptr->next;
                temp->next = Q;
                Q = temp;
            }
        }
        index++;
    }

    printf("Printing Q linklist(Odd position)...\n");
    display(Q);
    printf("\nPrinting R linklist(Even position)...\n");
    display(R);
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    createll(head, 8);
    split(head);

}