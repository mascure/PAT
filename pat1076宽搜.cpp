//http://pat.zju.edu.cn/contests/pat-a-practise/1076
/*
树的遍历，可以广搜，可以深搜
*/
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
//#include<map>
#define inf 0x7fffffff
#define LL long long
#define MAX_E 1000000
#define MAX_V 500
#define MAXN 1005
using namespace std;
vector<int> f[MAXN];
bool visited[MAXN];
int N,L;
int main()
{
	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d",&N,&L)!=EOF)
	{
	    for(i=0;i<N;i++)
	    {
	        int num;
	        scanf("%d",&num);
	        for(j=0;j<num;j++)
	        {
	            int id;
	            scanf("%d",&id);
	            f[id].push_back(i+1);
	        }
	    }
	    int K;
	    scanf("%d",&K);
	    while(K--)
	    {
	        fill(visited,visited+N+1,false);
	        int id;
	        scanf("%d",&id);
	        int ans=-1;
            queue<int> last;
            last.push(id);
            int level=L+1;
            while(level--)
            {
                queue<int> now;
                while(!last.empty())
                {
                    int front=last.front();
                    if(!visited[front])
                    {
                        visited[front]=true;
                        ans++;
                        for(i=0;i<f[front].size();i++)
                        {
                            int t=f[front][i];
                            now.push(t);
                        }
                    }
                    last.pop();
                }
                last=now;
            }
            printf("%d\n",ans);
	    }
	}
	return 0;
}
