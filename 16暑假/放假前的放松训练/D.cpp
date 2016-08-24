#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int INF = -0x3f3f3f3f;
const int MAXN = 25;
int dp[MAXN][MAXN][MAXN][MAXN];
int w[2][MAXN];

int cal(int a, int b, int c, int d, int flag){
    if(a > b && c > d){
        return 0;
    }
    int &t = dp[a][b][c][d];
    if(t != INF){
        return t;
    }
    if(flag == 1){
        if(a <= b){
            t = std::max(t, flag * w[0][a] + cal(a + 1, b, c, d, -flag));
            t = std::max(t, flag * w[0][b] + cal(a, b - 1, c, d, -flag));
        }
        if(c <= d){
            t = std::max(t, flag * w[1][c] + cal(a, b, c + 1, d, -flag));
            t = std::max(t, flag * w[1][d] + cal(a, b, c, d - 1, -flag));
        }
    }else{
        t -= INF;
        if(a <= b){
            t = std::min(t, flag * w[0][a] + cal(a + 1, b, c, d, -flag));
            t = std::min(t, flag * w[0][b] + cal(a, b - 1, c, d, -flag));
        }
        if(c <= d){
            t = std::min(t, flag * w[1][c] + cal(a, b, c + 1, d, -flag));
            t = std::min(t, flag * w[1][d] + cal(a, b, c, d - 1, -flag));
        }

    }
    return t;
}

int main(){
    freopen("D.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int k = 0; k < 2; ++k){
            for(int i = 1; i <= n; ++i){
                scanf("%d", &w[k][i]);
                sum += w[k][i];
            }
        }
        for(int i = 0; i <= n + 1; ++i){
            for(int j = 0; j <= n + 1; ++j){
                for(int k = 0; k <= n + 1; ++k){
                    for(int l = 0; l <= n + 1; ++l){
                        dp[i][j][k][l] = INF;
                    }
                }
            }
        }
        int ans = sum + cal(1, n, 1, n, 1);
        ans >>= 1;
        printf("%d\n", ans);
    }
    return 0;
}
