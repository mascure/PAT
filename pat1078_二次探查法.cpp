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

int M,N;
vector<int> k;
bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return n!=1;
}
void solve(){
	while(!isPrime(M))M++;
	vector<int> kp(N);
	vector<int> p(M);
	fill(p.begin(),p.end(),-1);
	fill(kp.begin(),kp.end(),-1);
	for(int i=0;i<N;i++){
		int pos=k[i]%M;
		for(int t=0;t<M;t++){
			int rp=(pos+t*t)%M;
			if(p[rp]==-1){
				p[rp]=k[i];
				kp[i]=rp;
				break;
			}
		}
	}
	cout<<kp[0];
	for(int i=1;i<N;i++){
		if(kp[i]==-1)cout<<" -";
		else cout<<" "<<kp[i];
	}
	cout<<endl;
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&M,&N)!=EOF){
		k.resize(N);
		for(int i=0;i<N;i++){
			scanf("%d",&k[i]);
		}
		solve();
	}
	return 0;
}

