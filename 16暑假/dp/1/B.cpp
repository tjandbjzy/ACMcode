#include <cstdio>

const int MAXN = 60;
typedef long long ll;

ll dp[MAXN];

int main(){
    //freopen("B.in", "r", stdin);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for(int i = 5; i < MAXN; ++i){
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    int n;
    while(~scanf("%d", &n) && n){
        printf("%lld\n", dp[n]); 
    }
    return 0;
}
