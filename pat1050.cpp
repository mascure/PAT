//1050. String Subtraction (20)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 40005
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int i,j;
    int asc[300];
    char S1[MAXN],S2[MAXN];
    gets(S1);
    gets(S2);
    int len1=strlen(S1),len2=strlen(S2);
    for(i=0;i<256;i++)
        asc[i]=0;
    for(i=0;i<len2;i++)
        asc[(unsigned int)S2[i]]=1;
    for(i=0,j=0;i<len1;i++)
    {
        if(asc[(unsigned int)S1[i]]==0)
        {
            S1[j++]=S1[i];
        }
    }
    S1[j]='\0';
    printf("%s\n",S1);
    return 0;
}
