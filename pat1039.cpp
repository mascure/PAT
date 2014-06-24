#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#define MAXN 40005
using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}
vector<int> S[26*26*26*10];
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,N,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        for(i=0;i<K;i++)
        {
            int id,num;
            scanf("%d%d",&id,&num);
            char name[5];
            for(j=0;j<num;j++)
            {
                scanf("%s",name);
                int sid=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
                S[sid].push_back(id);
            }
        }
        for(i=0;i<N;i++)
        {
            char name[5];
            scanf("%s",name);
            int sid=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
            sort(S[sid].begin(),S[sid].end(),cmp);
            printf("%s %d",name,S[sid].size());
            for(j=0;j<S[sid].size();j++)
            {
                printf(" %d",S[sid][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
