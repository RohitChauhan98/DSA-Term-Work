// Write a C program to create a double linked list by inserting nodes in such a way that the
// resultant linked list remains in ascending order.(do not use any sorting technique).

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

void create_doublyll(int n)
{
    
    struct Node *ptr;
    printf("Enter Node 1: ");
    scanf("%d",&head->data);
    head->next = NULL;
    head->prev = NULL;

    for(int i =2; i<=n; i++)
    {
        struct Node *new, *temp;
        ptr=head;

        new = (struct Node* )malloc(sizeof(struct Node));
        printf("Enter Node %d: ",i);
        scanf("%d",&new->data);
        if(new->data<ptr->data)
        {
            while(new->data < ptr->data && ptr->prev !=NULL)
            {
                ptr=ptr->prev;
            }
            if(ptr->prev!=NULL || ptr->data < new->data)
            {
                temp=ptr->next;
                ptr->next=new;
                new->prev=ptr;
                new->next=temp;
                temp->prev=new; 
            }
            else
            {
                ptr->prev=new;
                new->next=ptr;
                new->prev=NULL;
            }
            
        }
        else if(new->data>ptr->data)
        {
            while(new->data > ptr->data && ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            if(ptr->next !=NULL || ptr->data > new->data)
            {
                temp=ptr->prev;
                ptr->prev=new;
                new->next=ptr;
                new->prev=temp;
                temp->next=new; 
            }
            else
            {
                ptr->next=new;
                new->prev=ptr;
                new->next=NULL;
            }
            
        }
    }

    while(head->prev!=NULL)
    {
        head=head->prev;
    }
}


void traverse(struct Node *ptr)
{

    while(ptr !=NULL)
    {
        printf("%d ", ptr->data);
        ptr= ptr->next;
    }
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    create_doublyll(6);
    traverse(head);

}