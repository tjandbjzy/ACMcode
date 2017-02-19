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

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
    int n, a;
    while(~scanf("%d %d", &n, &a)){
        if(n == 0 && a == 0){
            break;
        }
        ll ans = 1;
        for(int i = 0; i < n; ++i){
            int m;
            scanf("%d", &m);
            ans = lcm(ans, m);
        }
        printf("%lld\n", ans - a);
    }

    return 0;
}
