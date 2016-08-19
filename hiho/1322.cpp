#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 10;
struct edge{
    int u, v;
};

edge s[MAXN];
int fa[600];

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
    freopen("1322.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i){
            fa[i] = i;
        }
        for(int i = 0; i < m; ++i){
            scanf("%d %d", &s[i].u, &s[i].v);
        } 
        bool flag = true;
        for(int i = 0; i < m; ++i){
            int x = find(s[i].u), y = find(s[i].v);
            if(x == y){
                flag = false;
                break;
            }
            fa[x] = y;
        }
        int rt = find(1);
        for(int i = 1; i <= n; ++i){
            if(rt != find(i)){
                flag = false;
                break;
            }
        }
        if(flag){
            puts("YES");
        }else{
            puts("NO");
        }
    }
        
    return 0;
}
