//1033. Sharing (25),找好的输入输出方法
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
using namespace std;

struct Node
{
    float dis,price;
};
struct Gas
{
    float price,num;
};
bool cmpDis(Node a,Node b)
{
    return a.dis<b.dis;
}
int main()
{
    freopen("in.txt","r",stdin);
    int capacity,D,Davg,N;
    int i,j;
    while(scanf("%d%d%d%d",&capacity,&D,&Davg,&N)!=EOF)
    {
        vector<Node> nodes;
        for(i=0;i<N;i++)
        {
            float price,dis;
            Node add;
            scanf("%f&f",&add.dis,&add.price);
            nodes.push_back(add);
        }
        sort(nodes.begin(),nodes.end(),cmpDis);
        if(nodes[0].dis>0)
        {
            printf("The maximum travel distance = 0.00\n");
            continue;
        }
        vector<Gas> tank;
        Gas start;
        start.price=nodes[0].price;
        start.num=capacity;
        tank.push_back(start);
        float cost=0.0,last_pos=0.0;
        //计算从上一个节点到这个节点的最小花费，并更新到当前节点的总花费。将这个节点的气加入tank，使得tank中总费用最少
        for(i=1;i<N;i++)
        {
            float sum=0.0,nowCost=0.0,gasNeed=(nodes[i].dis-last_pos)/Davg;
            while(sum<gasNeed&&tank.size()>0)
            {
                float realAdd=tank[0].num<(gasNeed-sum)?tank[0].num:(gasNeed-sum);
                nowCost+=realAdd*tank[0].price;
                sum+=realAdd;
                if(realAdd==tank[0].num)
                tank.erase(tank.begin());
            }
            //如果到不了这个节点
            if(tank.size()==0&&sum<gasNeed)
        }
    }
	return 0;
}
