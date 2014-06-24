//http://pat.zju.edu.cn/contests/pat-a-practise/1056
/*
一个数组，分为若干组，每组PK出最大值，进入下一轮，失败的排名相同；继续分组PK，直到只剩下一个，给出所有元素的排名
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 0x7fffffff
#define MAXN 1005
using namespace std;
struct Mouse
{
    int weight,rank;
}m[MAXN];
int N,G;
void win(int* list,int& listN,int& lastR,int& newR)
{
    int i,resN=(listN+G-1)/G,np=listN-resN;
    int res[MAXN];
    newR=lastR-np;
    int j=0,t=0,k=0;
    for(i=0;i<listN;i+=G)
    {
        t=i;;
        int p=1;
        while(p!=G&&i+p<listN)
        {
            if(m[list[i+p]].weight>m[list[t]].weight)
            {
                t=i+p;
            }
            p++;
        }
        res[j++]=list[t];
        for(k=0;k<G&&k+i<listN;k++)
        {
            if(k+i!=t)
            {
                m[list[k+i]].rank=newR;
            }
        }
    }
    listN=j;
    for(i=0;i<j;i++)
    {
        list[i]=res[i];
    }
    lastR=newR;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d%d",&N,&G)!=EOF)
    {
        for(i=0;i<N;i++)
            scanf("%d",&m[i].weight);
        int List[MAXN],listN=N;
        for(i=0;i<N;i++)
            scanf("%d",&List[i]);
        int lastR=1001,newR=lastR;
        while(listN!=1)
        {
            win(List,listN,lastR,newR);
        }
        newR=lastR-1;
        m[List[0]].rank=newR;
        for(i=0;i<N;i++)
            m[i].rank=m[i].rank-(newR-1);
        printf("%d",m[0].rank);
        for(i=1;i<N;i++)
            printf(" %d",m[i].rank);
        printf("\n");
    }
    return 0;
}
