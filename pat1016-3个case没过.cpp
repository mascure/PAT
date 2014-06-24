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
struct Record
{
	char user[25],time[15],state[10];
}r[MAXN];
int charge[24];
//按姓名排序
bool cmp1(const Record& a,const Record& b)
{
	if(strcmp(a.user,b.user)<=0)return true;
	return false;
}
bool cmp2(const Record& a,const Record& b)
{
	if(strcmp(a.time,b.time)<0)return true;
	return false;
}
void compute(const Record& a,const Record& b,int& len,int& cost)
{
	int ad=(a.time[3]-'0')*10+a.time[4]-'0';
	int ah=(a.time[6]-'0')*10+a.time[7]-'0';
	int am=(a.time[9]-'0')*10+a.time[10]-'0';
	int bd=(b.time[3]-'0')*10+b.time[4]-'0';
	int bh=(b.time[6]-'0')*10+b.time[7]-'0';
	int bm=(b.time[9]-'0')*10+b.time[10]-'0';
	int i;len=0;cost=0;
	if(ad==bd)
	{
	cost=-am*charge[ah];len=-am;
	for(i=ah;i<bh;i++)
	{
		cost+=60*charge[i];
		len+=60;
	}
	cost+=bm*charge[bh];
	len+=bm;
	}
	else
	{
		cost=-am*charge[ah];
		len=-am;
		for(i=ah;i<24;i++)
		{
			cost+=60*charge[i];
			len+=60;
		}
		int day_total=0;
		for(i=0;i<24;i++)
		{
			day_total+=60*charge[i];
		}
		cost+=day_total*(bd-ad-1);
		len+=24*60*(bd-ad-1);
		for(i=0;i<bh;i++)
		{
			cost+=60*charge[i];
			len+=60;
		}
		cost+=bm*charge[bh];
		len+=bm;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	int i,j,t,n,un[MAXN],unum;
	char name[MAXN][25];
	for(i=0;i<24;i++)scanf("%d",&charge[i]);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%s%s%s",r[i].user,r[i].time,r[i].state);
	}
	sort(r,r+n,cmp1);
	memset(un,0,sizeof(un));
	i=0;j=0;
	while(j<n)
	{
		strcpy(name[i],r[j].user);un[i]=1;j++;
		while(j<n&&strcmp(name[i],r[j].user)==0)
		{
			j++;un[i]++;
		}
		i++;
	}
	unum=i;
	int start=0,total=0;
	for(i=0;i<unum;i++)
	{
		total=0;
		sort(r+start,r+start+un[i],cmp2);
		printf("%s %c%c\n",r[start].user,r[start].time[0],r[start].time[1]);
		j=start;
		while(j<start+un[i])
		{
			//查找第一个on-line
			while(j<start+un[i]&&strcmp(r[j].state,"on-line")!=0)j++;
			if(j<start+un[i]&&strcmp(r[j].state,"on-line")==0)
			{
				t=j+1;
				if(j+1<start+un[i]&&strcmp(r[j+1].state,"off-line")==0)
				{
					int cost,len;
					compute(r[j],r[j+1],len,cost);
					total+=cost;
					printf("%s %s %d $%d.%d\n",r[j].time+3,r[t].time+3,len,cost/100,cost%100);
				}
			}
			j=j+1;
		}
		printf("Total amount: $%d.%02d\n",total/100,total%100);
		start+=un[i];
	}
	return 0;
}