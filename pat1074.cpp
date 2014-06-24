//http://pat.zju.edu.cn/contests/pat-a-practise/1074
/*
链表N，以K个为单位反转，最后剩余的不反转
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
//#include<map>
#define inf 0x7fffffff
#define LL long long
#define MAX_E 1000000
#define MAX_V 500
#define MAXN 100005
using namespace std;
struct Node
{
    int address,key,next;
}e[MAXN];
int N,K;
vector<Node> R,ans;
int main()
{
	freopen("in.txt","r",stdin);
	int i,j,first;
	while(scanf("%d%d%d",&first,&N,&K)!=EOF)
	{
	    for(i=0;i<N;i++)
	    {
	        int id,key,next;
	        scanf("%d%d%d",&id,&key,&next);
	        e[id].address=id;
	        e[id].key=key;
	        e[id].next=next;
	    }
	    int start=first;
	    R.clear();
	    ans.clear();
	    while(start!=-1)
	    {
	        R.push_back(e[start]);
	        start=e[start].next;
	    }
	    int n=R.size(),size=0;
	    for(i=0;i<n/K;i++)
	    {
	        for(j=K-1;j>=0;j--)
	        {
	            ans.push_back(R[i*K+j]);
	            size=ans.size();
	            if(size>1)
	            ans[size-2].next=ans[size-1].address;
	        }
	    }
	    for(i=(n/K)*K;i<n;i++)
	    {
	        ans.push_back(R[i]);
	        size=ans.size();
            if(size>1)
            ans[size-2].next=ans[size-1].address;
	    }
	    size=ans.size();
	    ans[size-1].next=-1;
	    for(i=0;i<size;i++)
	    {
	        printf("%05d %d ",ans[i].address,ans[i].key);
	        if(ans[i].next!=-1)
	        printf("%05d\n",ans[i].next);
	        else
	        printf("-1\n");
	    }
	}
	return 0;
}
