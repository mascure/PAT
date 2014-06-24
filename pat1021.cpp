#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define MAXN 10005
#define inf 0x7fffffff
using namespace std;

struct edge
{
    int from,to;
    edge* next;
    edge(){next=NULL;}
}*List[MAXN];
int used[MAXN];
queue<int>myqueue;
int p[MAXN],r[MAXN];
int Find(int x)
{
    if(p[x]!=x)
    {
        p[x]=Find(p[x]);
    }
    return p[x];
}
void Union(int a,int b)
{
    if(r[a]>r[b])
    {
        p[b]=a;
    }
    else if(r[a]==r[b])
    {
        p[b]=a;
        r[a]++;
    }
    else p[a]=b;
}
int BFS(int src,int* dis,int& len)
{
    int remost;
    memset(used,0,sizeof(used));
    while(!myqueue.empty())
    {
        myqueue.pop();
    }
    myqueue.push(src);
    used[src]=1;dis[src]=0;
    len=0;
    while(!myqueue.empty())
    {
        int index=myqueue.front();
        myqueue.pop();
        edge* p=List[index];
        while(p)
        {
            if(!used[p->to])
            {
                used[p->to]=1;
                myqueue.push(p->to);
                dis[p->to]=dis[index]+1;
                if(dis[p->to]>len)
                {len=dis[p->to];remost=p->to;}
            }
            p=p->next;
        }
    }
    return remost;
}
void insert(int from,int to)
{
    if(List[from]==NULL)
    {
        List[from]=new edge;
        List[from]->from=from;
        List[from]->to=to;
    }
    else
    {
        edge *p=List[from];
        while(p->next)
        {
            if(p->to==to)return;    //有重边跳过
            p=p->next;
        }
        p->next=new edge;
        p->next->from=from;
        p->next->to=to;
    }
}
int main()
{
    int i,j,k,n,du[MAXN],dis[MAXN],ans[MAXN];
    while(scanf("%d",&n)!=EOF)
    {
        memset(List,0,sizeof(List));
        memset(du,0,sizeof(du));
        for(i=1;i<=n;i++)
        p[i]=i,dis[i]=0,r[i]=1,ans[i]=0;
        for(i=0;i<n-1;i++)
        {
            int from,to;
            scanf("%d%d",&from,&to);
            insert(from,to);
            insert(to,from);
            du[from]++;du[to]++;
            int pa=Find(from),pb=Find(to);
            if(pa!=pb)Union(pa,pb);
        }
        k=0;    //连通分量的个数
        for(i=1;i<=n;i++)
        if(p[i]==i)k++;
        if(k>1)
        {
            printf("Error: %d components\n",k);
            continue;
        }
        i=1;
        int Max=0;
        for(j=1;j<=n;j++)
        {
            if(du[j]!=1)continue;
            BFS(j,dis,ans[j]); //找离i最远的结点
            if(Max<ans[j])Max=ans[j];
//            for(i=1;i<=n;i++)
//            if(dis[i]>ans[i])ans[i]=dis[i];
//            BFS(end,dis,len);       //从最远结点再算一次距离
//            for(i=1;i<=n;i++)
//            if(dis[i]>ans[i])ans[i]=dis[i];
//            for(i=1;i<=n;i++)
//            if(i==end||ans[i]==len)printf("%d\n",i);
        }
        for(i=1;i<=n;i++)
        if(ans[i]==Max)printf("%d\n",i);
    }
    return 0;
}
