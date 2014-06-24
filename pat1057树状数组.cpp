//http://pat.zju.edu.cn/contests/pat-a-practise/1057
/*
使用stl中的stack模拟栈操作，但取中位数的操作会超时。
对1到100000建立hash表，记录该数字出现的次数，对hash表建立树状数组，二分查找中间值
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<vector>
//#include<queue>
#include<stack>
//#include<algorithm>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
int in[MAXN],n=MAXN;
//求2^k
int lowbit(int t)
{
    return t&(t^(t-1));
}
//求前n项和
int sum(int end)
{
    int sum=0;
    while(end>0)
    {
        sum+=in[end];
        end-=lowbit(end);
    }
    return sum;
}
//增加某个元素的大小
void Plus(int pos,int num)
{
    while(pos<=n)
    {
        in[pos]+=num;
        pos+=lowbit(pos);
    }
}
int findMid(int size)
{
    int mid_pos=(size+1)/2;
    int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(sum(mid)<mid_pos)
        {
            low=mid+1;
        }
        else if(sum(mid)==mid_pos)
            high=mid-1;
        else
        {
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,N;
    while(scanf("%d",&N)!=EOF)
    {
        stack<int> v;
        char cmd[15];
        memset(in,0,sizeof(in));
        for(i=0;i<N;i++)
        {
            scanf("%s",cmd);
            if(strcmp(cmd,"Pop")==0)
            {
                if(v.size()==0)
                    printf("Invalid\n");
                else
                {
                    int top=v.top();
                    printf("%d\n",top);
                    v.pop();
                    Plus(top,-1);
                }
            }
            else if(strcmp(cmd,"PeekMedian")==0)
            {
                if(v.size()==0)
                    printf("Invalid\n");
                else
                {
                    printf("%d\n",findMid(v.size()));
                }
            }
            else if(strcmp(cmd,"Push")==0)
            {
                int data;
                scanf("%d",&data);
                v.push(data);
                Plus(data,1);
            }
        }
    }
    return 0;
}
