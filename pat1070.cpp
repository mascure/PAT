//pat1069 The Black Hole of Numbers
#include<stdio.h>
#include <stdlib.h>
using namespace std;
struct Cake
{
    float inventory;
    float price;
    float unit;
}cake[1000];
int cmp(const void *a,const void *b)
{
    Cake *aa=(Cake*)a;
    Cake *bb=(Cake*)b;
    return (bb->unit-aa->unit>0?1:-1);
}
int main()
{
    int i,N,D;
    while(scanf("%d %d",&N,&D)!=EOF)
    {
        for(i=0;i<N;i++)
        scanf("%f",&cake[i].inventory);
        for(i=0;i<N;i++)
        {
            scanf("%f",&cake[i].price);
            cake[i].unit=cake[i].price/cake[i].inventory;
        }
        qsort(cake,N,sizeof(cake[0]),cmp);
        float remain=D,ans=0;
        i=0;
        while(remain>0&&i<N)
        {
            if(cake[i].inventory<=remain)
            {
                ans+=cake[i].price;
                remain-=cake[i].inventory;
            }
            else
            {
                ans+=remain/cake[i].inventory*cake[i].price;
                remain-=remain;
            }
            i++;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
