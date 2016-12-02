#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>

typedef long long ll;
const int MAXN = 100000;
struct node{
    int x, y;
    friend bool operator < (const node a, const node b){
        return a.y > b.y;
    }
};
std::priority_queue<node> q;
bool vis[MAXN];

int bfs(int k, int p){
    node tmp;
    tmp.x = k;
    tmp.y = 0;
    while(!q.empty()){
        q.pop();
    }
    memset(vis, false, sizeof(vis));
    vis[k] = true;
    q.push(tmp);
    while(!q.empty()){
        node t = q.top();
        q.pop();
        if(t.x == p){
            return t.y;
        }
        node s;
        s.y = t.y + 1;
        s.x = t.x << 1;
        if(s.x < MAXN && !vis[s.x]){
            q.push(s);
            vis[s.x] = true;
        }
        if((t.x & 1) == 0){
            s.x = t.x >> 1;
            if(s.x < MAXN && !vis[s.x]){
                q.push(s);
                vis[s.x] = true;
            }
        }
        s.x = t.x + 1;
        if(s.x < MAXN && !vis[s.x]){
            q.push(s);
            vis[s.x] = true;
        }
    }
    return -1;
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int p, k;
        scanf("%d %d", &k, &p);
        int ans = bfs(k, p);
        printf("%d\n", ans);
    }
    
    return 0;
}
