#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int num;
    struct node* next;
};

struct node* createll(struct node *ptr, int n)
{
   struct node *prev, *start=ptr, *end, *new;
   printf("Time for Process No 1: ");
   scanf("%d",&ptr->data);
   ptr->num= 1;
   prev=ptr;
   ptr->next=start;

   for(int i =2; i<=n; i++)
   {
      new = (struct node *)malloc(sizeof(struct node));
      printf("Time for Process No %d: ",i);
      scanf("%d",&new->data);
      new->num= i;
      prev->next=new;
      prev = new;
      new->next=start;
   }
   end=new;
   return end;
}


// void display(struct node* ptr)
// {
//     struct node* start = ptr;
//     do
//     {
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     } while (ptr!= start);
    
// }


void time_sharing(struct node* ptr, struct node* end)
{
    struct node* start,*prev;
    int time_counter= 0, count= 0;
    start=ptr;
    prev=end;
    do
    {
        if(count<=0)
        start->data = start->data -10;
        time_counter = time_counter + 10;
        if(start->data == 0)
        {
            printf("Process No %d took %d ms\n",start->num, time_counter);
            prev->next = start->next;
        }
        else
        prev=start;
        start=start->next;

    }while(start->next!=start);
}


int main()
{
    struct node* head, *end;
    head = (struct node*)malloc(sizeof(struct node));
    end =createll(head,5);
    time_sharing(head,end);

}