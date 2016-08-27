#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 100;
const ll INF = 0x3f3f3f3f3f3f3f3f;
//const ll INF = (1LL << 60);
ll dp[MAXN][2];
std::string s[MAXN], rs[MAXN];
int c[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", c + i);
    }
    for(int i = 0; i < n; ++i){
        std::cin >> s[i];
        rs[i] = s[i];
        std::reverse(rs[i].begin(), rs[i].end());
    }
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for(int i = 1; i < n; ++i){
        //dp[i][0] = dp[i][1] = INF;
        if(rs[i] >= s[i - 1]){
            dp[i][1] = std::min(dp[i][1], dp[i - 1][0] + c[i]);
        }
        if(rs[i] >= rs[i - 1]){
            dp[i][1] = std::min(dp[i][1], dp[i - 1][1] + c[i]);
        }
        if(s[i] >= rs[i - 1]){
            dp[i][0] = std::min(dp[i][0], dp[i - 1][1]);
        }
        if(s[i] >= s[i - 1]){
            dp[i][0] = std::min(dp[i][0], dp[i - 1][0]);
        }
    }
    ll ans = std::min(dp[n - 1][0], dp[n - 1][1]);
    if(ans == INF){
        std::cout << "-1" << std::endl;
    }else{
        std::cout << ans << std::endl;
    }
    return 0;
}
