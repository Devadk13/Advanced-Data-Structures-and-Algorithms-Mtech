#include <stdio.h>


void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

void selectionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int  min=i;
        
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        swap(&arr[min],&arr[i]);
        
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
    selectionsort(arr,size);
    printarray(arr,size);
    return 0;
    
}
