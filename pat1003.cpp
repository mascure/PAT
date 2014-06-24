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
int map[MAXN][MAXN];
int num[MAXN];
void dijkstra(int n,int s,int t,int& path_num,int& team_num)
{
	int i,j,visit[MAXN],dis[MAXN],now,Min,tt;
	int path[MAXN],team[MAXN];
	memset(visit,0,sizeof(visit));
	for(i=0;i<n;i++)
	{
		dis[i]=inf;
		path[i]=0;
		team[i]=num[i];
	}
	visit[s]=1;dis[s]=0;
	path[s]=1;
	now=s;
	for(i=0;i<n-1;i++)
	{
		//¸üÐÂ¾àÀë
		for(j=0;j<n;j++)
		{
			if(visit[j]||map[now][j]==inf)continue;
			if(dis[now]+map[now][j]<dis[j])
			{
				dis[j]=dis[now]+map[now][j];
				path[j]=path[now];
				team[j]=team[now]+num[j];
			}
			else if(dis[now]+map[now][j]==dis[j])
			{
				path[j]+=path[now];
				if(team[j]<team[now]+num[j])
					team[j]=team[now]+num[j];
			}
		}
		Min=inf,tt=-1;
		for(j=0;j<n;j++)
		{
			if(visit[j]==0&&dis[j]<Min){Min=dis[j];tt=j;}
		}
		now=tt;visit[now]=1;
	}
	path_num=path[t];team_num=team[t];
}
int main()
{
    int i,j,n,m,s,t,a,b,d;
	while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			map[i][i]=0;
			for(j=i+1;j<n;j++)
				map[i][j]=map[j][i]=inf;
		}
		for(i=0;i<n;i++)scanf("%d",&num[i]);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&d);
			map[a][b]=map[b][a]=d;
		}
		int path_num,team_num;
		dijkstra(n,s,t,path_num,team_num);
		printf("%d %d\n",path_num,team_num);
	}
	return 0;
}
