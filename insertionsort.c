#include <stdio.h>


void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
    insertionsort(arr,size);
    printarray(arr,size);
    return 0;
    
}
