#include <cstdio>

typedef long long ll;
const int MAXN = 60;
ll dp[MAXN];

int main(){
    //freopen("C.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int a, b;
        scanf("%d %d", &a, &b);
        dp[a + 1] = 1;
        dp[a + 2] = 2;
        for(int i = a + 3; i <= b; ++i){
            dp[i] = dp[i - 1] + dp[i - 2]; 
        }
        printf("%lld\n", dp[b]);
    }
    return 0;
}
