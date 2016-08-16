#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 4000 + 100;
int dp[MAXN], a[3];

int dfs(int x){
    if(x <= 0){
        return 0;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    if(x == a[2] || x == a[1]){
        dp[x] = std::max(dfs(x - a[2]), std::max(dfs(x - a[1]), dfs(x - a[0]))) + 1;
        return dp[x];
    }
    dp[x] = std::max(dfs(x - a[2]), std::max(dfs(x - a[1]), dfs(x - a[0])));
    if(dp[x]){
        ++dp[x];
    }
    return dp[x];
}

int main(){
    int n;
    scanf("%d %d %d %d", &n, a, a + 1, a + 2);
    std::sort(a, a + 3);
    memset(dp, -1, sizeof(dp));
    dp[a[0]] = 1;
    printf("%d\n", dfs(n));
    //for(int i = 1; i <= n; ++i){
        //printf("%d ", dp[i]);
    //}
    //puts("");
    return 0;
}
