//pat1014. Waiting in Line (30)
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits>
using namespace std;
int window[20][10],currentTime[20];
int processTime[1001],finishTime[1001];
int query[1001];
int computeTime(int start,int length)
{
    //已结束或不可达
    if(start>=540||start==-1)return -1;
    //if(start+length>540) return 540;
    else return start+length;
}
void init(int N,int M,int K)
{
    int i,j;
    for(i=0;i<N;i++)
    currentTime[i]=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i*N+j<K)
            {
                window[j][i]=i*N+j;
                if(i==0)finishTime[j]=computeTime(0,processTime[j]);
                else finishTime[i*N+j]=computeTime(finishTime[window[j][i-1]],processTime[i*N+j]);
            }
            else break;
        }
    }
}
void process(int customer,int N,int M)
{
    int i,least=540,leastId=-1;
    for(i=0;i<N;i++)
    {
        if(currentTime[i]+processTime[window[i][0]]<least)
        {
            leastId=i;
            least=currentTime[i]+processTime[window[i][0]];
        }
    }
    //若所有窗口都已排到下班，则直接处理为sorry
    if(leastId==-1)
    {
        finishTime[customer]=-1;
        return;
    }
    //可以进入黄色区，customer进入leastId
    finishTime[customer]=computeTime(finishTime[window[leastId][M-1]],processTime[customer]);
    currentTime[leastId]=currentTime[leastId]+processTime[window[leastId][0]];
    for(i=0;i<M-1;i++)
    window[leastId][i]=window[leastId][i+1];
    window[leastId][M-1]=customer;
}
int main()
{
    int i,N,M,K,Q;
    while(scanf("%d%d%d%d",&N,&M,&K,&Q)!=EOF)
    {
        for(i=0;i<K;i++)
        scanf("%d",&processTime[i]);
        for(i=0;i<Q;i++)
        scanf("%d",&query[i]);
        //初始化黄色区
        init(N,M,K);
        for(i=N*M;i<K;i++)
        {
            process(i,N,M);
        }
        for(i=0;i<Q;i++)
        {
            int time=finishTime[query[i]-1];
            if(time==-1)
            printf("Sorry\n");
            else
            {
                int HH=time/60+8,MM=time%60;
                printf("%02d:%02d\n",HH,MM);
            }
        }
    }
    return 0;
}
