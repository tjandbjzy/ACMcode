#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 30000 + 100;
std::vector<int> G[MAXN];
std::vector<int> ans;
std::priority_queue<int> q;
bool vis[MAXN];
int ind[MAXN];

int main(){
    //freopen("hdu4857.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i){
            G[i].clear();
        }
        memset(ind, 0, sizeof(ind));
        int a, b;
        for(int i = 0; i < m; ++i){
            scanf("%d %d", &a, &b);
            G[b].push_back(a);
            ++ind[a];
        }
        while(!q.empty()){
            q.pop();
        }
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; ++i){
            if(!ind[i]){
                q.push(i);
                vis[i] = true;
            }
        }
        ans.clear();
        int t;
        while(!q.empty()){
            int x = q.top();
            ans.push_back(x);
            q.pop();
            for(int i = 0; i < G[x].size(); ++i){
                t = G[x][i];
                --ind[t];
                if(!vis[t] && !ind[t]){
                    vis[t] = true;
                    q.push(t);
                }
            } 
        }
        for(int i = n - 1; i >= 0; --i){
            printf(i == 0 ? "%d\n" : "%d ", ans[i]);
        }
    }
    
    return 0;
}
