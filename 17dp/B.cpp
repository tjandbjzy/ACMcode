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
const int MX = 20 * 15 * 25 * 2;
int dp[21][MX + 100];
int c[21];
int g[21];

int main(){
    int n, m;
    while(~scanf("%d %d", &n, &m)){
        for(int i = 0 ; i < n; ++i){
            scanf("%d", c + i);
        }
        for(int i = 1; i <= m; ++i){
            scanf("%d", g + i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][MX / 2] = 1;
        for(int i = 1; i <= m; ++i){
            for(int j = 0; j <= MX; ++j){
                for(int k = 0; k < n; ++k){
                    dp[i][j + c[k] * g[i]] += dp[i - 1][j];
                }
            }
        }
        printf("%d\n", dp[m][MX / 2]);
    }
    
    return 0;
}
