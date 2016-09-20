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

int main(){
    ll a, b, p;
    while(~scanf("%lld %lld %lld", &a, &b, &p)){
        printf("%lld\n", pow_mod(a, b, p));
    }
    
    return 0;
}
