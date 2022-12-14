//Write a C program to create two linked lists positive and negative from a Original linked list,
// so that positive linked list contains all positive elements and negative linked list contains
// negative elements. Positive and negative linked lists should use the node of existing original
// linked list.

#include<stdio.h>
#include<stdlib.h>

 struct  node
 {
    int data;
    struct node *next;
 };

void createll(struct node *ptr, int n)
{
   struct node *prev;
   printf("Enter Node 1: ");
   scanf("%d",&ptr->data);
   prev=ptr;
   ptr->next=NULL;

   for(int i =2; i<=n; i++)
   {
      struct node *new;
      new = (struct node *)malloc(sizeof(struct node));
      printf("Enter Node %d: ",i);
      scanf("%d",&new->data);
      prev->next=new;
      prev = new;
      new->next=NULL;
   }
}

struct node* creating_two_ll(struct node *ptr)
{
   struct node *positive, *negetive, *temp;
   int count1=0, count2=0;
   while(ptr!=NULL)
   {
      if(ptr->data>0)
      {
         if(count1<=0)
         {
            positive=ptr;
            ptr=ptr->next;      
            positive->next= NULL;
            count1++;
         }
         else{
            temp=ptr;
            ptr=ptr->next;
            temp->next=positive;
            positive=temp;
         }
         
      }
      else if (ptr->data<0)
      {
         if(count2<=0)
         {
            negetive=ptr;
            ptr=ptr->next;      
            negetive->next=NULL;
            count2++;
         }
         else{
            temp=ptr;
            ptr=ptr->next;
            temp->next=negetive;
            negetive=temp;
         }
         
      }
   }
   return negetive;
}



void traversal(struct node *ptr)
{
   while(ptr!=NULL)
   {
      printf("%d ",ptr->data);
      ptr=ptr->next;
   }
}

int main()
{
   struct node *head,*negetive;
   head = (struct node *)malloc(sizeof(struct node));

   createll(head, 7);
   negetive=creating_two_ll(head);
   printf("Printing the elements of the negetive linklist...\n");
   traversal(negetive);
}


// As we can not return two values from the function so i have returned negetive only for 
// checking if it is working or not