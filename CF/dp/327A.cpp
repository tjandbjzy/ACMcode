#include <cstdio>
#include <algorithm>

const int MAXN = 100 + 10;
int s[MAXN], dp[MAXN];

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if(x){
            ++ans;
            s[i] = -1;
        }else{
            s[i] = 1;
        }
    }
    dp[0] = s[0];
    for(int i = 1; i < n; ++i){
        dp[i] = std::max(dp[i - 1], 0) + s[i];
    }
    printf("%d\n", ans + dp[n - 1]);
    return 0;
}
