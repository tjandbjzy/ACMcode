#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 300;
const int INF = (1 << 30);
int dp[MAXN][MAXN];
int a[MAXN], b[MAXN];

int main(){
    freopen("A.in", "r", stdin);
    int cas, t = 0;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", a + i);
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", b + i);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = i <= j ? INF : 0;
            }
        }
        for(int j = 0; j <= n; ++j){
            for(int i = 1; i + j <= n; ++i){
                for(int k = i; k <= i + j; ++k){
                    dp[i][i + j] = std::min(dp[i][i + j], dp[i][k - 1] + dp[k + 1][i + j] + a[k] + b[i - 1] + b[i + j + 1]);
                }
            }
        }
        printf("Case #%d: %d\n", ++t, dp[1][n]);
    }
    return 0;
}
