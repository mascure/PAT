//pat1069 The Black Hole of Numbers
#include<stdio.h>
#include <stdlib.h>
using namespace std;
//ÉýÐò
int cmp1(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}
//½µÐò
int cmp2(const void *a,const void *b)
{
    return (*(int *)b-*(int *)a);
}
int main()
{
    int N;
    int wei[4],jiang[4],sheng[4],da,xiao,result;
    while(scanf("%d",&N)!=EOF)
    {
        do
        {
            jiang[0]=sheng[0]=wei[0]=N/1000;
            jiang[1]=sheng[1]=wei[1]=(N%1000)/100;
            jiang[2]=sheng[2]=wei[2]=(N%100)/10;
            jiang[3]=sheng[3]=wei[3]=N%10;
            if(wei[0]==wei[1]&&wei[1]==wei[2]&&wei[2]==wei[3])
            {
                printf("%d - %d = 0000\n",N,N);
                break;
            }
            qsort(jiang,4,sizeof(jiang[0]),cmp2);
            qsort(sheng,4,sizeof(sheng[0]),cmp1);
            da=jiang[0]*1000+jiang[1]*100+jiang[2]*10+jiang[3];
            xiao=sheng[0]*1000+sheng[1]*100+sheng[2]*10+sheng[3];
            result=da-xiao;
            printf("%d%d%d%d - %d%d%d%d = %04d\n",jiang[0],jiang[1],jiang[2],jiang[3],sheng[0],sheng[1],sheng[2],sheng[3],result);
            N=result;
        }while(N!=6174);
    }
    return 0;
}
