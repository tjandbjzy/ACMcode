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
const int MAXN = 100 + 10;
double dp[MAXN];
double a[MAXN];

int main(){
    int cas, t = 1;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%lf", a + i);
        }
        for(int i = 0; i <= n; ++i){
            dp[i] = 0.0;
        }
        dp[1] = 1.0;
        for(int i = 1; i < n; ++i){
            for(int j = 1; j <= std::min(6, n - i); ++j){
                dp[i + j] += dp[i] / std::min(6, n - i);
            }
        }
        dp[n] = 1.0;
        double ans = 0.0;
        for(int i = 1; i <= n; ++i){
            ans += dp[i] * a[i];
        }
        printf("Case %d: %.7f\n", t++, ans);
    }
    
    return 0;
}
