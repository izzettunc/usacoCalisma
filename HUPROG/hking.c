#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct k
{
    long long point;
    long long color;
}hm;

int cmpfunc (const void * a, const void * b) {
    hm *n1=(hm*)a,*n2=(hm*)b;
   return ( n1->point-n2->point );
}
int cmpfunc2 (const void * a, const void * b) {
    int *n1=(int*)a,*n2=(int*)b;
   return ( n1-n2 );
}
int main()
{
    long long i,n,m,k,j;
    scanf("%lld %lld %lld\n",&n,&m,&k);
    long long temp=7,read,len=n+m;
    long long okanPos=(len)/2;
    hm *konser=(hm*)calloc(n+m,sizeof(hm));
    long long *leds=(long long*)calloc(n,sizeof(long long));
    long long flag=0;
    long long element;
    if(len%2==1)
    {
        element=konser[okanPos].point;
        flag=1;
    }
    long long ledCount=0;
    for(i=0;i<len;i++)
      konser[i].point=0;
    for(j=0;j<n;j++)
    {
        scanf("%lld",&read);
        konser[j].point+=(temp*read);
        leds[j]+=(temp*read);
        konser[j].color=1;
    }
    temp=3;
    for(j=0;j<n;j++)
    {
        scanf("%lld",&read);
        konser[j].point+=(temp*read);
        leds[j]+=(temp*read);
        konser[j].color=1;
    }
    temp=7;
    for(j=n;j<len;j++)
    {
        scanf("%lld",&read);
        konser[j].point+=(temp*read);
        konser[j].color=2;
    }
    temp=3;
    for(j=n;j<len;j++)
    {
        scanf("%lld",&read);
        konser[j].point+=(temp*read);
        konser[j].color=2;
    }
    qsort(konser,len,sizeof(hm),cmpfunc);
    //qsort(leds,n,sizeof(int),cmpfunc2);
    long long* low=(long long*)calloc(konser[len-1].point+1,sizeof(long long));
    long long* high=(long long*)calloc(konser[len-1].point+1,sizeof(long long));
    long long start=0,finish=konser[0].point;
    long long higher=n;
    long long lower=0;
    for(i=0;i<len-1;i++)
    {
        for(j=start;j<=finish;j++)
        {
            low[j]=lower;
            high[j]=higher;
        }
        start=konser[i].point;finish=konser[i+1].point;
        if(konser[i].color==1)
        {
            higher--;
            lower++;
        }
    }
    /*for(i=0;i<n;i++)
    {
        high[leds[i]]++;
    }*/
    for(j=start;j<=finish;j++)
    {
        low[j]=lower;
        high[j]=higher;
    }
    /*for(i=0;i<konser[len-1].point+1;i++)
    {
        printf("%lld %lld %lld \n",i,high[i],low[i]);
    }*/
    long long geci,maxi=0,max=0,bu,ku;
    if(flag==1)
    {
        /*for(j=0;j<n;j++)
        {
            if(leds[j]>=element-k && element+k>=leds[j])
            {
                ledCount++;
            }
        }*/
        if(element-k>=0)
            bu=high[element-k];
        else
            bu=n;
        if(element+k<=konser[len-1].point)
            ku=low[element+k];
        else
            ku=n;
        //printf("%lld %lld %lld\n",high[i-k],low[i+k],ku+bu-n);
        if(ku+bu-n>max)
        {
            max=ku+bu-n;
            maxi=element;
        }
        printf("%lld\n%lld\n",element,max);
        return 0;
    }
    long long b1=konser[okanPos-1].point,b2=konser[okanPos].point;
    /*printf("%d %d\n",b1,b2);*/
    for(i=b1;i<=b2;i++)
    {
        if(i-k>=0)
            bu=high[i-k];
        else
            bu=n;
        if(i+k<=konser[len-1].point)
            ku=low[i+k];
        else
            ku=n;
        //printf("%lld %lld %lld\n",high[i-k],low[i+k],ku+bu-n);
        if(ku+bu-n>max)
        {
            max=ku+bu-n;
            maxi=i;
        }
    }
    printf("%lld\n%lld\n",maxi,max);
    return 0;
}
