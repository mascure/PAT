//http://pat.zju.edu.cn/contests/pat-a-practise/1064
/*
将一个数列排序后形成一个满二叉树
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
#define MAXN 1005
using namespace std;

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int N;
int key[MAXN],result[MAXN];
void put(int start,int end,int pos)
{
    int n=end-start+1;
    int level=1,sum=2;
    while(sum-1<n)
    {
        level++;
        sum=sum<<1;
    }
    int last_total=sum/2,sum1=sum/2-1;
    //计算最后一行的个数
    int add=n-sum1;
    if(last_total>=2&&add>last_total/2)
    add=last_total/2;
    int target=start+sum/4-1+add;
    result[pos]=key[target];
    if(pos*2+1<N)
    put(start,target-1,pos*2+1);
    if(pos*2+2<N)
    put(target+1,end,pos*2+2);
}
int main()
{
    freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&key[i]);
        }
        qsort(key,N,sizeof(key[0]),cmp);
        //计算第一个元素的位置
        put(0,N-1,0);
        printf("%d",result[0]);
        for(i=1;i<N;i++)
        printf(" %d",result[i]);
        printf("\n");
    }
    return 0;
}
