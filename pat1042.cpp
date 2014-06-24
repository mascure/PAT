#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#define MAXN 10005
using namespace std;
int cnt[MAXN],num[100005];
void print(int i)
{
    int first=(i-1)/13;
    if(first==0)
        printf("S");
    else if(first==1)
        printf("H");
    else if(first==2)
        printf("C");
    else if(first==3)
        printf("D");
    else
        printf("J");
    printf("%d",(i-1)%13+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,N,old_card[54],new_card[54],shuffling[54];
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<54;i++)
            old_card[i]=i+1;
        for(i=0;i<54;i++)
        {
            scanf("%d",&shuffling[i]);
            shuffling[i]--;
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<54;j++)
            {
                new_card[shuffling[j]]=old_card[j];
            }
            for(j=0;j<54;j++)
            {
                old_card[j]=new_card[j];
            }
        }
        print(old_card[0]);
        for(i=1;i<54;i++)
        {
            printf(" ");
            print(old_card[i]);
        }
        printf("\n");
    }
    return 0;
}
