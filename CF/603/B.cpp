#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const ll MOD = 1000000007;

ll pow(ll a, ll b){
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
    freopen("B.in", "r", stdin);
    ll p, k;
    while(std::cin >> p >> k){
        ll ans = 0;
        if(k == 0){
            ans = pow(p, p - 1);
        }else if(k == 1){
            ans = pow(p, p);
        }else{

        }
        std::cout << ans << std::endl;
    }
    
    return 0;
}
