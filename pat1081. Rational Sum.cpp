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
P a[MAX_N];
ll gcd(ll a,ll b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
P Plus(P a,P b){
	ll g=gcd(a.second,b.second);
	P res;
	res.second=a.second*b.second/g;
	res.first=a.first*(res.second/a.second)+b.first*(res.second/b.second);
	ll gg=gcd(res.first,res.second);
	res.first/=gg;
	res.second/=gg;
	return res;
}
void solve(){
	while(N>1){
		a[N-2]=Plus(a[N-1],a[N-2]);
		N--;
	}
	if(a[0].first==0){
		cout<<0<<endl;
	}
	else if(abs(a[0].first)>=a[0].second){
		if(a[0].first<0){
			cout<<"-";
			a[0].first=-a[0].first;
		}
		cout<<a[0].first/a[0].second;
		if(a[0].first%a[0].second!=0){
			cout<<" "<<a[0].first%a[0].second<<"/"<<a[0].second;
		}
		cout<<endl;
	}
	else{
		cout<<a[0].first<<"/"<<a[0].second<<endl;
	}
}
int main(){
	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%lld/%lld",&a[i].first,&a[i].second);
		}
		solve();
	}
}