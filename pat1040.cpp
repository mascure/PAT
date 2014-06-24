#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXN 1005
using namespace std;
int find(char* str,int mid,int len)
{
    int i,ans=1;
    for(i=1;;i++)
    {
        int left=mid-i,right=mid+i;
        if(left>=0&&right<len&&str[left]==str[right])
            ans++;
        else
            break;
    }
    ans=ans*2-1;
    int oans=0;
    for(i=1;;i++)
    {
        int left=mid-i+1,right=mid+i;
        if(left>=0&&right<len&&str[left]==str[right])
            oans++;
        else
            break;
    }
    oans*=2;
    ans=ans>oans?ans:oans;
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i;
    char str[MAXN];
    while(gets(str))
    {
        int ans=0,slen=strlen(str);
        for(i=0;i<slen;i++)
        {
            int len=0;
            len=find(str,i,slen);
            if(len>ans)ans=len;
        }
        printf("%d\n",ans);
    }
    return 0;
}
