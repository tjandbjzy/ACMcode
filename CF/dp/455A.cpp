#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 100000 + 10;
int h[MAXN];
ll dp[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    int ma = -1;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        ++h[x];
        ma = std::max(ma, x);
    }
    memset(dp, 0, sizeof(dp));
    dp[1] = h[1];
    for(int i = 2; i <= ma; ++i){
        dp[i] = std::max(dp[i - 1], dp[i - 2] + 1LL * h[i] * i);//可能会爆int
    }
    std::cout << dp[ma] << std::endl;
    return 0;
}
