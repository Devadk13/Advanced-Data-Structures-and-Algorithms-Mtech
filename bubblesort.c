#include <stdio.h>
#include <stdbool.h>


void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}


void bubblesort(int arr[],int n)
{
    int i,j;
    bool swapped;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped=true;
                
            }
        }
        if(swapped==false)
        break;
    }
}


void printarray(int arr[],int n)
{
    printf("The sorted array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int size;
    int arr[100];
    printf("Enter the size of array you want to sort ");
    scanf("%d",&size);
    
    printf("Enter the array\n");
    for(int k=0;k<size;k++)
    {
        scanf("%d",&arr[k]);
    }
    bubblesort(arr,size);
    printarray(arr,size);
    return 0;
    
}
