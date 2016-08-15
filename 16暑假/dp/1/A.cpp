#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100 + 10;
int dp[MAXN][MAXN];


int main(){
    //freopen("A.in", "r", stdin);
	int cas;
	scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                scanf("%d" , &dp[i][j]); 
            }
        }
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[i][j] += std::max(dp[i - 1][j], dp[i - 1][j - 1]);
            } 
        }
        int ans = -1;
        for(int i = 1; i <= n; ++i){
            ans = std::max(dp[n][i], ans); 
        }
        printf("%d\n", ans);
    }
    return 0;
}
