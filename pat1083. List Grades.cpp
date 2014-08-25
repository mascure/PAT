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
struct Student{
	string name,ID;
	int grade;
}s[MAX_N];
int N;
int g1,g2;
bool cmp(Student a,Student b){
	return a.grade>b.grade;
}
void solve(){
	sort(s,s+N,cmp);
	int end=N-1,start=0;
	while(end>=0&&s[end].grade<g1)end--;
	while(start<N&&s[start].grade>g2)start++;
	if(start>end)cout<<"NONE"<<endl;
	else{
		for(int i=start;i<=end;i++){
			cout<<s[i].name<<" "<<s[i].ID<<endl;
		}
	}
}
int main(){
	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			cin>>s[i].name>>s[i].ID>>s[i].grade;
		}
		cin>>g1>>g2;
		if(g1>g2)swap(g1,g2);
		solve();
	}
}