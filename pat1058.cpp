//http://pat.zju.edu.cn/contests/pat-a-practise/1058
/*
�����ִļӷ���ģ��ӷ����㣬��Ҫע���1λ����ȡģ
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
#define MAXN 100005
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int G1,S1,K1,G2,S2,K2;
    while(scanf("%d.%d.%d",&G1,&S1,&K1)!=EOF)
    {
        scanf("%d.%d.%d",&G2,&S2,&K2);
        int ans1=0,ans2=0,ans3=0;
        int c1=0,c2=0;
        ans3=(K1+K2)%29;
        c2=(K1+K2)/29;
        ans2=(c2+S1+S2)%17;
        c1=(c2+S1+S2)/17;
        ans1=c1+G1+G2;
        printf("%d.%d.%d\n",ans1,ans2,ans3);
    }
    return 0;
}
