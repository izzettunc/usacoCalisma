#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,n,kcount=0;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        int b,m;
        char w;
        scanf("%d %d %c",&b,&m,&w);
        int last=((b-1)%(m+1));
        if(last==0)
        {
            if(w=='A')
                kcount++;
        }
        else
        {
            if(w=='K')
                kcount++;
        }
        //printf("%d %d\n",last,kcount);
    }
    int acount=n-kcount;
    if(acount<kcount)
    {
        printf("Asya %d",acount);
    }
    else
        printf("Kayra %d",kcount);
    return 0;
}
