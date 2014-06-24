//http://pat.zju.edu.cn/contests/pat-a-practise/1068
/*
对一个数列，找一个最小的子集，使得它们的和为M
若只判断能不能找到，动态规划应该是更好的办法=^=
先剪掉本身已经大于M的数，快排之后递归，这样找到的肯定是最小的。
但考虑这样一种情况，数列为2...2,3，...,M=99
当2很多（10000）时，开始的递归将一直在2里面找，很耗时。解决的办法为下一次开始的数从不等于前一个数开始，因为以前一个数开始已经确定找不到。
最后一个case应该就是这种情况。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXN 105
using namespace std;
vector<int> c;
int N,M;
bool cmp(int a,int b)
{
    return a<b;
}
bool find(int x,vector<int>& res,int sum)
{
    res.push_back(c[x]);
    vector<int>tmp(res);
    sum+=c[x];
    if(sum==M)
    return true;
    else if(sum>M)
    return false;
    else
    {
        for(int i=x+1;i<N;i++)
        {
            if(sum+c[i]>M)break;
            if(find(i,res,sum))
            return true;
            else
            {
                res=tmp;
                while(i+1<N&&c[i]==c[i+1])
                i++;
            }
        }
        return false;
    }
}
int main() {
    freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        c.clear();
        int data;
        for(i=0;i<N;i++)
        {
            scanf("%d",&data);
            if(data<=M)
            c.push_back(data);
        }
        sort(c.begin(),c.end(),cmp);
        N=c.size();
        for(i=0;i<N;i++)
        {
            if(c[i]>M)break;
            vector<int>res;
            if(find(i,res,0))
            {
                printf("%d",res[0]);
                for(j=1;j<res.size();j++)
                printf(" %d",res[j]);
                printf("\n");
                break;
            }
            else
            {
                while(i+1<N&&c[i]==c[i+1])
                i++;
            }
        }
        if(i==N||c[i]>M)
        printf("No Solution\n");
    }
    return 0;
}
