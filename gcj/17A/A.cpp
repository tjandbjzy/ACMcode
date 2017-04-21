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
const int MOD = 1000000007;

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("AA.out", "w", stdout);
    int cas, k = 0;
    scanf("%d", &cas);
    while(cas--){
        ll m, n;
        scanf("%lld %lld", &m, &n);
        m--;
        n--;
        if(m > n){
            std::swap(m, n);
        }
        ll ans = m * n;
        for(int i = 1; i <= m - 1; ++i){
            ans = (ans + (m - i) * (n - i)) % MOD;
            ans = (ans + (m - i) * (n - i) * i) % MOD;
        }
        printf("Case #%d: %lld\n", ++k, ans);
    }
    
    return 0;
}
