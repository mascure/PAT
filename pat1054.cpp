//1054. The Dominant Color (20)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 0x7fffffff
#define MAXN 500005
using namespace std;
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int c[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,N,M;
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                scanf("%d",&c[i*M+j]);
            }
        }
        qsort(c,N*M,sizeof(c[0]),cmp);
        j=1;
        int cnt=1,ans=c[0];
        while(j<N*M)
        {
            if(c[j]==c[j-1])
            {
                cnt++;
                if(cnt>N*M/2)
                {
                    ans=c[j];
                    break;
                }
            }
            else
            {
                cnt=1;
            }
            j++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
