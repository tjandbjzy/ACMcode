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
struct mat{
    ll a[3][3];
    void init(){
        memset(a, 0, sizeof(a));
    }
};

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

ll e(ll n){
    ll res = n, a = n;
    for(int i = 2; i * i <= a; ++i){
        if(a % i == 0){
            res = res / i * (i - 1);
            while(a % i == 0){
                a /= i;
            }
        }
    }
    if(a > 1){
        res = res / a * (a - 1);
    }
    return res;
}

mat mul(mat x, mat y, ll p){
    mat tmp;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            tmp.a[i][j] = 0;
            for(int k = 0; k < 3; ++k){
                tmp.a[i][j] = (tmp.a[i][j] + x.a[i][k] * y.a[k][j] % p + p) % p;
            }
        }
    }
    return tmp;
}

mat pow_mat(mat m, ll b, ll p){
    mat res;
    res.init();
    res.a[0][0] = res.a[1][1] = res.a[2][2] = 1;
    while(b){
        if(b & 1){
            res = mul(res, m, p);
        }
        m = mul(m, m, p);
        b >>= 1;
    }
    return res;
}

ll cal(ll n, ll p){
    if(n == 1 || n == 0){
        return n;
    }
    mat m;
    m.init();
    m.a[0][0] = 5; m.a[0][1] = 5; m.a[0][2] = -1;
    m.a[1][0] = 1; m.a[2][1] = 1;
    m = pow_mat(m, n - 2, p);
    return m.a[0][0] * 5 + m.a[0][1];
}

int main(){
    //freopen("4.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        ll n, y, x, s;
        scanf("%lld %lld %lld %lld", &n, &y, &x, &s);
        ++s;
        n *= y;
        //printf("%lld\n", n);
        n = cal(n, e(s));
        //printf("%lld\n", n);
        printf("%lld\n", pow_mod(x, n, s));
    }
    
    return 0;
}
