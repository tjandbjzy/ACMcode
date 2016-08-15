#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 100;
const int INF = 1 << 30;
ll dp[MAXN], a[MAXN];

int main(){
    int n;
	scanf("%d",&n);
    for (int i = 1; i <= n ; ++i){
        scanf("%lld", a + i);
	}
	std::sort(a + 1 , a + n + 1);
    dp[0] = 0;
    for (int i = 1 ; i <= n ; ++i){
        dp[i] = INF;
        if (i > 1){
            dp[i] =std:: min(dp[i], dp[i - 2] + a[i] - a[i - 1]);
        }
		if (i > 2){
            ll t = std::min(a[i] - a[i - 2] , std::min(a[i] * 2 - a[i - 1] - a[i - 2], a[i] + a[i - 1] - a[i - 2] * 2));
            dp[i] = std::min(dp[i], dp[i - 3] + t);
        }
    }
    printf("%lld\n", dp[n]);
	return 0;
}
