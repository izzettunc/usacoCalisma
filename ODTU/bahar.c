#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  int dizi[10001]={0};
  int j,i,x,y,max=0;
  for(i=0;i<n;i++)
  {
    scanf("%d %d",&x,&y);
    for(j=(x-y>=0?x-y:0);j<=(x+y<=10000?x+y:10000);j++)
      dizi[j]++;
  }
  for(i=0;i<10001;i++)
    if(dizi[i]>max)
      max=dizi[i];
  printf("%d",max);
  return 0;
}
