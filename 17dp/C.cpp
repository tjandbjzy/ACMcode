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
const int MAXN = 1000 + 10;
int dp[MAXN];
int a[MAXN];


int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i < n; ++i){
            int mx = 0;
            for(int j = 0; j < i; ++j){
                if(a[j] < a[i]){
                    mx = std::max(mx, dp[j]);
                }
            }
            dp[i] = mx + 1;
        }
        int ans = -1;
        for(int i = 0; i < n; ++i){
            ans = std::max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
