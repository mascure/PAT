//1038. Recover the Smallest Number (30)
//找第一个非0数
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
#define MAXN 10005
using namespace std;

int cmp(const void *a,const void *b)
{
    string aa=*(string*)a;
    string bb=*(string*)b;
    string str1=aa.append(bb),str2=bb.append(aa);
    int i,len=aa.length()+bb.length();
    for(i=0;i<len;i++)
    {
        if(str1[i]<str2[i])return -1;
        else if(str1[i]>str2[i])return 1;
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,N;
    string seg[MAXN];
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            char num[10];
            scanf("%s",num);
            seg[i]=num;
        }
        qsort(seg,N,sizeof(seg[0]),cmp);
        i=0;
        while(i<N)
        {
            if(atoi(seg[i].c_str())!=0)break;
            i++;
        }
        printf("%d",atoi(seg[i].c_str()));
        for(i=i+1;i<N;i++)
        cout<<seg[i];
        cout<<endl;
    }
    return 0;
}
