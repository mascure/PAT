//1031. Hello World for U (20)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int i,j,n1,n2;
	char s[100],tu[100][100];
	while(scanf("%s",s)!=EOF)
	{
	    int N=strlen(s);
	    int start=0;
	    if(N%2==0)start=4;
	    else start=3;
	    for(n2=start;n2<=N;n2+=2)
	    {
	        n1=(N+2-n2)/2;
	        if(n1<=n2)break;
	    }
	    n1=(N+2-n2)/2;
	    for(i=0;i<n1;i++)
	    {
	        for(j=0;j<n2;j++)
	        {tu[i][j]=' ';}
	        tu[i][j]='\0';
	    }
	    for(i=0;i<n1;i++)
	    {
	        tu[i][0]=s[i];
	    }
	    for(i=n1;i<n1+n2-1;i++)
	    {
	        tu[n1-1][i-n1+1]=s[i];
	    }
	    for(j=n1-2,i=n1+n2-1;i<N;i++,j--)
	    {
	        tu[j][n2-1]=s[i];
	    }
	    for(i=0;i<n1;i++)
	    printf("%s\n",tu[i]);
	}
	return 0;
}
