#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<unordered_map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
const int MAX_N=105;
typedef long long ll;
typedef pair<ll,ll> P;
int N;
int wei[10];
string du[10]={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi","Shi"};
string shu[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void solve(){
	if(N==0){
		cout<<"ling"<<endl;
		return;
	}
	if(N<0){
		cout<<"Fu ";
		N=-N;
	}
	int i=0;
	while(N>0){
		wei[i]=N%10;
		i++;N/=10;
	}
	i--;
	bool first=true;
	while(i>=0){
		if(wei[i]>0){
			if(first){first=false;}
			else cout<<" ";
			cout<<shu[wei[i]];
			if(i>0)
			cout<<" "<<du[i];
			i--;
		}
		else{
			while(i>=0&&wei[i]==0){
				if(i==8)cout<<" Yi";
				if(i==4)cout<<" Wan";
				i--;
			}
			if(i>=0&&!(i==7||i==3))cout<<" ling";
		}
	}
	cout<<endl;
}
int main(){
	while(scanf("%d",&N)!=EOF){
		solve();
	}
}