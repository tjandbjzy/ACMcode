#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int INF = 1 << 30;
const int MAXV = 100000 + 10;
const int MAXE = 300000 + 10;

int head[MAXV], tot;

struct node{
    int c, to, next;
}edge[MAXE];

struct maxFlow{
    int s, t, n;
    int d[MAXV], q[MAXV];

    void init(int _s, int _t){
        tot = 0;
        s = _s;
        t = _t;
        n = t + 1;
        memset(head, -1, sizeof(head));
    }
    
    void addEdge(int a, int b, int c){
        edge[tot].to = b;
        edge[tot].c = c;
        edge[tot].next = head[a];
        head[a] = tot++;
    }

    void addDouEdge(int a, int b, int c){
        addEdge(a, b, c);
        addEdge(b, a, 0);
    }

    bool bfs(){
        int t = 0, top = 0, x, y;
        memset(d, -1, sizeof(d));
        d[s] = 0;
        q[top++] = s;
        while(t < top){
            x = q[t++];
            for(int i = head[x]; ~i; i = edge[i].next){
                y = edge[i].to;
                if(d[y] == -1 && edge[j].c){
                    d[y] = d[x] + 1;
                    q[top++] = y;
                }
            }
        }
        if(d[t] == -1){
            return false;
        }
        return true;
    }

    int dfs(int x, int sum){
        if(x == t){
            return sum;
        }
        int y, tmp, os = sum;
        for(int i = head[x]; ~i; i = edge[i].next){
            y = edge[i].to;
            if(edge[i].c  && d[y] == d[x] + 1){
                tmp = dfs(y, std::min(sum, edge[i].c));
                edge[i].c -= tmp;
                edge[i ^ 1].c += tmp;
                sum -= tmp;
            }
        }
        return os - sum;
    }

    int solveMaxFlow(){
        int ans = 0;
        while(bfs()){
            ans += dfs(s, INF);
        }
        return ans;
    }
}Flow;


int main(){
    freopen("Dinic.in", "r", stdin);
    freopen("Dinic.out", "w", stdout);
    int n, m;
    int t = 0;
    while(~scanf("%d %d", &n, &m)){
        Flow.init(1, n);
        while(m--){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            Flow.addDouEdge(a, b, c);
        }
        printf("Case %d : The MaxFlow is %d\n", ++t, Flow.solveMaxFlow());
    }
     
    return 0;
}
