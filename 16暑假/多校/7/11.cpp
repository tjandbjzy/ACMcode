#include <cstdio>

typedef long long ll;
const int MAXN = 1000 + 10;
const int MOD = 1e9 + 7;
const int tMOD = (1e9 + 7) / 2 + 1;

bool right[MAXN];
ll dp[MAXN][MAXN];

int main(){
    int cas, t = 0;
	scanf("%d", &cas);
    while(cas--){
        int n, cur;
		scanf("%d", &n);
        for (int i = 1; i <= n; ++i){
			int x;
			scanf("%d", &x);
			if(x){
				right[i] = true;
			}else{
				right[i] = false;
			}
		}
		dp[1][1] = 1LL;
		cur = 1;
        for (int i = 2; i < n; ++i){
            if(right[i]){
                ++cur;
                for(int j = 1; j <= cur; ++j){
					dp[i][j] = dp[i - 1][j - 1];
            	}
			}else{
                dp[i][cur] = dp[i - 1][cur] * tMOD % MOD;
                for (int j = cur - 1; j > 0; --j){
					dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) * tMOD % MOD;
				}
				dp[i][1] = dp[i][1] * 2 % MOD;
            }
        }
        ll ans = 0LL, h = 1LL;
        for (int i = 1; i <= cur; ++i){
            h = h * tMOD % MOD;
            ans = (ans + dp[n - 1][i] * h % MOD) % MOD;
        }
        printf("Case #%d: %lld\n", ++t, ans);
    }

    return 0;
}
