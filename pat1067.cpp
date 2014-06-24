//http://pat.zju.edu.cn/contests/pat-a-practise/1067
/*
将[0,N-1]的一个排列排序，只允许做0和x位置的交换，求最小的交换次数。
位置已经对的数不用动，检查不在对的位置上的数。
不在位置上的数将形成k个封闭的环，需要k次操作，每次操作把一个环内的所有数放对位置。所有操作的次数和即所求。
对每一个环，环内有n个数，先把第一个位置上的数包含进来，进行一次交换。之后需要n次交换就可将这n个数放对位置，因此一次大操作包含的交换次数为n+1。
当0在某一个环内时（p[0]!=0），该环的交换次数为n-1
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100005
int p[MAXN],visited[MAXN];
int n;
int main() {
    int i,ans=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &p[i]);
    }
    ans=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0&&p[i]!=i)
        {
            int start=i,sum=1;
            visited[i]=1;
            while(p[start]!=i)
            {
                sum++;
                start=p[start];
                visited[start]=1;
            }
            ans+=sum+1;
        }
    }
    if(p[0]!=0)
    ans-=2;
    printf("%d\n",ans);
    return 0;
}
