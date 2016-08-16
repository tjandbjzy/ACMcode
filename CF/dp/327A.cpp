#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100 + 10;
int s[MAXN], dp[MAXN];

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        s[i] = x? -1 : 1;
        if(x){
            ++ans;
        }
    }
    dp[0] = s[0];
    int mx = dp[0];
    for(int i = 1; i < n; ++i){
        dp[i] = std::max(dp[i - 1], 0) + s[i];
        mx = std::max(dp[i], mx);
    }
    printf("%d\n", ans + mx);
    return 0;
}
