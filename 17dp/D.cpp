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
const int MAXN = 100000 +10;
int dp[MAXN];
int value[MAXN];

int main(){
	int sum, n, num;
	int a, c;
	while(~scanf("%d", &n)){
		if(n < 0){
			break;
        }
		num = 0, sum = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &a, &c);
			for(int j = 0; j < c; j++){
				value[num++] = a;
				sum += a;
			}
		}
		for(int i = 0; i < num; ++i){
			for(int j = sum / 2; j >= value[i]; --j){
				dp[j] = std::max(dp[j], dp[j - value[i]] + value[i]);
			}
		}
		printf("%d %d\n", sum - dp[sum / 2], dp[sum / 2]);
	}

	return 0;
}
