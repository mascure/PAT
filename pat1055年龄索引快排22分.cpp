//http://pat.zju.edu.cn/contests/pat-a-practise/1055
/*
建立年龄索引，在选中的区间内得到列表，快排，输出前M个
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
struct Person
{
    char name[10];
    int age,worth;
}p[MAXN];
int N;
bool cmp(const Person aa,const Person bb)
{
    if(aa.worth!=bb.worth)
        return aa.worth>bb.worth;
    if(aa.age!=bb.age)
        return aa.age<bb.age;
    return strcmp(aa.name,bb.name)<0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        Person a;
        vector<Person> Age[205];
        for(i=0;i<N;i++)
        {
            scanf("%s%d%d",a.name,&a.age,&a.worth);
            Age[a.age].push_back(a);
        }
        int M,Amin,Amax;
        for(i=0;i<K;i++)
        {
            scanf("%d%d%d",&M,&Amin,&Amax);
            vector<Person> res;
            for(j=Amin;j<=Amax;j++)
            {
                for(k=0;k<Age[j].size();k++)
                    res.push_back(Age[j][k]);
            }
            printf("Case #%d:\n",i+1);
            if(res.size()==0)
            {
                printf("None\n");
                continue;
            }
            sort(res.begin(),res.end(),cmp);
            for(j=0;j<res.size()&&j<M;j++)
            {
                printf("%s %d %d\n",res[j].name,res[j].age,res[j].worth);
            }
        }
    }
    return 0;
}
