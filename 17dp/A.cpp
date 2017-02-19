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
const int MAXN = 1000 + 100;
int dp[MAXN][MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int m, n, x, y, tmp;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                scanf("%d", &tmp);
                dp[i][j] = tmp + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
        int mx = 0;
        for(int i = x; i <= m; ++i){
            for(int j = y; j <= n; ++j){
                mx = std::max(mx, dp[i][j] - dp[i - x][j] - dp[i][j - y] + dp[i - x][j - y]);
            }
        }
        printf("%d\n", mx);
    }
    
    return 0;
}
