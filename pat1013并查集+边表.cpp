#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
//#include<map>
#include<algorithm>
#define MAXN 1005
#define inf 0x7fffffff
#define LL long long
using namespace std;
int p[MAXN],r[MAXN];
struct edge
{
	int from,to;
}e[MAXN*MAXN];
int find(int x)
{
	if(p[x]!=x)
	{
		p[x]=find(p[x]);
	}
	return p[x];
}
void Union(int a,int b)
{
	if(r[a]>r[b])
	{
		p[b]=a;
	}
	else if(r[a]==r[b])
	{
		p[b]=a;
		r[a]++;
	}
	else
		p[a]=b;
}
int main()
{
    int i,j,a,b,n,m,k,ans;
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			e[i].from=a;e[i].to=b;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&a);a--;
			ans=n-2;
			for(j=0;j<n;j++)
			{
				p[j]=j;r[j]=1;
			}
			for(j=0;j<m;j++)
			{
				int pa=find(e[j].from),pb=find(e[j].to);
				if(e[j].from==a||e[j].to==a||pa==pb)continue;
				Union(pa,pb);ans--;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}