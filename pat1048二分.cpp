//1048. Find Coins (25)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
int cmp(const void* a,const void *b)
{
    return *((int*)a)-*((int*)b);
}
int coin[MAXN],N,M;
bool find(int i,int k)
{
    int low=i+1,high=N-1;
    int mid=(low+high)/2;
    while(low<=high)
    {
        if(coin[mid]<k)
            low=mid+1;
        else if(coin[mid]==k)
        {
            return true;
        }
        else
            high=mid-1;
        mid=(low+high)/2;
    }
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&coin[i]);
        }
        qsort(coin,N,sizeof(coin[0]),cmp);
        for(i=0;i<N;i++)
        {
            if(find(i,M-coin[i]))
            {
                int low=min(coin[i],M-coin[i]),high=max(coin[i],M-coin[i]);
                printf("%d %d\n",low,high);
                break;
            }
        }
        if(i==N)
            printf("No Solution\n");
    }
    return 0;
}
