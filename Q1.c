// Write a C Program to store N elements to an array and then send all positive elements of the
// array to the end without altering the original sequence.

#include<stdio.h>


int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Start Entering the Elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=1; i<n; i++)
    {
        if(arr[i]<0)
        {
            int temp = arr[i];
            int j,copy,saved;
            for(j =0; j<i; j++)
            {   
                if(arr[j]>0)
                {
                    saved =arr[j];
                    break;
                }  
            }


            for(int k =j; k<i; k++)
            {   
                copy = arr[k+1];
                arr[k+1] = saved;
                saved = copy;
            }
            arr[j]=copy;
        }
    }

    printf("Shifting Positive elements to the right...\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}