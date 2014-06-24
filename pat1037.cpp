//1037. Magic Coupon (25)无需大数
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
#define MAXN 100005
using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    freopen("in.txt","r",stdin);
    int i,NC,NP;
    int C[MAXN],P[MAXN],ans;
    while(scanf("%d",&NC)!=EOF)
    {
        for(i=0;i<NC;i++)
        scanf("%d",&C[i]);
        scanf("%d",&NP);
        qsort(C,NC,sizeof(int),cmp);
        for(i=0;i<NP;i++)
        scanf("%d",&P[i]);
        qsort(P,NP,sizeof(int),cmp);
        ans=0;
        for(i=0;i<NC&&i<NP&&C[i]<0&&P[i]<0;i++)
        ans+=C[i]*P[i];
        for(i=0;i<NC&&i<NP&&C[NC-i-1]>0&&P[NP-i-1]>0;i++)
        ans+=C[NC-i-1]*P[NP-i-1];
        printf("%d\n",ans);
    }
    return 0;
}
