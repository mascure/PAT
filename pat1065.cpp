//http://pat.zju.edu.cn/contests/pat-a-practise/1065
/*
64位数比较大小
题目比较弱，说是[-2^63,2^63]，其实为[-2^63,2^63),可以用long long解决，不必高精度数
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 105
typedef long long LL;
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int i,T;
    char n1[MAXN],n2[MAXN],n3[MAXN],ans[MAXN];
    LL A,B,C;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        //scanf("%lld%lld%lld",&A,&B,&C);
        cin>>A>>B>>C;
        bool result=false;
        if(A>=0&&B>=0&&C>=0)
        {
            if(B>C-A)result=true;
        }
        else if((A>=0&&B<=0)||(A<0&&B>0))
        {
            if(A+B>C)result=true;
        }
        else if(A<=0&&B<=0&&C<0)
        {
            if(B>C-A)result=true;
        }
        printf("Case #%d: ",i);
        if(result)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
