//pat 1022. Digital Library (30)
//看别人的代码，找处理输入，字符串的简便方法
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
//#include<map>
#include<algorithm>
#define MAXN 505
#define inf 0x7fffffff
#define LL long long
using namespace std;

struct Book
{
    int ID;
    char title[85];
    char author[85];
    int keyNum;
    char key[5][15];
    char publisher[85];
    char year[5];
};
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
	//freopen("in.txt","r",stdin);
    int i,j,k,N,M;
    //char s[80];
    //Book a;
    //gets(s);
    //scanf("%s %s %s %s %s",a.key[0],a.key[1],a.key[2],a.key[3],a.key[4]);
    //printf("%s %s %s %s %s\n",a.key[0],a.key[1],a.key[2],a.key[3],a.key[4]);
    while(scanf("%d",&N)!=EOF)
    {
        Book* book=new Book[N];
        int* res=new int[N],resN=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&book[i].ID);
            getchar();
            gets(book[i].title);
            gets(book[i].author);
            char tmp[85];
            gets(tmp);
            j=0,k=0;
            book[i].keyNum=0;
            while(tmp[j]!='\0')
            {
                int t=0;
                //若为空格，跳到下一个字符
                if(tmp[j]==' ')j++;
                while(tmp[j]!=' '&&tmp[j]!='\0')
                {
                    book[i].key[k][t]=tmp[j];
                    t++;
                    j++;
                }
                book[i].key[k][t]='\0';
                k++;
            }
            book[i].keyNum=k;
            gets(book[i].publisher);
            scanf("%s",book[i].year);
            //printf("%s\n",book[i].title);
            //printf("%s\n",book[i].author);
            //for(j=0;j<book[i].keyNum;j++)
            //printf("%s\n",book[i].key[j]);
        }
        scanf("%d",&M);
        int id;
        char query[85];
        for(i=0;i<M;i++)
        {
            resN=0;
            scanf("%d:",&id);
            getchar();
            gets(query);
            printf("%d: %s\n",id,query);
            if(id==1)
            {
                for(j=0;j<N;j++)
                if(strcmp(book[j].title,query)==0)
                res[resN++]=book[j].ID;
            }
            else if(id==2)
            {
                for(j=0;j<N;j++)
                if(strcmp(book[j].author,query)==0)
                res[resN++]=book[j].ID;
            }
            else if(id==3)
            {
                for(j=0;j<N;j++)
                {
                    for(k=0;k<book[j].keyNum;k++)
                    if(strcmp(book[j].key[k],query)==0)
                    {
                        res[resN++]=book[j].ID;
                        break;
                    }
                }
            }
            else if(id==4)
            {
                for(j=0;j<N;j++)
                if(strcmp(book[j].publisher,query)==0)
                res[resN++]=book[j].ID;
            }
            else if(id==5)
            {
                for(j=0;j<N;j++)
                if(strcmp(book[j].year,query)==0)
                res[resN++]=book[j].ID;
            }
            if(resN==0)
            printf("Not Found\n");
            else
            {
                qsort(res,resN,sizeof(res[0]),cmp);
                for(j=0;j<resN;j++)
                printf("%d\n",res[j]);
            }
        }
    }
	return 0;
}
