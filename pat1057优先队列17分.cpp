//http://pat.zju.edu.cn/contests/pat-a-practise/1056
/*
���ȶ���ʵ�֣�17�֣�����case��ʱ
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
    //����
    L.pop();
    //������Ԫ����ѹ��L
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
        //�󶥶�
        priority_queue<int,vector<int>,less<int> > L;
        //С����
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
                        //����ֱ࣬�Ӵ�L����
                        if(top<=L.top())
                        {
                            popLeft(L,top);
                        }
                        //���Ҳ࣬��R�������ٴ�L����Rһ��
                        else
                        {
                            popRight(R,top);
                            R.push(L.top());
                            L.pop();
                        }
                    }
                    else if(L.size()==R.size())
                    {
                        //����࣬��������R����Lһ��
                        if(top<=L.top())
                        {
                            popLeft(L,top);
                            L.push(R.top());
                            R.pop();
                        }
                        //���Ҳ࣬��R����
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
                    //����࣬��L����Rһ������ѹ�����
                    if(data<L.top())
                    {
                        R.push(L.top());
                        L.pop();
                        L.push(data);
                    }
                    //���Ҳֱ࣬�Ӽ����Ҳ�
                    else
                    {
                        R.push(data);
                    }
                }
                else if(L.size()==R.size())
                {
                    //����ֱ࣬��ѹ��
                    if(L.size()==0||data<=R.top())
                        L.push(data);
                    //���Ҳ࣬��R����Lһ������ѹ��R
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
