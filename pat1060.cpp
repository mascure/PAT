//http://pat.zju.edu.cn/contests/pat-a-practise/1060
/*
将浮点数转换为标准形式，并保留指定数目的有效数字
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 105
using namespace std;
void deal(char* s,vector<int>& dig,int& mi,int N)
{
    int i,dot_pos=-1,len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='.')
        {
            dot_pos=i;
            break;
        }
    }
    if(dot_pos==-1)dot_pos=len;
    i=0;
    while(i<len&&(s[i]=='0'||s[i]=='.'))
    {
        i++;
    }
    if(i<dot_pos)
    mi=dot_pos-i;
    else
        mi=dot_pos-i+1;
    //没找到有效数字
    if(i==len)
        mi=0;
    int sig=0;
    while(sig<N&&i<len)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            dig.push_back(s[i]-'0');
            sig++;
        }i++;
    }
    while(sig<N)
    {
        dig.push_back(0);
        sig++;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,N;
    char n1[MAXN],n2[MAXN];
    while(scanf("%d",&N)!=EOF)
    {
        scanf("%s %s",n1,n2);
        vector<int> dig1,dig2;
        int mi1=0,mi2=0;
        deal(n1,dig1,mi1,N);
        deal(n2,dig2,mi2,N);
        bool equal=false;
        if(mi1==mi2&&dig1.size()==dig2.size())
        {
            for(i=0;i<dig1.size();i++)
            {
                if(dig1[i]!=dig2[i])
                    break;
            }
            if(i==dig1.size())
                equal=true;
        }
        if(equal)
        {
            printf("YES 0.");
            for(i=0;i<dig1.size();i++)
                printf("%d",dig1[i]);
            printf("*10^%d\n",mi1);
        }
        else
        {
            printf("NO 0.");
            for(i=0;i<dig1.size();i++)
                printf("%d",dig1[i]);
            printf("*10^%d 0.",mi1);
            for(i=0;i<dig2.size();i++)
                printf("%d",dig2[i]);
            printf("*10^%d\n",mi2);
        }
    }
    return 0;
}
