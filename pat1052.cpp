//1052. Linked List Sorting (25)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stack>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
struct Node
{
    int address,next;
    int key;
}node[MAXN],List[MAXN];
int ListN=0;
int cmp(const void* a,const void* b)
{
    Node aa=*(Node*)a;
    Node bb=*(Node*)b;
    return aa.key-bb.key;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,N,first;
    while(scanf("%d%d",&N,&first)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            int address,key,next;
            scanf("%d%d%d",&address,&key,&next);
            node[address].key=key;
            node[address].next=next;
            node[address].address=address;
        }
        ListN=0;
        i=first;
        while(i!=-1)
        {
            List[ListN++]=node[i];
            i=node[i].next;
        }
        if(N==0||first==-1)
        {
            printf("0 -1\n");
            continue;
        }
        if(ListN==1)
        {
            printf("1 %05d\n",List[0].address);
            printf("%05d %d -1\n",List[0].address,List[0].key);
            continue;
        }
        qsort(List,ListN,sizeof(List[0]),cmp);
        for(i=ListN-2;i>=0;i--)
        {
            List[i].next=List[i+1].address;
        }
        printf("%d %05d\n",ListN,List[0].address);
        for(i=0;i<ListN-1;i++)
            printf("%05d %d %05d\n",List[i].address,List[i].key,List[i].next);
        printf("%05d %d -1\n",List[i].address,List[i].key);
    }
    return 0;
}
