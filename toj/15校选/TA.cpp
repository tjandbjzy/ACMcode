#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 10000 + 10;
int dp[MAXN][3];

int dfs(int n, int m){
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(!n){
        return 0;
    }
    if(m == 1){
        return n;
    }
    int mn = 1 << 30, mx;
    for(int i = 1; i <= n; ++i){
        mx = std::max(dfs(i - 1, m - 1), dfs(n - i, m));
        mn = std::min(mn, mx);
    }
    return mn + 1;
}

int main(){
    memset(dp, -1, sizeof(dp));
    //dfs(30, 2);
    for(int i = 1; i <= 20; ++i){
        printf("%d\n", dfs(i, 2));
    }
    return 0;
}
