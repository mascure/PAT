#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
//#include<map>
#include<algorithm>
#define MAXN 100005
#define inf 0x7fffffff
#define LL long long
using namespace std;
struct student
{
	char id[10],name[10];
	int score;
}s[MAXN];
bool cmp1(const student& a,const student& b)
{
	if(strcmp(a.id,b.id)<0)return true;
	return false;
}
bool cmp2(const student& a,const student& b)
{
	if(strcmp(a.name,b.name)==0)
	{
		if(strcmp(a.id,b.id)<0)return true;
		else return false;
	}
	else if(strcmp(a.name,b.name)<0)return true;
	else
	return false;
}
bool cmp3(const student& a,const student& b)
{
	if(a.score==b.score)
	{
		if(strcmp(a.id,b.id)<0)return true;
		else return false;
	}
	return a.score<b.score;
}
int main()
{
	freopen("in.txt","r",stdin);
    int n,i,c;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s%s%d",s[i].id,s[i].name,&s[i].score);
		}
		if(c==1)
		{
			sort(s,s+n,cmp1);
			for(i=0;i<n;i++)
			{
				printf("%s %s %d\n",s[i].id,s[i].name,s[i].score);
			}
		}
		else if(c==2)
		{
			sort(s,s+n,cmp2);
			for(i=0;i<n;i++)
			{
				printf("%s %s %d\n",s[i].id,s[i].name,s[i].score);
			}
		}
		else if(c==3)
		{
			sort(s,s+n,cmp3);
			for(i=0;i<n;i++)
			{
				printf("%s %s %d\n",s[i].id,s[i].name,s[i].score);
			}
		}
	}
	return 0;
}