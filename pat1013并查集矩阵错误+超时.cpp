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
int map[MAXN][MAXN],flag[MAXN],p[MAXN],r[MAXN];
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
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			map[a][b]=map[b][a]=1;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&a);a--;
			ans=n-2;
			for(j=0;j<n;j++)
			{
				flag[j]=1;p[j]=j;r[j]=1;
			}
			flag[a]=0;
			for(j=0;j<n;j++)
			{
				if(flag[j]==0)continue;
				int pa=find(j);
				for(k=0;k<n;k++)
				{
					if(flag[k]==0||map[j][kzr]==0||j==k)continue;
					int pb=find(k);
					if(pa!=pb)
					{Union(pa,pb);ans--;}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
