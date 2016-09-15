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
struct node{
    int cnt, r;
};

std::vector<node> v[MAXN];
int a[MAXN];
int ans[MAXN];

bool cmp(const node &a, const node &b){
    return a.r < b.r;
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", a + i);
        }
        int m;
        scanf("%d", &m);
        int l, r;
        node e;
        for(int i = 0; i < m; ++i){
            scanf("%d %d", &l, &r);
            e.cnt = i;
            e.r = r;
            v[l].push_back(e);
        }
        for(int i = 1; i <= n; ++i){
            if(v[i].size()){
                std::sort(v[i].begin(), v[i].end(), cmp);
            }
        }
        int len, k, tans;
        for(int i = 1; i <= n; ++i){
            if(v[i].size() == 0){
                continue;
            }
            len = v[i].size();
            k = 0;
            tans = a[i];
            if(v[i][0].r == i){
                ans[v[i][0].cnt] = tans;
                ++k;
            }
            for(int j = i + 1; j <= v[i][len - 1].r; ++j){
                tans %= a[j];
                if(j == v[i][k].r){
                    ans[v[i][k].cnt] = tans;
                    ++k;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            printf("%d\n", ans[i]);
        }
        
    }

    
    return 0;
}
