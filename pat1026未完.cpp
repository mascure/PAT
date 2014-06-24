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
    int now,length;
    int tag;
};
bool cmp1(Player a,Player b)
{
    return a.arrive<b.arrive;
}
vector<Player> player;
vector<Table> table;
int time2S(string time)
{
    return (time[0]*10+time[1])*3600+(time[3]*10+time[4])*60+time[6]*10+time[7];
}
void printTime(int s)
{
    int H=s/3600,M=(s%3600)/60,S=s%60;
    printf("%02d:%02d:%02d",H,M,S);
}
int main()
{
	int i,N,M,K;
	while(scanf("%d",&N)!=EOF)
	{
	    player.resize(N);
	    for(i=0;i<N;i++)
	    {
	        int H,M,S;
	        scanf("%d:%d:%d %d %d",&H,&M,&S,&player[i].playTime,&player[i].tag);
	        player[i].arrive=H*3600+M*60+S;
	        player[i].serve=inf;
	    }
	    scanf("%d%d",&M,&K);
	    table.resize(M);
	    for(i=0;i<M;i++)
	    {
	        table[i].now=8*3600;
	        table[i].length=0;
	        table[i].tag=0;
	    }
	    for(i=0;i<K;i++)
	    {
	        int num;
	        scanf("%d",&num);
	        table[num-1].tag=1;
	    }
	    sort(player,player+N,cmp1);
	    //当前队列中的起始位置
	    int pStartPos=0;
	    while(N--)
	    {
	        int id=-1,time=inf;
	        for(i=0;i<M;i++)
	        {
	            if(time>table[i].now+length)
	            {
	                time=table[i].now+length;
	                id=i;
	            }
	        }

	    }
	}
	return 0;
}
