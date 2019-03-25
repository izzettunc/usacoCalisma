#include <stdio.h>

int main()
{
    int i,n;
    unsigned long long x,a[]={0,1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&x);
        printf("%llu\n",a[x]);
    }
}
