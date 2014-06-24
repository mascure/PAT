//1047. Student List for Course (25)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 100005
int str2int(char* name)
{
    return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}
char* int2str(int k)
{
    char* name=new char[5];
    name[0]=k/(26*26*10)+'A';
    name[1]=(k%(26*26*10))/(26*10)+'A';
    name[2]=(k%(26*10))/10+'A';
    name[3]=k%10+'0';
    name[4]='\0';
    return name;
}
bool cmp(int a,int b)
{
    return a<b;
}
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,N,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        vector<vector<int> > course;
        course.resize(K+1);
        for(i=0;i<N;i++)
        {
            char name[5];
            int courseId,num;
            scanf("%s %d",name,&num);
            int iName=str2int(name);
            for(j=0;j<num;j++)
            {
                scanf("%d",&courseId);
                course[courseId].push_back(iName);
            }
        }
        for(i=1;i<=K;i++)
        {
            printf("%d %d\n",i,course[i].size());
            sort(course[i].begin(),course[i].end(),cmp);
            for(j=0;j<course[i].size();j++)
            {
                printf("%s\n",int2str(course[i][j]));
            }
        }
    }
    return 0;
}
