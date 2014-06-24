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
#define MAX_N 40005
#define MAX_M 105
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N,M,K;
int quota[MAX_M];
vector<int> admi[MAX_M];
struct Student{
	int id;
	int app[5];
	int GE,GI;
	int rank;
	int school;
}s[MAX_N];
bool cmp(Student a,Student b){
	if(a.GE+a.GI!=b.GE+b.GI)return (a.GE+a.GI)>(b.GE+b.GI);
	return a.GE>b.GE;
}
void solve(){
	sort(s,s+N,cmp);
	int r=1;
	s[0].rank=r;
	for(int i=1;i<N;i++){
		if(cmp(s[i-1],s[i])){
			s[i].rank=i+1;
			r=i+1;
		}
		else{
			s[i].rank=r;
		}
	}
	for(int i=0;i<N;i++){
		//依次试着匹配第j个志愿
		for(int j=0;j<K;j++){
			//相同名次的是否有录取
			int t=i-1,tar=s[i].app[j];
			while(t>=0&&s[i].rank==s[t].rank&&s[t].school!=tar){t--;}
			//找到
			if(t>=0&&s[i].rank==s[t].rank){
				s[i].school=tar;
				admi[tar].push_back(s[i].id);
				break;
			}
			//没找到，看是否名额满
			if(admi[tar].size()<quota[tar]){
				s[i].school=tar;
				admi[tar].push_back(s[i].id);
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		sort(admi[i].begin(),admi[i].end());
		for(int j=0;j<admi[i].size();j++){
			cout<<admi[i][j];
			if(j<admi[i].size()-1)cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&N,&M,&K)!=EOF){
		for(int i=0;i<M;i++)
			scanf("%d",&quota[i]);
		for(int i=0;i<N;i++){
			s[i].id=i;
			scanf("%d%d",&s[i].GE,&s[i].GI);
			for(int j=0;j<K;j++){
				scanf("%d",&s[i].app[j]);
			}
		}
		solve();
	}
	return 0;
}

