//http://pat.zju.edu.cn/contests/pat-a-practise/1055
/*
全排，每个年龄只选前100个留下来
这道题快排的效率为n*log(n),大约为100000*10=10^6
但查询可能有1000个，查询时间总共为10^5*10^3=10^8，因此应当着力优化查询性能
每个年龄保留最多100个，2*10^4*10^3=2*10^7
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 0x7fffffff
#define MAXN 100005
using namespace std;
struct Person
{
    char name[10];
    int age,worth;
}p[MAXN];
int cmp(const void* a,const void* b)
{
    Person aa=*(Person*)a;
    Person bb=*(Person*)b;
    if(aa.worth!=bb.worth)
        return bb.worth-aa.worth;
    if(aa.age!=bb.age)
        return aa.age-bb.age;
    return strcmp(aa.name,bb.name);
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,N,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%s%d%d",p[i].name,&p[i].age,&p[i].worth);
        }
        qsort(p,N,sizeof(p[0]),cmp);
        int M,Amin,Amax;
        int age_count[205]={0};
        int filter[MAXN],filterNum=0;
        for(i=0;i<N;i++)
        {
            if(++age_count[p[i].age]<101)
                filter[filterNum++]=i;
        }
        for(i=0;i<K;i++)
        {
            scanf("%d%d%d",&M,&Amin,&Amax);
            int ansN=0;
            printf("Case #%d:\n",i+1);
            for(j=0;j<filterNum&&ansN<M;j++)
            {
                if(p[filter[j]].age>=Amin&&p[filter[j]].age<=Amax)
                {
                    ansN++;
                    printf("%s %d %d\n",p[filter[j]].name,p[filter[j]].age,p[filter[j]].worth);
                }
            }
            if(ansN==0)
                printf("None\n");
        }
    }
    return 0;
}
