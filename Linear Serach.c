#include <stdio.h>

int main()
{
    int a[100],i,n,key,flag=0;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Enter found at location=%d\n",i+1);
    else
        printf("Element not found\n");
}
