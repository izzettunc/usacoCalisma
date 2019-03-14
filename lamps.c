/*
  ID:hiy.1991
  PROG:lamps
  LANG:C
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
void sort(int **res,int resLen,int inLen)
{
	int i,j,k,power,num1,num2,numTemp;
	for(i=0;i<resLen-1;i++)
	{
		for(j=0;j<resLen-1-i;j++)
		{
			num1=num2,power=0;
			for(k=5;k>=0;k--)
			{
				numTemp=(res[j][k]==1)?res[j][k]:0;
				num1+=numTemp*pow(2,power);
				numTemp=(res[j+1][k]==1)?res[j+1][k]:0;
				num2+=numTemp*pow(2,power);
				power++;
			}
			if(num1>num2)
			{
				int *temp=res[j];
				res[j]=res[j+1];
				res[j+1]=temp;
			}
		}
	}
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
  // 0 nötr 1 açýk -1 kapalý
  do {
    fscanf(fi,"%d",&temp);
    if(temp!=-1)
    {
      if(counter==0)
        lamps[temp-1]=1;
      else
        lamps[temp-1]=-1;
    }
    else
     counter++;
  } while(counter!=2);
  if(c==0)
  {
  	for(i=0;i<n-1;i++)
  	{
  		if(lamps[i]==-1)
		{
			fprintf(fo,"IMPOSSIBLE\n");
			exit(0); 	
	  	}	
	}
	for(i=0;i<n-1;i++)
		fprintf(fo,"1");
	fprintf(fo,"1\n");
	exit(0);
  }
  int patternLen=16;
  row pattern[patternLen];
  for(i=0;i<patternLen;i++)
  {
    pattern[i].state=calloc(n,sizeof(int));
    pattern[i].counter=0;
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
            pattern[temp].counter=l+k+j+i;
            if(i)
            {
              buttonPress(0,pattern[temp].state,n);
            }
            if(j)
            {
              buttonPress(3,pattern[temp].state,n);
            }
            if(k)
            {
              buttonPress(2,pattern[temp].state,n);
            }
            if(l)
            {
              buttonPress(1,pattern[temp].state,n);
            }
          }
        }
      }
    }
  }
  int countButton=buttonCount(c);
  int **res=(int**)calloc(patternLen,sizeof(int*)),resCount=0;
  for(i=0;i<patternLen;i++)
  	res[i]=(int*)calloc(n,sizeof(int));
  for(i=patternLen-1;i>=0;i--)
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
        if(!(pattern[i].counter==2 || pattern[i].counter==4 || pattern[i].counter==0))
          continue;
      }
    }
    for(j=0;j<n;j++)
    {
      if((lamps[j]==-1 && pattern[i].state[j]!=-1) || (lamps[j]==1 && pattern[i].state[j]!=1))
      {
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
  if(resCount==0)
  {
  	fprintf(fo,"IMPOSSIBLE\n");
  }
  sort(res,resCount,n);
  for(i=0;i<resCount;i++)
  {
    for(j=0;j<n;j++)
    {
      temp=(res[i][j]==1)?res[i][j]:0;
      fprintf(fo,"%d",temp);
    }
    fprintf(fo,"\n");
  }
  exit(0);
}
