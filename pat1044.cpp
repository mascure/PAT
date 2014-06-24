//1044. Shopping in Mars (25)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
int num[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,N,M,Min;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Min=inf;
        for(i=0;i<N;i++)
        {
            scanf("%d",&num[i]);
            if(Min>num[i])
                Min=num[i];
        }
        //此处循环起点的一个剪枝，防止实际值远大于M的情况
        int total=Min>M?Min:M;
        bool Find=false;
        while(1)
        {
            int sum=num[0];
            j=1;
            for(i=0;i<N;i++)
            {
                while(sum<total&&j<N)
                {
                    sum+=num[j++];
                }
                if(sum==total)
                {
                    Find=true;
                    printf("%d-%d\n",i+1,j);
                    sum=sum-num[i];
                }
                else if(sum>total)
                {
                    sum=sum-num[i];
                }
                else if(j==N)
                break;
            }
            if(Find)
                break;
            else
                total++;
        }
    }
    return 0;
}
