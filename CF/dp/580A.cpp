#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100000 + 10;
int dp[MAXN];
int a[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        dp[i] = a[i] >= a[i - 1] ? dp[i - 1] + 1 : 1;
    }
    int ans = -1;
    for(int i = 0; i < n; ++i){
        //printf("%d ", dp[i]);
        ans = std::max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
