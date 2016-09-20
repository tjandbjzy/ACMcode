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

int cal(int a, int b, int p){
    if(a < b){
        return 0;
    }
    if(a == b){
        return 1;
    }
    if(b > a - b){
        b = a - b;
    }
    int res = 1, ta = 1, tb = 1;
    for(int i = 0; i < b; ++i){
        ta = ta * (a - i) % p;
        tb = tb * (b - i) % p;
    }
    res = ta * pow_mod(tb, p - 2, p) % p;
    return res;
}

int Lucas(int n, int m, int p){
    int res = 1;
    while(n && m && res){
        res = res * cal(n % p, m % p, p) % p;
        n /= p;
        m /= p;
    }
    return res;
}

int main(){
    int m, n, k; 
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d %d %d", &n, &m, &k);
        if(m == 0 || n == m * k + m){
            puts("1");
            continue;
        }
        if(m == 1){
            printf("%d\n", n);
            continue;
        }
        if(n < m * k + m){
            puts("0");
            continue;
        }
        int ans = Lucas(2 * n - (k + 1) *m - 1, n - 1, MOD);
        printf("%d\n", ans);
    }
    return 0;
}
