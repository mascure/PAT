//pat 1018. Public Bike Management (30)
//Dijkstra求最短路径，但在有两条最短路相等时，记录前序节点需做变形：两个节点均需记录下来，最后，以树遍历所有最短路，根据节点的存车量找到最短路径
//出发带车中选带的最少的；回来带车和出发带车选回来带车；回来带车选带的最少的
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
//#include<map>
#include<algorithm>
#define MAXN 505
#define inf 0x7fffffff
#define LL long long
using namespace std;

int map[MAXN][MAXN];
//前一个节点序列
vector<int> pre[MAXN];
vector<int> path;
int ans_take=inf,ans_remain=inf;
int current[MAXN];
int capacity;
void dijkstra(int s,int min[MAXN],int n)
{
    int i,j,k,v[MAXN];
    for(i=0;i<n;i++)
    {
        min[i]=inf;v[i]=0;
    }
    for(min[s]=0,j=0;j<n;j++)
    {
        for(k=-1,i=0;i<n;i++)
        {
            if(!v[i]&&(k==-1||min[i]<min[k]))
            k=i;
        }
        for(v[k]=1,i=0;i<n;i++)
        {
            if(!v[i]&&min[k]!=inf&&map[k][i]!=inf&&min[k]+map[k][i]<=min[i])
            {
                //若更短，则更新距离，并清空前序节点后将k加入前序节点
                if(min[k]+map[k][i]<min[i])
                {
                    min[i]=min[k]+map[k][i];
                    pre[i].clear();
                    pre[i].push_back(k);
                }
                //若相等，则直接将k加入前序节点
                else
                {
                    pre[i].push_back(k);
                }
            }
        }
    }
    return;
}
//
void find(int start,int end,int num,vector<int> nowPath)
{
    int i;
    if(start==end)
    {
        int most_take=0,take=0,sum=0;
        for(i=0;i<nowPath.size();i++)
        {
            sum+=current[nowPath[i];
            take+=capacity/2-current[nowPath[i];
            if(most_take<take)most_take=take;
        }
        int remain=take+sum-nowPath.size()*capacity/2;
        if(most_take<ans_take||(most_take==ans_take&&remain<ans_remain))
        {
            ans_take=most_take;
            ans_remain=remain;
            path=nowPath;
        }
        return ;
    }
    for(i=0;i<pre[start].size();i++)
    {
        int s=pre[start][i];
        nowPath.push_back(s);
        find(s,end,num+current[s],nowPath);
        nowPath.pop_back();
    }
}

int main()
{
	freopen("in.txt","r",stdin);
    int i,j,N,Sp,M,Min[MAXN];
	while(scanf("%d%d%d%d",&capacity,&N,&Sp,&M)!=EOF)
	{
	    current[0]=0;
	    ans_take=inf,ans_remain=inf;
	    for(i=0;i<N;i++)
	    scanf("%d",&current[i+1]);
	    for(i=0;i<=N;i++)
	    {
	        map[i][i]=0;
	        for(j=i+1;j<=N;j++)
            map[i][j]=map[j][i]=inf;
	    }
	    int a,b,dis;
	    for(i=0;i<M;i++)
	    {
	        scanf("%d%d%d",&a,&b,&dis);
	        map[b][a]=map[a][b]=dis;
	    }
	    dijkstra(Sp,Min,N+1);
	    vector<int> tmp;
	    find(0,Sp,0,tmp);
	    printf("%d 0",ans_take);
	    for(i=0;i<path.size();i++)
	    printf("->%d",path[i]);
	    printf(" %d\n",ans_remain);
	}
	return 0;
}
