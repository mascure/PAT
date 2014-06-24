//1034. Head of a Gang (30)并查集
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
#define MAXN 2005
using namespace std;
struct People
{
    int p;//父节点
    int r;//层数
    int num;//包含的节点数
    int weight;//节点权重
    int tree_weight;//树权重
    string name;
}p[MAXN];
struct Result
{
    int root;
    int max;
    int max_i;
    string name;
}result[MAXN];
int result_num=0;
int N,K;
//根节点，层数，树中节点数
void init()
{
    for(int i=0;i<MAXN;i++)
    {
        p[i].p=i;
        p[i].r=1;
        p[i].num=1;
        p[i].weight=0;
        p[i].tree_weight=0;
        result[i].root=-1;
        result[i].max=0;
        result[i].max_i=0;
    }
}
int Find(int x)
{
    if(p[x].p!=x)
    {
        p[x].p=Find(p[x].p);
    }
    return p[x].p;
}
//1:以x为根，0：以y为根
int id=1;
map<string,int> name;
bool Merge(int x,int y)
{
    if(p[x].r<p[y].r)
    {
        p[x].p=y;
        p[y].num+=p[x].num;
        p[y].tree_weight+=p[x].tree_weight;
        return 0;
    }
    else if(p[x].r==p[y].r)
    {
        p[x].p=y;
        p[y].num+=p[x].num;
        p[y].tree_weight+=p[x].tree_weight;
        p[y].r++;
        return 0;
    }
    else
    {
        p[y].p=x;
        p[x].num+=p[y].num;
        p[x].tree_weight+=p[y].tree_weight;
        return 1;
    }
}
int dealS(char* n,int relation)
{
    string s=n;
    int pN=name[s];
    //第一次出现的名字
    if(pN==0)
    {
        pN=id;
        name[s]=id;
        p[id].name=s;
        id++;
    }
    p[pN].weight+=relation;
    int root=Find(pN);
    p[root].tree_weight+=relation;
    return pN;
}
void updateResult(int id)
{
    int i,root=Find(id);
    if(p[root].tree_weight<=K*2||p[root].num<=2)return;
    for(i=0;i<result_num;i++)
    {
        if(result[i].root==root)
        {
            if(p[id].weight>result[i].max)
            {
                result[i].max=p[id].weight;
                result[i].max_i=id;
                result[i].name=p[id].name;
            }
            break;
        }
    }
    if(i==result_num)
    {
        result[i].root=root;
        result[i].max=p[id].weight;
        result[i].max_i=id;
        result[i].name=p[id].name;
        result_num++;
    }
}
int cmp(const void* a,const void *b)
{
    Result aa=*((Result*)a);
    Result bb=*((Result*)b);
    return aa.name.compare(bb.name);
}
int main()
{
    freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        init();
        name.clear();
        result_num=0;
        char left[5],right[5];
        string L,R;
        int relation;
        id=1;
        for(i=0;i<N;i++)
        {
            scanf("%s%s%d",left,right,&relation);
            int idL=dealS(left,relation);
            int idR=dealS(right,relation);
            int pL=p[idL].p,pR=p[idR].p;
            if(pL!=pR)Merge(pL,pR);
        }
        for(i=1;i<id;i++)
        {
            updateResult(i);
        }
        printf("%d\n",result_num);
        qsort(result,result_num,sizeof(result[0]),cmp);
        for(i=0;i<result_num;i++)
        {
            cout<<p[result[i].max_i].name<<" "<<p[result[i].root].num<<endl;
        }
    }
    return 0;
}
