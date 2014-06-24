//http://pat.zju.edu.cn/contests/pat-a-practise/1056
/*
优先队列实现，17分，三个case超时
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
using namespace std;
void popLeft(priority_queue<int,vector<int>,less<int> >& L,int item)
{
    stack<int> tmp;
    while(L.top()!=item)
    {
        tmp.push(L.top());
        L.pop();
    }
    //弹出
    L.pop();
    //将其余元素在压入L
    while(!tmp.empty())
    {
        L.push(tmp.top());
        tmp.pop();
    }
}
void popRight(priority_queue<int,vector<int>,greater<int> >& R,int item)
{
    stack<int> tmp;
    while(R.top()!=item)
    {
        tmp.push(R.top());
        R.pop();
    }
    R.pop();
    while(!tmp.empty())
    {
        R.push(tmp.top());
        tmp.pop();
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,N;
    while(scanf("%d",&N)!=EOF)
    {
        stack<int> v;
        //大顶堆
        priority_queue<int,vector<int>,less<int> > L;
        //小顶堆
        priority_queue<int,vector<int>,greater<int> > R;
        char cmd[15];
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
                    if(L.size()==R.size()+1)
                    {
                        //在左侧，直接从L弹出
                        if(top<=L.top())
                        {
                            popLeft(L,top);
                        }
                        //在右侧，从R弹出，再从L加入R一个
                        else
                        {
                            popRight(R,top);
                            R.push(L.top());
                            L.pop();
                        }
                    }
                    else if(L.size()==R.size())
                    {
                        //在左侧，弹出，从R加入L一个
                        if(top<=L.top())
                        {
                            popLeft(L,top);
                            L.push(R.top());
                            R.pop();
                        }
                        //在右侧，从R弹出
                        else
                            popRight(R,top);
                    }
                    v.pop();
                }
            }
            else if(strcmp(cmd,"PeekMedian")==0)
            {
                if(v.size()==0)
                    printf("Invalid\n");
                else
                {
                    printf("%d\n",L.top());
                }
            }
            else if(strcmp(cmd,"Push")==0)
            {
                int data;
                scanf("%d",&data);
                v.push(data);
                if(L.size()==R.size()+1)
                {
                    //在左侧，从L加入R一个，再压入左侧
                    if(data<L.top())
                    {
                        R.push(L.top());
                        L.pop();
                        L.push(data);
                    }
                    //在右侧，直接加入右侧
                    else
                    {
                        R.push(data);
                    }
                }
                else if(L.size()==R.size())
                {
                    //在左侧，直接压入
                    if(L.size()==0||data<=R.top())
                        L.push(data);
                    //在右侧，从R加入L一个，再压入R
                    else
                    {
                        L.push(R.top());
                        R.pop();
                        R.push(data);
                    }
                }
            }
        }
    }
    return 0;
}
