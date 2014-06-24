#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 1005
using namespace std;
int N, L;
vector<int> f[MAXN];
bool visited[MAXN];
bool childv[MAXN];
int sou(int id, int level) {
    int ans = 0;
    if(!visited[id])ans++;
    visited[id] = true;
    if(level < L && !childv[id]) {
        childv[id]=true;
        for(int i = 0; i < f[id].size(); i++) {
            int t = f[id][i];
            ans += sou(t, level + 1);
        }
    }
    return ans;
}
int main() {
    int i, j;
    while(scanf("%d%d", &N, &L) != EOF) {
        for(i = 1; i <= N ; i++)
            f[i].clear();
        for(i = 1; i <= N; i++) {
            int num;
            scanf("%d", &num);
            for(j = 0; j < num; j++) {
                int id;
                scanf("%d", &id);
                f[id].push_back(i);
            }
        }
        int qn, id;
        scanf("%d", &qn);
        for(i = 0; i < qn; i++) {
            fill(visited + 1, visited + N + 1, false);
            fill(childv + 1, childv + N + 1, false);
            scanf("%d", &id);
            int ans = sou(id, 0) - 1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
