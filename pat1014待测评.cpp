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
void print(int time)
{
	if(time>=inf)printf("Sorry\n");
	else
	{
		int h=8+time/60,m=time%60;
		printf("%02d:%02d\n",h,m);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
    int i,j,n,m,k,q,ptime[MAXN],end_time[MAXN],now[21];
	while(scanf("%d%d%d%d",&n,&m,&k,&q)!=EOF)
	{
		memset(now,0,sizeof(now));
		queue<int>w[21];
		for(i=1;i<=k;i++)
			scanf("%d",&ptime[i]);
		int t=1;
		//把n个窗口铺满
		for(i=0;i<m&&t<=k;i++)
		{
			for(j=0;j<n&&t<=k;j++)
			{
				w[j].push(t++);
			}
		}
		for(i=0;i<n;i++)
		{
			if(!w[i].empty())
			now[i]=ptime[w[i].front()];
		}
		int Min,tt,can_use[21];
		for(i=0;i<n;i++)can_use[i]=1;
		//将剩余的顾客压入队列
		while(t<=k)
		{
			Min=540;
			for(i=0;i<n;i++)
			{
				if(i==0||Min>now[i])
				{Min=now[i];tt=i;}
			}
			if(Min==540)
			{end_time[t++]=inf;continue;}
			int num=w[tt].front();
			end_time[num]=now[tt];
			w[tt].pop();
			num=w[tt].front();
			now[tt]+=ptime[num];
			w[tt].push(t++);
		}
		for(i=0;i<n;i++)
		{
			while(!w[i].empty())
			{
				int num=w[i].front();
				w[i].pop();
				if(now[i]>540)end_time[num]=inf;
				else
				{
					end_time[num]=now[i];
					if(!w[i].empty())
					{
						num=w[i].front();
						now[i]+=ptime[num];
					}
				}
			}
		}
		for(i=0;i<q;i++)
		{
			int id;
			scanf("%d",&id);
			if(id>k)printf("Sorry\n");
			else
			print(end_time[id]);
		}
	}
	return 0;
}