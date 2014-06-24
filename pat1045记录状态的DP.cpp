//1045. Favorite Color Stripe (30)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#define inf 0x7fffffff
#define MAXN 10005
using namespace std;
int stripe[MAXN],repeate[MAXN];
int num[205];
void filter(int L,int& rL)
{
    int i=0,lastIndex=0,nextIndex=1;
    rL=0;
    i=1;
    repeate[0]=1;
    while(i<L)
    {
        if(stripe[i]==stripe[lastIndex])
        {
            repeate[lastIndex]++;
        }
        else
        {
            stripe[nextIndex]=stripe[i];
            repeate[nextIndex]=1;
            lastIndex=nextIndex;
            nextIndex++;
        }
        i++;
    }
    rL=nextIndex;
    i=0;
    int k=0;
    while(i<rL)
    {
        if(num[stripe[i]]!=-1)
        {
            stripe[k]=stripe[i];
            repeate[k]=repeate[i];
            k++;
        }
        i++;
    }
    rL=k;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,N,M,L,Max;
    while(scanf("%d",&N)!=EOF)
    {
        scanf("%d",&M);
        for(i=0;i<N;i++)
        {
            num[i+1]=-1;
        }
        int color;
        //定位颜色的顺序
        for(i=0;i<M;i++)
        {
            scanf("%d",&color);
            num[color]=i;
        }
        scanf("%d",&L);
        for(i=0;i<L;i++)
        {
            scanf("%d",&stripe[i]);
        }
        int rL;
        filter(L,rL);
        Max=0;
        for(i=0;i<rL;i++)
        {
            if(num[stripe[i]]==-1)continue;
            int sum=0;
            for(j=0;j<i;j++)
            {
                if(num[stripe[j]]==-1)
                    continue;
                if(num[stripe[i]]>=num[stripe[j]]&&repeate[i]+repeate[j]>sum)
                    sum=repeate[i]+repeate[j];
            }
            if(sum!=0)
                repeate[i]=sum;
            if(repeate[i]>Max)Max=repeate[i];
        }
        printf("%d\n",Max);
    }
    return 0;
}
