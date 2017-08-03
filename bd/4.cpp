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
const int MAXN = 30;
int a[MAXN][MAXN];
ll dp[MAXN][MAXN];
int n, m;

ll dfs(int x, int y){
    if(x < 1 || y < 1){
        return 0;
    }
    if(a[x][y] == 1){
        return 0;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
    return dp[x][y];
}

void init(){
    memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));
    dp[1][1] = 1;
    return;
}

int main(){
    int k;
    while(~scanf("%d %d %d", &n, &m, &k)){
        init();
        int x, y;
        for(int i = 0; i < k; ++i){
            scanf("%d %d", &x, &y);
            a[x][y] = 1;
        }
        ll ans = dfs(n, m);
        init();
        ll sum = dfs(n, m);
        double res = 1.0 * ans / (1.0 * sum);
        printf("%.2f\n", res);
        
    }

    
    return 0;
}
