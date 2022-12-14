// Write a program to add of two polynomials of degree n, using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int Xpower;
    struct node* next;
};

void creating_eq(struct node *ptr, int n)
{
    struct node *temp;
    printf("X(0): ");
    ptr->Xpower=0;
    scanf("%d", &ptr->data);
    temp=ptr;
    ptr->next=NULL;

    for(int i=1; i<n; i++)
    {
        struct node *new;
        new =(struct node *)malloc(sizeof(struct node));
        printf("X(i) :");
        scanf("%d",&new->data);
        new->Xpower = i;
        ptr->next=new;
        ptr=new;
        new->next=NULL;
    }
}

void adding_eq(struct node *eq1,struct node *eq2)
{
    struct node *eq3;
    while(eq1!=NULL || eq2!=NULL)
    {
        int count=0;
        struct node *new, prev;
        if(eq1->Xpower == eq2->Xpower)
        {
            new =(struct node *)malloc(sizeof(struct node));
            if(count<=0)
            {
                eq3=new;
                count++;
                
            }
        
            new->data = eq1->data + eq2->data;
            
            eq1 = eq1->next;
            eq2 = eq2->next;
        }

        else if(eq1->Xpower > eq2->Xpower)
        {
            
        }
        else if(eq1->Xpower < eq2->Xpower)
        {

        }
    
        
    }
}

int main()
{
    struct node *eq1, *eq2;
    eq1 = (struct node *)malloc(sizeof(struct node));
    eq2 = (struct node *)malloc(sizeof(struct node));

    creating_eq(eq1, 4);
    creating_eq(eq2, 4);
}