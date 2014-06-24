//http://pat.zju.edu.cn/contests/pat-a-practise/1055
/*
全排，从前往后依次检查是否符合年龄要求，得到结果，21分
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
    //freopen("in.txt","r",stdin);
    int i,j,N,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%s%d%d",p[i].name,&p[i].age,&p[i].worth);
        }
        qsort(p,N,sizeof(p[0]),cmp);
        int M,Amin,Amax;
        for(i=0;i<K;i++)
        {
            scanf("%d%d%d",&M,&Amin,&Amax);
            int ansN=0;
            printf("Case #%d:\n",i+1);
            for(j=0;j<N&&ansN<M;j++)
            {
                if(p[j].age>=Amin&&p[j].age<=Amax)
                {
                    ansN++;
                    printf("%s %d %d\n",p[j].name,p[j].age,p[j].worth);
                }
            }
            if(ansN==0)
                printf("None\n");
        }
    }
    return 0;
}
