#include <iostream>
#include <cstring>

const int MAXN = 3000 + 100;
typedef long long ll;
ll sum[MAXN], num[MAXN];
int dp[MAXN];


int main(int argc, char const *argv[]){
	std::ios::sync_with_stdio(false);
	int n;
	while(std::cin >> n){
		memset(sum, 0, sizeof(sum));
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i){
			std::cin >> sum[i];
			sum[i] += sum[i - 1];
		}
		for(int i = 1; i <= n; ++i){
			for(int j = i - 1; ; --j){
				if(sum[i] - sum[j] >= num[j]){
					num[i] = sum[i] - sum[j];
					dp[i] = dp[j] + i - j - 1;
					break;
				}
			}
		}
		std::cout << n - dp[n] << std::endl;
	}
	return 0;
}
