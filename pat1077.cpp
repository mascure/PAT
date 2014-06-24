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
#define MAX_N 20005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<string> S;
void solve(){
	int ans=0,len=inf;
	for(int i=0;i<N;i++){
		if(S[i].length()<len)len=S[i].length();
	}
	for(int i=0;i<len;i++){
		string& s=S[0];
		char a=s[s.length()-1-i];
		int j=0;
		for(j=1;j<N;j++){
			if(S[j][S[j].length()-1-i]!=a)break;
		}
		if(j!=N)break;
		ans++;
	}
	if(ans>0)
		cout<<S[0].substr(S[0].length()-ans)<<endl;
	else
		cout<<"nai"<<endl;
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&N)!=EOF){
		getchar();
		S.resize(N);
		for(int i=0;i<N;i++){
			getline(cin,S[i]);
		}
		solve();
	}
	return 0;
}

