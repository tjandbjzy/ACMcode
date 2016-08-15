#include <cstdio>

const int MAXN = 100 + 10;
long long dp[MAXN];

int main(){
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i < 51; ++i){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int n;
	while(~scanf("%d", &n) && n + 1){
		printf("%lld\n", dp[n]);
	}
	return 0;
}
