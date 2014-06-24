#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#define MAXN 10005
using namespace std;
int cnt[MAXN],num[100005];
int main()
{
    //freopen("in.txt","r",stdin);
    int i,N;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=1;i<=10000;i++)
            cnt[i]=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&num[i]);
            cnt[num[i]]++;
        }
        for(i=0;i<N;i++)
        {
            if(cnt[num[i]]==1)
            {
                printf("%d\n",num[i]);
                break;
            }
        }
        if(i==N)
        {
            printf("None\n");
        }
    }
    return 0;
}
