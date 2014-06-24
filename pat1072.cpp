//pat1072 Gas Station
#include<stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
//�ܽڵ���
#define MAXN 1100
#define inf 2000000000
struct Candidate
{
    int min,max;
    double average;
}candidate[15];
int map[MAXN][MAXN],Min[MAXN];
//���нڵ���=N+M��������ѡ��,0��M-1Ϊ��ѡ�㣬M��n-1Ϊhouse
int n;

void dijkstra(int s,int* min)
{
    int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
    {min[i]=inf,v[i]=0;}
	for (min[s]=0,j=0;j<n;j++)
	{
	    //�Ҿ�����С�ĵ㣬���ΪԴ��
		for (k=-1,i=0;i<n;i++)
        {
            if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
        }
        //�ȽϴӾ����õ㵽������ľ����뵱ǰ��С���룬���µ�ǰ��С����
		for (v[k]=1,i=0;i<n;i++)
        {
            if (!v[i]&&min[k]+map[k][i]<min[i])
				min[i]=min[k]+map[k][i];
        }
	}
}
int char2int(char* p,int M)
{
    int ans=0;
    if(p[0]=='G')
    {
        j=1;
        while(p[j]!='\0')
        {
            ans=ans*10+p[j]-'0';
            j++;
        }
        ans--;
    }
    else
    {
        j=0;
        while(p[j]!='\0')
        {
            ans=ans*10+p[j]-'0';
            j++;
        }
        ans=ans+M-1;
    }
    return ans;
}
int main()
{
    int i,j,N,M,K,Ds;
    char p1[10],p2[10];
    while(scanf("%d%d%d%d",&N,&M,&K,&Ds)!=EOF)
    {
        n=N+M;
        int dist,left,right;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            map[i][j]=map[j][i]=inf;
        }
        for(i=0;i<K;i++)
        {
            scanf("%s%s%d",p1,p2,&dist);
            left=right=0;
            left=char2int(p1,M);
            right=char2int(p2,M);
            map[left][right]=map[right][left]=dist;
        }
        //�������ѡ�㵽����house�ľ��룬��¼���ֵ����Сֵ
        int sum=0;
        for(i=0;i<M;i++)
        {
            candidate[i].min=inf;
            candidate[i].max=0;
        }
        for(i=0;i<M;i++)
        {
            dijkstra(i,Min);
            sum=0;
            for(j=M;j<n;j++)
            {
                if(j==M||Min[j]<candidate[i].min)
                candidate[i].min=Min[j];
                if(j==M||Min[j]>candidate[i].max)
                candidate[i].max=Min[j];
                sum+=Min[j];
            }
            candidate[i].average=(sum+0.0)/N;
        }
        //�����ֵС�ڵ���Ds�����������Сֵ����
        int ans=-1;
        for(i=0;i<M;i++)
        {
            if(candidate[i].max<=Ds)
            {
                if(ans==-1||candidate[i].min>candidate[ans].min)
                {
                    ans=i;
                }
                else if(candidate[i].min==candidate[ans].min&&candidate[i].average<candidate[ans].average)
                {
                    ans=i;
                }
            }
        }
        if(ans==-1)
        printf("No Solution\n");
        else
        printf("G%d\n%.1f %.1f\n",ans+1,candidate[ans].min+0.0,candidate[ans].average);
    }

    return 0;
}
