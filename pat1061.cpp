//http://pat.zju.edu.cn/contests/pat-a-practise/1061
/*
一道坑题，题意比较难摸准
星期：找到s1和s2第一个范围在'A'到'G'的字母，
小时：再找到之后的第一个范围在'0'到'9'或'A'到'N'的字母
分：s3和s4第一个相同字母的位置
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
char DAY[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    freopen("in.txt","r",stdin);
    int i;
    char s1[MAXN],s2[MAXN],s3[MAXN],s4[MAXN];
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        scanf("%s",s3);
        scanf("%s",s4);
        int d=-1,h=-1,m=-1;
        int len1=strlen(s1),len2=strlen(s2),len3=strlen(s3),len4=strlen(s4);
        for(i=0;i<len1;i++)
        {
            if(s1[i]>='A'&&s1[i]<='G'&&s2[i]==s1[i])
            {
                d=(s1[i]-'A');
                break;
            }
        }
        for(i++;i<len1&&i<len2;i++)
        {
            //if((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='0'&&s1[i]<='9'))
            if(((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9'))&&s2[i]==s1[i])
            {
                if(s1[i]>='0'&&s1[i]<='9')
                {
                    h=s1[i]-'0';
                }
                if(s1[i]>='A'&&s1[i]<='N')
                {
                    h=s1[i]-'A'+10;
                }
                break;
            }
        }
        for(i=0;i<len3&&i<len4;i++)
        {
            if(((s3[i]>='A'&&s3[i]<='Z')||(s3[i]>='a'&&s3[i]<='z'))&&s3[i]==s4[i])
            {
                m=i%60;
                break;
            }
        }
        printf("%s %02d:%02d\n",DAY[d],h,m);
    }
    return 0;
}
