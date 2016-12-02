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
const int MAXN = 1000 + 10;
struct node{
    int x, y, z;
};

node edge[MAXN * MAXN];
int fa[MAXN];

int find(int x){
    return x == fa[x] ? x : find(fa[x]);
}

bool cmp(const node &a, const node &b){
    return a.z < b.z;
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n, m, k;
        int a, b, c;
        int cnt = 0;
        scanf("%d %d %d", &n, &m, &k);
        node e;
        for(int i = 0; i < m; ++i){
            scanf("%d %d", &e.x, &e.y);
            e.z = 0;
            edge[cnt++] = e;
        }
        for(int i = 0; i < k; ++i){
            scanf("%d %d %d", &e.x, &e.y, &e.z);
            edge[cnt++] = e;
        }
        if(cnt < n - 1){
            puts("-1");
            continue;
        }
        for(int i = 0; i <= n; ++i){
            fa[i] = i;
        }
        std::sort(edge, edge + cnt, cmp);
        int ans = 0, f = 0;
        for(int i = 0; i < cnt; ++i){
            a = edge[i].x;
            b = edge[i].y;
            if(find(a) != find(b)){
                f++;
                ans += edge[i].z;
                fa[find(a)] = find(b);
            }
        }
        if(f != n - 1){
            puts("-1");
        }else{
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
