#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
//#include<map>
#include<algorithm>
#define MAXN 1005
#define inf 0x7fffffff
#define LL long long
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
    int r,g,b;
	char red[3],green[3],blue[3];
	char c[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	while(scanf("%d%d%d",&r,&g,&b)!=EOF)
	{
		red[0]=c[r/13];
		red[1]=c[r%13];
		red[2]='\0';
		green[0]=c[g/13];
		green[1]=c[g%13];
		green[2]='\0';
		blue[0]=c[b/13];
		blue[1]=c[b%13];
		blue[2]='\0';
		printf("#%s%s%s\n",red,green,blue);
	}
	return 0;
}