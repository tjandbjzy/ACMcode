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
const int MAXN = 100 + 10;

struct node{
    int x, y, t;
};

int n, m;
node d[MAXN][MAXN];
std::queue<node> q;
bool vis[MAXN][MAXN];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool ok(int x, int y){
    return x <= n && x >= 1 && y <= m && y >= 1;
}

int bfs(){
    memset(vis, false, sizeof(vis));
    node st;
    st.x = st.y = st.t = 1;    
    vis[1][1] = true;
    q.push(st);
    while(!q.empty()){
        node tmp = q.front(), nxt;
        vis[tmp.x][tmp.y] = true;
        q.pop();
        if(tmp.x == n && tmp.y == m){
            return tmp.t;
        }
        for(int i = 0; i < 4; ++i){
            nxt.x = tmp.x + dx[i];
            nxt.y = tmp.y + dy[i];
            nxt.t = tmp.t + 1;
            if(nxt.t >= d[nxt.x][nxt.y].x && nxt.t <= d[nxt.x][nxt.y].y){
                continue;
            }
            if(ok(nxt.x, nxt.y) && !vis[nxt.x][nxt.y]){
                q.push(nxt);
            }
        }
    }
    return -1;
}

int main(){
    int t;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            d[i][j].x = d[i][j].y = -1;
        }
    }
    int a, b, c, e;
    for(int i = 0; i < t; ++i){
        scanf("%d %d %d %d", &a, &b, &c, &e);
        d[a][b].x = c;
        d[a][b].y = e;
    }
    printf("%d\n", bfs() + 1);
    return 0;
}
