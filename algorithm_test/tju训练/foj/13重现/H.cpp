#include <cstdio>

const int mod = 1e9 + 7;
typedef long long ll;
const int MAXN = 100000 + 10;
int s[MAXN];
ll dp[MAXN];

int main(int argc, char const *argv[]){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d", s + i);
		}
		dp[0] = 1;
		for(int i = 1; i < n; ++i){
			dp[i] += dp[i - 1];
			dp[i] %= mod;
			for(int j = 0; j < i; ++j){
				if(s[j] < s[i]){
					dp[i] += dp[j];
					dp[i] %= mod;
				}
			}
			dp[i]++;
		}
		//for(int i = 0; i < n; i++)
		printf("%lld\n", dp[n - 1]);
	}
	return 0;
}