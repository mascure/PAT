//http://pat.zju.edu.cn/contests/pat-a-practise/1073
/*
数的科学表示法转换为常规表示法。
注意细节！
*/
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
//#include<map>
#include<algorithm>
#define inf 0x7fffffff
#define LL long long
#define MAX_E 1000000
#define MAX_V 500
#define MAXN 10005
using namespace std;
//bellman-ford
char in[MAXN];
int mi(int start,int end)
{
    int ans=0;
    while(start!=end)
    {
        ans=ans*10+in[start]-'0';
        start++;
    }
    return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(scanf("%s",in)!=EOF)
	{
	    int len=strlen(in),E;
	    for(i=0;i<len;i++)
	    {
	        if(in[i]=='E')
	        {
	            E=i;break;
	        }
	    }
	    if(in[0]=='-')printf("-");
	    int m=mi(E+2,len);
	    //幂为正
	    if(in[E+1]=='+')
	    {
	        printf("%c",in[1]);
	        for(i=2;i+2<E&&i-2<m;i++)
	        {
	            printf("%c",in[i+1]);
	        }
	        if(i-2==m)
	        {
	            printf(".");
                for(;i+1<E;i++)
                printf("%c",in[i+1]);
                printf("\n");
	        }
	        else
	        {
	            printf("%c",in[i+1]);
	            i++;
	            for(;i-2<m;i++)
                printf("0");
                printf("\n");
	        }
	    }
	    else
	    {
	        if(m==0)
	        {
	            in[E]='\0';
	            printf("%s\n",in+1);
	        }
	        else
	        {
	            printf("0.");
	            for(i=0;i<m-1;i++)
	            printf("0");
	            printf("%c",in[1]);
	            in[E]='\0';
	            printf("%s\n",in+3);
	        }
	    }
	}
	return 0;
}
