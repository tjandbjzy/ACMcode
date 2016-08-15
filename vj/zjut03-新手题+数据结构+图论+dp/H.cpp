#include <cstdio>
#include <iostream>

typedef long long ll;
const int MAXN = 30;
ll dp[MAXN];

int main(){
	dp[2] = 1;
	dp[3] = 2;
	for(int i = 4; i < 25; ++i){
		dp[i] = dp[i - 1] * (i - 1) + dp[i - 2] * (i - 1);
	}
	int n;
	while(~scanf("%d", &n)){
		printf("%lld\n", dp[n]);
	}
	return 0;
}
