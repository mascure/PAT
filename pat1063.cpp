//http://pat.zju.edu.cn/contests/pat-a-practise/1063
/*
比较两个数组的相似度，首先排序，用短的数组中的数二分查找另一个数组中的相同的数，得到相同的数的个数，再统计两个数列互不相同的数的个数，两者相除得到结果
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<sstream>
#define inf 10000000
#define MAXN 40005
using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}
bool find(const vector<int>& s,int n)
{
    int low=0,high=s.size()-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(s[mid]<n)
        low=mid+1;
        else if(s[mid]==n)
        return true;
        else
        high=mid-1;
    }
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,N,M,K;
    while(scanf("%d",&N)!=EOF)
    {
        vector<int> sets[50];
        for(i=0;i<N;i++)
        {
            scanf("%d",&M);
            for(j=0;j<M;j++)
            {
                int n;
                scanf("%d",&n);
                sets[i].push_back(n);
            }
            sort(sets[i].begin(),sets[i].end(),cmp);
        }
        scanf("%d",&K);
        int s1,s2;
        while(K--)
        {
            scanf("%d%d",&s1,&s2);
            if(sets[s1-1].size()>sets[s2-1].size())
            {
                int tmp;
                tmp=s1;
                s1=s2;
                s2=tmp;
            }
            s1--;s2--;
            int common=0,total=sets[s1].size()+sets[s2].size(),dis1=0,dis2=0;
            for(i=0;i<sets[s1].size();i++)
            {
                dis1++;
                if(find(sets[s2],sets[s1][i]))
                common++;
                while(i+1<sets[s1].size()&&sets[s1][i]==sets[s1][i+1])
                i++;
            }
            i=0;
            for(i=0;i<sets[s2].size();i++)
            {
                dis2++;
                while(i+1<sets[s2].size()&&sets[s2][i]==sets[s2][i+1])
                i++;
            }
            total=dis1+dis2-common;
            printf("%.1f%%\n",common*100.0/total);
        }
    }
    return 0;
}
