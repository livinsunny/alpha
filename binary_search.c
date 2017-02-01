


#include<stdio.h>

#define SIZE 10
int main()
{
    int arr[10]={23,34,55,56,66,76,82,85,88,91};
    int number=0;
    int ret=0;
    printf("Enter the number to find ");
    scanf("%d",&number);
    ret=binary_search(arr,number);
    if(ret)
        printf("Found at %d ",ret);
    else
        printf("Not found \n");
}


int binary_search(int a[],int key)
{
    int mid=0;
    int low=0;
    int high=SIZE -1;

    while(low <= high)
    {
        mid=(low+high)/2;

        if(key == a[mid])
            return mid+1;
        else if(key < a[mid])
        {
            high = mid-1;
        }
        else
        {
            low =mid+1;
        }

    }
    return 0;
}
