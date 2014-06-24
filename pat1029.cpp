#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
//#include<map>
#include<algorithm>
#define MAXN 1005
#define inf 0x7fffffff
#define LL long long
using namespace std;
int a[1000005],b[1000005];
int main()
{
	freopen("in.txt","r",stdin);
    int i,n1,n2;
	while(scanf("%d",&n1)!=EOF)
	{
		for(i=0;i<n1;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
		{
			scanf("%d",&b[i]);
		}
		int pa=0,pb=0,t=-1,flag=1;
		while(pa<n1&&pb<n2&&t<(n1+n2-1)/2)
		{
			if(a[pa]<b[pb])
			{
				pa++;flag=1;
			}
			else
			{
				pb++;flag=2;
			}
			t++;
		}
		if(t>=(n1+n2-1)/2)
		{
			if(flag==1)
				printf("%d\n",a[pa-1]);
			else if(flag==2)
				printf("%d\n",b[pb-1]);
		}
		else
		{
			if(pa<n1)
			{
				while(pa<n1&&t<(n1+n2-1)/2)
				{t++;pa++;}
				printf("%d\n",a[pa-1]);
			}
			else
			{
				while(pb<n2&&t<(n1+n2-1)/2)
				{t++;pb++;}
				printf("%d\n",b[pb-1]);
			}
		}
	}
	return 0;
}