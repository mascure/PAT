//1026. Table Tennis (30) �ȴ�ʱ��(round up)��������ȡ�������������룻���ǵ�һ��ΪVIP����ǰʱ�����̨�д��ڵ�2�����Ժ�λ�õ�VIP��
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
using namespace std;

struct Player
{
    int arrive,serve;
    int playTime,tag;
};
struct Table
{
    int now;
    int tag;
    int count;
};
bool cmp1(Player a,Player b)
{
    return a.arrive<b.arrive;
}
bool cmp2(Player a,Player b)
{
    if(a.serve==b.serve)
    return a.arrive<b.arrive;
    return a.serve<b.serve;
}
vector<Player> player;
vector<Table> table;
void printTime(int s)
{
    int H=s/3600,M=(s%3600)/60,S=s%60;
    printf("%02d:%02d:%02d",H,M,S);
}
int main()
{
    freopen("in.txt","r",stdin);
	int i,j,N,M,K;
	while(scanf("%d",&N)!=EOF)
	{
	    player.resize(N);
	    for(i=0;i<N;i++)
	    {
	        int H,M,S;
	        scanf("%d:%d:%d %d %d",&H,&M,&S,&player[i].playTime,&player[i].tag);
	        //mת��Ϊs
	        player[i].playTime*=60;
	        if(player[i].playTime>2*3600)player[i].playTime=2*3600;
	        player[i].arrive=H*3600+M*60+S;
	        player[i].serve=inf;
	    }
	    scanf("%d%d",&M,&K);
	    table.resize(M);
	    for(i=0;i<M;i++)
	    {
	        table[i].now=8*3600;
	        table[i].tag=0;
	        table[i].count=0;
	    }
	    for(i=0;i<K;i++)
	    {
	        int num;
	        scanf("%d",&num);
	        table[num-1].tag=1;
	    }
	    sort(player.begin(),player.end(),cmp1);
	    //��ǰ�����е���ʼλ��
	    int total=N;
	    while(total--)
	    {
	        int id=-1,time=inf;
	        for(i=0;i<M;i++)
	        {
	            if(time>table[i].now)
	            {
	                time=table[i].now;
                    id=i;
	            }
	        }
	        if(time>=21*3600)break;
	        //����һ���Ƿ���VIP,���ǣ���
	        for(j=0;j<player.size();j++)
	        {
	            if(player[j].serve==inf)break;
	        }
	        if(player[j].tag==1)
	        {
	            for(i=id+1;i<M;i++)
	            {
	                if(table[i].now==table[id].now&&table[i].tag==1)
	                {id=i;break;}
	            }
	        }
	        //������ͨ�������������е�һ��
	        if(table[id].tag==0)
	        {
	            for(j=0;j<player.size();j++)
	            {
	                if(player[j].serve==inf)
	                break;
	            }
	            int tableReady=table[id].now;
	            player[j].serve=tableReady>player[j].arrive?tableReady:player[j].arrive;
	            table[id].now=player[j].serve+player[j].playTime;
	        }
	        //����VIP�����������Ƿ���VIP�����У���������һ��VIP�����ޣ���������е�һ��
	        else if(table[id].tag==1)
	        {
	            bool findVIP=false;
	            for(j=0;j<player.size()&&player[j].arrive<=table[id].now;j++)
	            {
	                if(player[j].serve==inf&&player[j].tag==1)
	                {
	                    findVIP=true;break;
	                }
	            }
	            if(findVIP)
	            {
	                int tableReady=table[id].now;
                    player[j].serve=tableReady>player[j].arrive?tableReady:player[j].arrive;
                    table[id].now=player[j].serve+player[j].playTime;
	            }
	            else
	            {
	                for(j=0;j<player.size();j++)
                    {
                        if(player[j].serve==inf)
                        break;
                    }
                    int tableReady=table[id].now;
                    player[j].serve=tableReady>player[j].arrive?tableReady:player[j].arrive;
                    table[id].now=player[j].serve+player[j].playTime;
	            }
	        }
	        if(player[j].serve<3600*21)
	        table[id].count++;
	    }
	    sort(player.begin(),player.end(),cmp2);
	    for(i=0;i<player.size();i++)
	    {
	        if(player[i].serve>=21*3600)
	        break;
	        printTime(player[i].arrive);
	        printf(" ");
	        printTime(player[i].serve);
	        float min=(player[i].serve-player[i].arrive)/60.0;
	        int m=min>(int)min?(int)min+1:(int)min;
	        m=(player[i].serve-player[i].arrive+30)/60;
	        printf(" %d\n",m);
	    }
	    for(i=0;i<M-1;i++)
        {
            printf("%d ",table[i].count);
        }
        printf("%d\n",table[M-1].count);
	}
	return 0;
}
