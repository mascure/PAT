//http://pat.zju.edu.cn/contests/pat-a-practise/1059
/*
��N���������������ݴΣ�����2���ݴΣ���3��ʼ����������Ƿ������ӣ����������ݴΣ����Ա�ֻ֤Ҫ�����ӣ����Ϊ�����ӣ�
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
long compute(long& n,long i)
{
    long ans=0;
    while(n%i==0)
    {
        n/=i;
        ans++;
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    long i,N;
    while(scanf("%ld",&N)!=EOF)
    {
        long tmp=N;
        vector<long> fac,cnt;
        if(N==1)
        {
            printf("1=1\n");
            continue;
        }
        if(N%2==0)
        {
            fac.push_back(2);
            cnt.push_back(compute(N,2));
        }
        for(i=3;i<=N;i+=2)
        {
            if(N%i==0)
            {
                fac.push_back(i);
                cnt.push_back(compute(N,i));
            }
        }
        printf("%ld=%ld",tmp,fac[0]);
        if(cnt[0]!=1)
        {
            printf("^%ld",cnt[0]);
        }
        for(i=1;i<fac.size();i++)
        {
            printf("*%ld",fac[i]);
            if(cnt[i]!=1)
                printf("^%ld",cnt[i]);
        }
        printf("\n");
    }
    return 0;
}
