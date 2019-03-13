/*
  ID:hiy.1991
  PROG:lamps
  LANG:C
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct a
{
  int *state;
  int counter;
}row;

void buttonPress(int type,int arr[],int arrLength)
{
  int i;
  switch (type) {
    case 0:
      for(i=0;i<arrLength;i++)
      {
        arr[i]*=-1;
      }
      break;
    case 1:
      for(i=0;i<arrLength;i+=2)
      {
        arr[i]*=-1;
      }
      break;
    case 2:
      for(i=1;i<arrLength;i+=2)
      {
        arr[i]*=-1;
      }
      break;
    case 3:
      for(i=0;i<arrLength;i+=3)
      {
        arr[i]*=-1;
      }
      break;
  }
}
int buttonCount(int c)
{
  return (c<3)?c:(c%2==0)?6:4;
}

int main()
{
  FILE *fi,*fo;
  fi=fopen("lamps.in","r");
  fo=fopen("lamps.out","w");
  int n,c,i,j,k,l;
  fscanf(fi,"%d\n%d",&n,&c);
  int *lamps=calloc(n,sizeof(int));
  int temp;
  int counter=0;
  //0 nötr -1 kapalı 1 açık
  do {
    fscanf(fi,"%d",&temp);
    if(temp!=-1)
    {
      if(counter==0)
        lamps[temp]=1;
      else
        lamps[temp]=-1;
    }
    else
     counter++;
  } while(counter!=2);
  row pattern[15];
  for(i=0;i<15;i++)
  {
    pattern[i].state=calloc(n,sizeof(int));
    for(j=0;j<n;j++)
    {
      pattern[i].state[j]=1;
    }
  }
  for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    {
      for(k=0;k<2;k++)
      {
        for(l=0;l<2;l++)
        {
          temp=l+2*k+4*j+8*i;
          if(temp)
          {
            pattern[temp-1].counter=l+k+j+i;
            if(i)
            {
              buttonPress(0,pattern[temp-1].state,n);
            }
            if(j)
            {
              buttonPress(1,pattern[temp-1].state,n);
            }
            if(k)
            {
              buttonPress(2,pattern[temp-1].state,n);
            }
            if(l)
            {
              buttonPress(3,pattern[temp-1].state,n);
            }
          }
        }
      }
    }
  }
  int countButton=buttonCount(c);
  int res[15][n],resCount=0;
  for(i=0;i<15;i++)
  {
    int check=1,check2=1;
    if(countButton<3)
    {
      if(pattern[i].counter!=countButton)
        continue;
    }
    else
    {
      if(countButton==4)
      {
        if(!(pattern[i].counter==1 || pattern[i].counter==3))
          continue;
      }
      else
      {
        if(!(pattern[i].counter==2 || pattern[i].counter==4))
          continue;
      }
    }
    for(j=0;j<n;j++)
    {
      if((lamps[j-1]==-1 && pattern[i].state[j-1]!=-1) || (lamps[j-1]==1 && pattern[i].state[j-1]!=1))
      {
        if(i==0)
          printf("%d %d %d\n",j,lamps[j-1],pattern[i].state[j-1]);
        check=0;
        break;
      }
    }
    if(check)
    {
      for(j=0;j<resCount;j++)
      {
        if(res[j]==pattern[i].state)
        {
          check2=0;
        }
      }
      if(check2)
      {
        for(j=0;j<n;j++)
          res[resCount][j]=pattern[i].state[j];
        resCount++;
      }
    }
  }
  for(i=0;i<resCount;i++)
  {
    for(j=0;j<n;j++)
    {
      temp=(res[i][j]==1)?res[i][j]:0;
      printf("%d ",temp);
    }
    printf("\n");
  }
  exit(0);
}
