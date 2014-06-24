//http://pat.zju.edu.cn/contests/pat-a-practise/1075
/*
pat排序，注意，得分为-1时应当输出0，不是-1，样例中可以看出
*/
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
//#include<map>
#define inf 0x7fffffff
#define LL long long
#define MAX_E 1000000
#define MAX_V 500
#define MAXN 10005
using namespace std;
struct Student
{
    int id;
    int score[5];
    int total;
}S[MAXN];
int N,K,M;
int fen[5];
int total(Student x)
{
    int i,ans=0;
    for(i=0;i<K;i++)
    {
        if(x.score[i]>=0)ans+=x.score[i];
    }
    return ans;
}
bool check(Student& x)
{
    x.total=total(x);
    for(int i=0;i<K;i++)
    {
        if(x.score[i]>-1)
        return true;
    }
    return false;
}
int perfect(Student x)
{
    int ans=0;
    for(int i=0;i<K;i++)
    {
        if(x.score[i]==fen[i])ans++;
    }
    return ans;
}
int cmp(const void *a,const void *b)
{
    Student aa=*(Student*)a;
    Student bb=*(Student*)b;
    if(aa.total!=bb.total)
    return bb.total-aa.total;
    int pa=perfect(aa),pb=perfect(bb);
    if(pa!=pb)
    return pb-pa;
    return aa.id-bb.id;
}
int main()
{
	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d%d",&N,&K,&M)!=EOF)
	{
	    for(i=0;i<N;i++)
	    {
	        S[i].id=i+1;
	        S[i].total=0;
	        fill(S[i].score,S[i].score+5,-2);
	    }
	    for(i=0;i<K;i++)
	    scanf("%d",&fen[i]);
	    for(i=0;i<M;i++)
	    {
	        int id,num,get;
	        scanf("%d%d%d",&id,&num,&get);
	        id--;
	        num--;
	        if(get>S[id].score[num])
	        S[id].score[num]=get;
	    }
        int rn=0;
	    for(i=0;i<N;i++)
	    {
	        if(check(S[i]))S[rn++]=S[i];
	    }
	    qsort(S,rn,sizeof(S[0]),cmp);
	    int lastR=-1;
	    for(i=0;i<rn;i++)
	    {
	        int rank=i+1;
	        if(i>0&&S[i-1].total==S[i].total)rank=lastR;
	        Student& x=S[i];
	        printf("%d %05d %d",rank,x.id,x.total);
	        for(j=0;j<K;j++)
	        {
	            if(x.score[j]==-2)
	            printf(" -");
	            else if(x.score[j]==-1)
	            printf(" 0");
	            else
	            printf(" %d",x.score[j]);
	        }
	        printf("\n");
	        lastR=rank;
	    }
	}
	return 0;
}
