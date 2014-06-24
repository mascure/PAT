#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define MAXN 505
#define inf 0x7fffffff
#define LL long long
using namespace std;
struct edge
{
	int from,to,len;
	int next;
}e[MAXN*MAXN];
int num[MAXN],p[MAXN];
void SPFA(int n,int s,int t,int& path_num,int& team_num)
{
	int i,queue[MAXN],front,rear,dis[MAXN],flag[MAXN],path[MAXN],team[MAXN];
	for(i=0;i<n;i++)
	{
		dis[i]=inf;
		flag[i]=0;
		path[i]=0;team[i]=0;
	}
	queue[0]=s;front=0;rear=1;
	dis[s]=0;flag[s]=1;path[s]=1;team[s]=num[s];
	while(front!=rear)
	{
		int v=queue[front++];
		if(front==MAXN)front=0;
		for(i=p[v];i!=-1;i=e[i].next)
		{
			if(dis[e[i].to]>dis[v]+e[i].len)
			{
				dis[e[i].to]=dis[v]+e[i].len;
				path[e[i].to]=path[v];
				team[e[i].to]=team[v]+num[e[i].to];
				if(!flag[e[i].to])
				{
					flag[e[i].to]=1;
					queue[rear++]=e[i].to;
					if(rear==MAXN)rear=0;
				}
			}
			else if(dis[e[i].to]==dis[v]+e[i].len)
			{
				path[e[i].to]+=path[v];
				if(team[e[i].to]<team[v]+num[e[i].to])
					team[e[i].to]=team[v]+num[e[i].to];
			}
		}
		flag[v]=0;
	}
	path_num=path[t];team_num=team[t];
}
int main()
{
    int i,n,m,s,t,a,b,d;
	while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);p[i]=-1;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&d);
			//ÎÞÏòÍ¼
			int p1=2*i,p2=2*i+1;
			e[p1].from=a;e[p1].to=b;e[p1].len=d;e[p1].next=p[a];p[a]=p1;
			e[p2].from=b;e[p2].to=a;e[p2].len=d;e[p2].next=p[b];p[b]=p2;
		}
		int path_num,team_num;
		SPFA(n,s,t,path_num,team_num);
		printf("%d %d\n",path_num,team_num);
	}
	return 0;
}
