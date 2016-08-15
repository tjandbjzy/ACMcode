#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

typedef long long ll;
const int MAXN = 100000 + 100;

int a[MAXN], next[MAXN], pre[MAXN], l[MAXN];
ll s[MAXN];

int solve(int n){
    int ans = -1;
    memset(pre, 0, sizeof(pre));
    for(int i = 1; i <= n; ++i){
        if(a[i] > n){
            next[i] = 0;
            a[i] = n + 1;
        }else{
            next[i] = pre[a[i]];
            pre[a[i]] = i;
        }
    }
    for(int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + a[i];
    }
    memset(l ,0x3f, sizeof(l));
    for(int i = 1; i <= n; ++i){
        if(a[i] == 1){
            int ma = -1;
            for(int j = i + 1; j <= n && a[j] != 1; ++j){
                l[j] = std::min(l[j - 1], next[j]);
            }        
            int nextma = 0;
            for(int j = i; j >= 1 && (j == i || a[j] != 1); --j){
                ma = std::max(ma, a[j]);
                nextma = std::max(nextma, next[j]);/*
                if(j + ma - 1 < i || j + ma - 1 > n){
                    continue;
                }                
                if(std::max(nextma, l[j + ma - 1]) >= j){
                    continue;
                }*/
                if(s[j + ma - 1] - s[j - 1] == (ll)(ma + 1) * ma / 2){
                    ans = std::max(ans, ma);
                }
            }
        }
    }
    return ans;
}

int main(){

    freopen("A.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }
    int ans = solve(n);
    //std::cout << ans << std::endl;
    for(int i = 1; i <= n / 2; ++i){
        std::swap(a[i], a[n - i + 1]);
    }
    ans = std::max(ans, solve(n));
    printf("%d\n",ans);
    
    return 0;
}
