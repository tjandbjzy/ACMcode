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
const int MAXN = 300 + 10;
ll dp[MAXN][MAXN];
ll a[MAXN], b[MAXN];
ll g[MAXN][MAXN];

ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}

int main(){
    std::ios::sync_with_stdio(false);
    int cas;
    std::cin >> cas;
    while(cas--){
        int n;
        std::cin >> n;
        ll d;     
        bool flag = false;
        for(int i = 1; i <= n; ++i){
            std::cin >> a[i];
        }
        for(int i = 1; i <= n; ++i){
            std::cin >> b[i];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                g[i][j] = gcd(a[i], a[j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int l = 0; l < n; ++l){
            for(int i = 1; i + l <= n; ++i){
                for(int k = i; k < i + l; ++k){
                    if(g[k][k + 1]!= 1){
                        dp[i][i + l] = std::max(dp[i][i + l], dp[i][k - 1] + dp[k + 2][i + l] + b[k] + b[k + 1]);
                    }
                }
            }
        }
        std::cout << dp[1][n] << "\n";
    }
    
    return 0;
}
