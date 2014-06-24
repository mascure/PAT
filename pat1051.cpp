//1051. Pop Sequence (25)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stack>
#define inf 0x7fffffff
#define MAXN 40005
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int i,M,N,K,seq[MAXN];
    while(scanf("%d%d%d",&M,&N,&K)!=EOF)
    {
        while(K--)
        {
            for(i=0;i<N;i++)
                scanf("%d",&seq[i]);
            stack<int> s;
            //当前队列即将入栈的指针
            int p=1;
            bool yes=true;
            for(i=0;i<N&&p<=N+1;i++)
            {
                if(seq[i]<p)
                {
                    if(s.size()==0)
                    {
                        yes=false;
                        break;
                    }
                    else if(s.top()!=seq[i])
                    {
                        yes=false;
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
                else if(seq[i]==p)
                {
                    if(s.size()<M)
                    p++;
                    else
                    {
                        yes=false;
                        break;
                    }
                }
                else
                {
                    while(p!=seq[i])
                    {
                        s.push(p++);
                        if(s.size()>=M)
                        {
                            yes=false;
                            break;
                        }
                    }
                    if(!yes)
                    {
                        break;
                    }
                    p++;
                }
            }
            if(yes)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
