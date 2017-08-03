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
const int MAXN = 2e5 + 10;
ll dp[MAXN];

int main(){
    int n, c;
    ll t;
    while(~scanf("%d %lld %d", &n, &t, &c)){
        dp[0] = 0LL;
        for(int i = 1; i <= n; ++i){
            scanf("%lld", dp + i);
        }
        ll sum = 0;
        int cnt = 0;
        for(int i = 0; i <= c; ++i){
            sum += dp[i];
        }
        if(sum <= t){
            cnt++;
        }
        sum = 0;
        for(int i = 1; i <= n; ++i){
            if(i < c){
                sum += dp[i];
            }else{
                sum += dp[i];
                sum -= dp[i - c - 1];
                if(sum <= t){
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    
    return 0;
}
