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

ll powmod(ll a, ll b, ll mod){
    ll res = 1LL;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ll m, n;
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%lld %lld", &m, &n);
        m--;
        n--;
        if(m > n){
            std::swap(m, n);
        }
        ll ans = 3 * m * m % MOD;
        ans = ans + 20 * n + 7 * m - 2;
        ans = (ans - 10 * m * n + MOD) % MOD;
        ans = ans * m % MOD * (m - 1) % MOD;
        ans = ans * powmod(12, MOD, MOD - 2);
        printf("%lld\n", ans);
    }
    
    return 0;
}
