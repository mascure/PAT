//http://pat.zju.edu.cn/contests/pat-a-practise/1062
/*
排序题，按照类别写出排序函数
*/
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
#define MAXN 40005
using namespace std;

struct Person
{
    int id,virtue,talent;
};
int L,H;
bool isSage(Person a)
{
    if(a.talent>=H&&a.virtue>=H)return true;
    else return false;
}
bool isNoblemen(Person a)
{
    if(a.talent<H&&a.virtue>=H)return true;
    else return false;
}
bool isFoolmen(Person a)
{
    if(a.talent<H&&a.virtue<H&&a.talent<=a.virtue)return true;
    else return false;
}
bool cmp(Person a,Person b)
{
    //同一级别
    if(isSage(a)&&isSage(b))
    {
        if(a.talent+a.virtue!=b.talent+b.virtue)
        return a.talent+a.virtue>b.talent+b.virtue;
        else if(a.virtue!=b.virtue)
        return a.virtue>b.virtue;
        else
        return a.id<b.id;
    }
    //高一级以上
    else if(isSage(a)&&!isSage(b))
    {
        return true;
    }
    //底一级以上
    else if(!isSage(a)&&isSage(b))
    {
        return false;
    }
    else if(isNoblemen(a)&&isNoblemen(b))
    {
        if(a.talent+a.virtue!=b.talent+b.virtue)
        return a.talent+a.virtue>b.talent+b.virtue;
        else if(a.virtue!=b.virtue)
        return a.virtue>b.virtue;
        else
        return a.id<b.id;
    }
    else if(isNoblemen(a)&&!isNoblemen(b))
    {
        return true;
    }
    else if(!isNoblemen(a)&&isNoblemen(b))
    return false;
    else if(isFoolmen(a)&&isFoolmen(b))
    {
        if(a.talent+a.virtue!=b.talent+b.virtue)
        return a.talent+a.virtue>b.talent+b.virtue;
        else if(a.virtue!=b.virtue)
        return a.virtue>b.virtue;
        else
        return a.id<b.id;
    }
    else if(isFoolmen(a)&&!isFoolmen(b))
    return true;
    else if(!isFoolmen(a)&&isFoolmen(b))
    return false;
    else
    {
        if(a.talent+a.virtue!=b.talent+b.virtue)
        return a.talent+a.virtue>b.talent+b.virtue;
        else if(a.virtue!=b.virtue)
        return a.virtue>b.virtue;
        else
        return a.id<b.id;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int i,N;
    while(scanf("%d%d%d",&N,&L,&H)!=EOF)
    {
        vector<Person> p;
        for(i=0;i<N;i++)
        {
            int id,virtue,talent;
            scanf("%d%d%d",&id,&virtue,&talent);
            if(virtue>=L&&talent>=L)
            {
                Person pp;
                pp.id=id;
                pp.virtue=virtue;
                pp.talent=talent;
                p.push_back(pp);
            }
        }
        sort(p.begin(),p.end(),cmp);
        printf("%d\n",p.size());
        for(i=0;i<p.size();i++)
        {
            printf("%08d %d %d\n",p[i].id,p[i].virtue,p[i].talent);
        }
    }
    return 0;
}
