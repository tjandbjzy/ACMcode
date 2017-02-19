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
const int MAXN = 1000 + 5;

struct node{
    int x, y;
    bool operator <(const node &a) const{
        if(y != a.y){
            return y > a.y;
        }
        return x < a.x;
    }
};

node s[MAXN];
bool vis[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &s[i].x);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &s[i].y);
        }
        std::sort(s, s + n);
        memset(vis, false, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int k;
            for(k = s[i].x; k > 0; --k){
                if(!vis[k]){
                    vis[k] = true;
                    break;
                }
            }
            if(!k){
                ans += s[i].y;
            }
        }
        printf("%d\n", ans);

    }
    
    return 0;
}

