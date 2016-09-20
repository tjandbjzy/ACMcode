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
const ll MOD = 1000000007;

ll pow_mod(ll a, ll b, ll p){
    ll res = 1LL;
    while(b){
        if(b & 1){
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll cal(ll a, ll b, ll p){
    if(a < b){
        return 0LL;
    }
    if(a == b){
        return 1LL;
    }
    if(b > a - b){
        b = a - b;
    }
    ll res = 1, ta = 1, tb = 1;
    for(ll i = 0; i < b; ++i){
        ta = ta * (a - i) % p;
        tb = tb * (b - i) % p;
    }
    res = ta * pow_mod(tb, p - 2, p) % p;
    return res;
}

ll Lucas(ll n, ll m, ll p){
    ll res = 1LL;
    while(n && m && res){
        res = res * cal(n % p, m % p, p) % p;
        n /= p;
        m /= p;
    }
    return res;
}

int main(){
    ll m, n, k; 
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%lld %lld %lld", &n, &m, &k);
        ll ans = Lucas(2 * n - (k + 1) *m - 1, n - 1, MOD);
        printf("%lld\n", ans);
    }
    return 0;
}
