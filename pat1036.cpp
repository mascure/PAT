//1036. Boys vs Girls (25)
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
struct Student
{
    char name[15];
    char sex;
    char ID[15];
    int grade;
};
int main()
{
    freopen("in.txt","r",stdin);
    int i,N;
    while(scanf("%d",&N)!=EOF)
    {
        int highFid=-1,highFG,lowMid=-1,lowMG;
        Student *student=new Student[N];
        for(i=0;i<N;i++)
        {
            scanf("%s %c %s %d",student[i].name,&student[i].sex,student[i].ID,&student[i].grade);
            if(student[i].sex=='F')
            {
                if(highFid==-1)
                {
                    highFid=i;
                    highFG=student[i].grade;
                }
                else if(highFid!=-1&&student[i].grade>highFG)
                {
                    highFid=i;
                    highFG=student[i].grade;
                }
            }
            else if(student[i].sex=='M')
            {
                if(lowMid==-1)
                {
                    lowMid=i;
                    lowMG=student[i].grade;
                }
                else if(lowMid!=-1&&student[i].grade<lowMG)
                {
                    lowMid=i;
                    lowMG=student[i].grade;
                }
            }
        }
        if(highFid!=-1&&lowMid!=-1)
        {
            printf("%s %s\n",student[highFid].name,student[highFid].ID);
            printf("%s %s\n",student[lowMid].name,student[lowMid].ID);
            printf("%d\n",highFG-lowMG);
        }
        else
        {
            if(highFid==-1)
            printf("Absent\n");
            else
            printf("%s %s\n",student[highFid].name,student[highFid].ID);
            if(lowMid==-1)
            printf("Absent\n");
            else
            printf("%s %s\n",student[lowMid].name,student[lowMid].ID);
            printf("NA\n");
        }
    }
    return 0;
}
