#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<math.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_N 100005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
double p,r;
int level[MAX_N],num[MAX_N];
vector<int> child[MAX_N];
double mi[MAX_N];
int maxL=0;
void sou(int x){
  for(int i=0;i<child[x].size();i++){
    int t=child[x][i];
    level[t]=level[x]+1;
    maxL=max(maxL,level[t]);
    sou(t);
  }
}
void solve(){
  //Çólevel
  memset(level,sizeof(level),0);
  level[0]=0;
  sou(0);
  double tmp=1;
  r=1+(r/100);
  for(int i=0;i<=maxL;i++){
    mi[i]=tmp;
    tmp*=r;
  }
  double res=0;
  for(int i=0;i<N;i++){
    if(num[i]>0){
      res+=num[i]*mi[level[i]];
    }
  }
  res*=p;
  printf("%.1f\n",res);
}
int main(){
  //freopen("in.txt","r",stdin);
  while(scanf("%d%lf%lf",&N,&p,&r)!=EOF){
    //memset(num,sizeof(num),-1);
    //memset(pa,sizeof(pa),-1);
    fill(num,num+N,-1);
    for(int i=0;i<N;i++){
      int k;
      scanf("%d",&k);
      child[i].resize(k);
      if(k==0)scanf("%d",&num[i]);
      else{
        for(int j=0;j<k;j++){
          scanf("%d",&child[i][j]);
        }
      }
    }
    solve();
  }
  return 0;
}