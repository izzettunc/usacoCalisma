#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	char temp[100000];
	char instring[100000];
	int templen=0;
	
void ekle ( int start, int end)
{		
	int i;
	for(i = start ; i <= end; i++)
	{
		temp[templen]=instring[i];	
		templen++;
	}
		
}


int main()
{
	
	int type[100000];
	int index[100000];
	int charcount=0;
	fgets(instring, sizeof(instring), stdin);
	int len,i=0;
	int bracketCount=0;
	do
	{
		if(instring[i]=='[')
		{
			index[bracketCount]=i;
			type[bracketCount]=0;
			bracketCount++;
		}
		else if(instring[i]==']')
		{
			index[bracketCount]=i;
			type[bracketCount]=1;
			bracketCount++;
		}	
		else charcount++;
		i++;
	}while(instring[i]!='\n' && instring[i]!='\r');
	len=i;
	index[bracketCount]=len+1;
	if(charcount == 0) return 0;		

	i=bracketCount-1;
	//s1
	if(type[i]==0 && index[i]<len-1)
	{
		ekle(index[i]+1,len-1);
		i--;
	}

	for(;i>=0;i--)
		if(type[i]==0)
			ekle(index[i]+1,index[i+1]-1);
	//
	//s2
	i=0;	
	if(index[i]>0)
	{
		ekle(0,index[0]-1);
	}
	//	
	//s3
	for(;i<=bracketCount;i++)
		if(type[i]==1)
			ekle(index[i]+1,index[i+1]-1);
	//
	if(temp[templen-1]=='\n' || temp[templen-1]=='\r')
		temp[templen-1]='\0';
	temp[templen]='\0';
	for(i=0;i<templen;i++)
		if(temp[i]=='\n' || temp[i]=='\r')
			temp[i]='\0';
	printf("%s",temp);
	return 0;	
}
