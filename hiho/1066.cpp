#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>

typedef long long ll;
const int MAXN = 100000 + 10;
std::map<std::string, int> m;
std::string s, t;
int fa[MAXN];

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}


int main(){
    //freopen("1066.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i = 0; i <= n; ++i){
        fa[i] = i;
    }
    int cnt = 0, op, x, y;
    while(n--){
        std::cin >> op >> s >> t;
        if(op){
            x = find(m[s]);
            y = find(m[t]);
            if(x == y){
                puts("yes");
            }else{
                puts("no");
            }
        }else{
            if(!m[s]){
                m[s] = cnt++;
            }
            if(!m[t]){
                m[t] = cnt++;
            }
            x = find(m[s]);
            y = find(m[t]);
            fa[x] = y;
        }
    }
    return 0;
}
