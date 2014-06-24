//1046. Shortest Distance (20)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define inf 0x7fffffff
#define MAXN 100005

using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int i,dis[MAXN],N,M;
    while(scanf("%d",&N)!=EOF)
    {
        dis[0]=0;
        for(i=1;i<=N;i++)
        {
            scanf("%d",&dis[i]);
            dis[i]=dis[i-1]+dis[i];
        }
        scanf("%d",&M);
        int left,right;
        while(M--)
        {
            scanf("%d%d",&left,&right);
            left--;
            right--;
            if(right<left)
            {
                int tmp=left;
                left=right;
                right=tmp;
            }
            int len=dis[right]-dis[left];
            int ans=min(len,dis[N]-len);
            printf("%d\n",ans);
        }
    }
    return 0;
}
