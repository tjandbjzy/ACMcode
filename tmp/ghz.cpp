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
const int MAXN = 1000 + 100;
char s1[MAXN], s2[MAXN];
int dp[MAXN];

int main(){
    int cas;
    std::cin >> cas;
    while(cas--){
        std::cin >> s1 >> s2;
        int n = strlen(s1);
        int m = strlen(s2);
        for(int i = 0; i <= m; ++i){
            dp[i] = i;
        }
        for(int i = 1; i <= n; ++i){
            int pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= m; ++j){
                int t = dp[j];
                if(s1[i - 1] == s2[j - 1]){
                    std::swap(dp[j], pre);
                    continue;
                }
                int tmp = dp[j];
                dp[j] = std::min(std::min(t, dp[j - 1]), pre) + 1;
                pre = tmp;
            }
        }
        std::cout << dp[m] << std::endl;
    }
    
    return 0;
}
