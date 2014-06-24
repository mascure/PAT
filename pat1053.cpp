//1053. Path of Equal Weight (30)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#define inf 0x7fffffff
#define MAXN 105
using namespace std;
struct Node
{
    int id,weight;
    Node *leftChild,*right,*parent;
}node[MAXN];
struct TMP
{
    int id;
    int total_weight;
};
void push_weight(vector<int>& res,int id)
{
    if(node[id].parent!=NULL)
        push_weight(res,node[id].parent->id);
    res.push_back(node[id].weight);
}
int cmp(const void* a,const void* b)
{
    vector<int> aa=*(vector<int>*)a;
    vector<int> bb=*(vector<int>*)b;
    for(int i=0;i<aa.size()&&i<bb.size();i++)
    {
        if(aa[i]!=bb[i])
            return bb[i]-aa[i];
    }
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,N,M,S;
    while(scanf("%d%d%d",&N,&M,&S)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&node[i].weight);
            node[i].id=i;
            node[i].leftChild=NULL;
            node[i].right=NULL;
            node[i].parent=NULL;
        }
        for(i=0;i<M;i++)
        {
            int id,num,cId;
            scanf("%d%d",&id,&num);
            scanf("%d",&cId);
            node[id].leftChild=&node[cId];
            node[cId].parent=&node[id];
            int lastC=cId;
            for(j=1;j<num;j++)
            {
                scanf("%d",&cId);
                node[lastC].right=&node[cId];
                node[cId].parent=&node[id];
                lastC=cId;
            }
        }
        vector<int> result[MAXN];
        int resultNum=0;
        queue<TMP> q;
        TMP root;
        root.id=0;
        root.total_weight=node[0].weight;
        //根节点入队
        q.push(root);
        while(!q.empty())
        {
            TMP& front=q.front();
            Node* p=node[front.id].leftChild;
            //叶节点,检查是否
            if(p==NULL)
            {
                //路径权重等于指定权重
                if(front.total_weight==S)
                {
                    push_weight(result[resultNum],front.id);
                    resultNum++;
                }
            }
            //非页节点
            else
            {
                while(p!=NULL)
                {
                    TMP a;
                    a.id=p->id;
                    a.total_weight=front.total_weight+p->weight;
                    q.push(a);
                    p=p->right;
                }
            }
            q.pop();
        }
        qsort(result,resultNum,sizeof(result[0]),cmp);
        for(i=0;i<resultNum;i++)
        {
            printf("%d",result[i][0]);
            for(j=1;j<result[i].size();j++)
                printf(" %d",result[i][j]);
            printf("\n");
        }
    }
    return 0;
}
