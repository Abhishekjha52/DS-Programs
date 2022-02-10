#include <stdio.h>

int main()
{
    int a[100],i,n,key,flag=0;
    int low,high,mid;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            printf("%d is found at location %d\n",key,mid+1);
            break;
        }
         else if(a[mid]<key)
            low=mid+1;
        else if(key<mid)
            high=mid-1;
    }
    if(low>high)
            printf("Not found\n");

}