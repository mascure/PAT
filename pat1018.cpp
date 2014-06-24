//http://pat.zju.edu.cn/contests/pat-a-practise/1018
/*求最短路径，沿最短路走一遍的过程中，将每个节点的存车量变为容量的一半，找出发需要带的车最少的。
因此，在有多条最短路相等时，需将这些路径记录下来，并计算出发带车数量和剩余数量。
步骤：
Dijkstra求最短路，每个节点的前序节点用vector表示
以树遍历所有最短路，找到一条完整路径时，计算出发需要带的车数量和到终点后剩下的数量。
从中选择出发数最少的，若出发数相等，选剩下数最少的
注意计算带车数量时，只考虑从开始到终点，不考虑从终点返回起点过程。
*/
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
            sum+=current[nowPath[i]];
            take+=capacity/2-current[nowPath[i]];
            if(most_take<take)most_take=take;
        }
        int remain=most_take+sum-nowPath.size()*capacity/2;
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
