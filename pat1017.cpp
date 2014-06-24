#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 10005
#define inf 1000000000

using namespace std;
struct Customer
{
	int h,m,s,p;
}c[MAXN];
bool cmp(const Customer& a,const Customer& b)
{
	if(a.h!=b.h)return a.h<b.h;
	if(a.m!=b.m)return a.m<b.m;
	return a.s<b.s;
}
bool check(const Customer& a)
{
	if(a.h<17||(a.h==17&&a.m==0&&a.s==0))return true;
	return false;
}
int main()
{
	int i,j,t,total,n,k;
	char time[10];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		Customer *window=new Customer[k];
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s%d",time,&c[i].p);
			c[i].h=(time[0]-'0')*10+time[1]-'0';
			c[i].m=(time[3]-'0')*10+time[4]-'0';
			c[i].s=(time[6]-'0')*10+time[7]-'0';
		}
		sort(c,c+n,cmp);
		for(i=0;i<k;i++)
		{
			window[i].h=8;
			window[i].m=0;
			window[i].s=0;
		}
		total=0;j=0;
		while(j<n)
		{
			//找当前最早有时间可供分配的
			if(!check(c[j]))break;
			Customer Min;
			for(i=0;i<k;i++)
			{
				if(i==0||cmp(window[i],Min))
				{
					Min=window[i];t=i;
				}
			}
			//总等待时间
			window[t]=cmp(c[j],window[t])?window[t]:c[j];
			total+=(window[t].h-c[j].h)*3600+(window[t].m-c[j].m)*60+window[t].s-c[j].s;
			window[t].m=(window[t].m+c[j].p)%60;
			window[t].h+=(window[t].m+c[j].p)/60;
			j++;
		}
		printf("%.1f\n",(total+0.0)/(60*j));
	}
    return 0;
}
