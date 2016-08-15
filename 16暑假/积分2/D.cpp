#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int MAXN = 1000000 + 10;
int dp[2][1<<14];
int MOD = 1000000007;

int main(){
	int n, x;
	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < n; ++i){
			scanf("%d", &x);
			for(int j = 0; j < (1 << 14); ++j)
				dp[1][j] = dp[0][j];
			for(int j = 0; j < (1 << 14); ++j)
				if(dp[1][j]){
					dp[0][j ^ x] = (dp[0][j ^ x] + dp[1][j] * 2) % MOD;
				}
		}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}
