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
        printf("X(%d): ",i);
        scanf("%d",&new->data);
        new->Xpower = i;
        ptr->next=new;
        ptr=new;
        new->next=NULL;
    }
}


struct node* adding_eq(struct node *eq1,struct node *eq2)
{
    struct node *new, *prev, *eq3;
    int count=0;
    while(eq1!=NULL || eq2!=NULL)
    {
        if(eq1!=NULL && eq2!=NULL)
        {
            new =(struct node *)malloc(sizeof(struct node));
            if(count<=0)
            {
                eq3=new;
                count++;
                prev = eq3;
            }

            new->data = eq1->data + eq2->data;
            new->Xpower =eq1->Xpower; 
            
            if(count==1)
            {
                count++;
                eq1 = eq1->next;
                eq2 = eq2->next;
                continue;
            }
            prev->next=new;
            prev=new;
            new->next=NULL;
            eq1 = eq1->next;
            eq2 = eq2->next;
        }

        else if(eq1!=NULL)
        {
            new = (struct node *)malloc(sizeof(struct node));
            new->data = eq1->data;
            new->Xpower = eq1->Xpower;
            prev->next = new;
            prev = new;
            new->next = NULL;
            eq1 = eq1->next;
        }
        else if(eq2!=NULL)
        {
            new = (struct node *)malloc(sizeof(struct node));
            new->data = eq2->data;
            new->Xpower = eq2->Xpower;
            prev->next = new; 
            prev = new;
            new->next = NULL;
            eq2 = eq2->next;
        }
            // eq1 = eq1->next;
            // eq2 = eq2->next;
        
    }
    return eq3;
}

void display(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("X(%d): %d   ",ptr->Xpower,ptr->data);
        ptr = ptr->next;
    }
}


int main()
{
    struct node *eq1, *eq2, *eq3;
    eq1 = (struct node *)malloc(sizeof(struct node));
    eq2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the terms of EQ1: \n");
    creating_eq(eq1, 4);
    printf("Enter the terms of EQ2: \n");
    creating_eq(eq2, 2);
    eq3 = adding_eq(eq1,eq2);
    printf("The sum is: \n");
    display(eq3);
}