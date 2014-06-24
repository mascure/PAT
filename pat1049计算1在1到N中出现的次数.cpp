//1049. Counting Ones (30)���ۣ�ͳ��ĳ�����ֳ��ֵĴ���
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
void deal(vector<int>& num,vector<int>& ji,int N)
{
    int i=0;
    int J=1;
    while(N!=0)
    {
        num.insert(num.begin(),N%10);
        ji.insert(ji.begin(),J);
        N/=10;
        i++;
        J=J*10;
    }
}
int compute(vector<int>& num,int start,int end)
{
    int ans=0,i;
    for(i=start;i<=end;i++)
    {
        ans=ans*10+num[i];
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,N;
    vector<int>num,ji;
    while(scanf("%d",&N)!=EOF)
    {
        num.clear();
        deal(num,ji,N);
        int ans=0;
        for(i=0;i<num.size();i++)
        {
            //�����λ��1�����ڸ�λ���ִ���ΪN-��λ�Ļ�
            if(num[i]==1)
            {
                ans+=compute(num,0,i-1)*ji[i]+compute(num,i+1,num.size()-1)+1;
            }
            //�����λ����1����
            else if(num[i]>1)
            {
                ans+=(compute(num,0,i-1)+1)*ji[i];
            }
            //��λС��1������0��
            else
            {
                ans+=compute(num,0,i-1)*ji[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
