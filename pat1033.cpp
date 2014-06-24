//1033. To Fill or Not to Fill (25) ̰�ģ�ÿ��һ���ڵ������ö�ʹ������˵����ͣ����������б�
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
    int i;
    while(scanf("%d%d%d%d",&capacity,&D,&Davg,&N)!=EOF)
    {
        vector<Node> nodes;
        for(i=0;i<N;i++)
        {
            Node add;
            scanf("%f%f",&add.price,&add.dis);
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
        float cost=0.0;
        float far_most=capacity*Davg;
        bool reach=true;
        //�������һ���ڵ㵽����ڵ����С���ѣ������µ���ǰ�ڵ���ܻ��ѡ�������ڵ��������tank��ʹ��tank���ܷ�������
        for(i=1;i<N;i++)
        {
            //�������������ڵ�
            if(far_most<nodes[i].dis-nodes[i-1].dis)
            {
                printf("The maximum travel distance = %.2f\n",nodes[i-1].dis+far_most);
                reach=false;
                break;
            }
            float sum=0.0,nowCost=0.0,gasNeed=(nodes[i].dis-nodes[i-1].dis)/Davg;
            while(sum<gasNeed&&tank.size()>0)
            {
                float realAdd=tank[0].num<(gasNeed-sum)?tank[0].num:(gasNeed-sum);
                nowCost+=realAdd*tank[0].price;
                tank[0].num-=realAdd;
                sum+=realAdd;
                if(tank[0].num==0)
                tank.erase(tank.begin());
            }
            cost+=nowCost;
            //������ڵ��������tank
            float add=gasNeed;
            while(tank.size()>0)
            {
                if(nodes[i].price<=tank[tank.size()-1].price)
                {
                    add+=tank[tank.size()-1].num;
                    tank.erase(tank.end()-1);
                }
                else break;
            }
            Gas last;
            last.num=add;
            last.price=nodes[i].price;
            tank.push_back(last);
        }
        if(reach)
        {
            if(far_most<D-nodes[i-1].dis)
            {
                printf("The maximum travel distance = %.2f\n",nodes[i-1].dis+far_most);
            }
            else
            {
                float sum=0.0,nowCost=0.0,gasNeed=(D-nodes[i-1].dis)/Davg;
                while(sum<gasNeed&&tank.size()>0)
                {
                    float realAdd=tank[0].num<(gasNeed-sum)?tank[0].num:(gasNeed-sum);
                    nowCost+=realAdd*tank[0].price;
                    tank[0].num-=realAdd;
                    sum+=realAdd;
                    if(tank[0].num==0)
                    tank.erase(tank.begin());
                }
                cost+=nowCost;
                printf("%.2f\n",cost);
            }
        }
    }
	return 0;
}
