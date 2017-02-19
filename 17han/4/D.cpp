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

int main(){
    ll n;
    while(~scanf("%lld", &n)){
        if(n <= 2){
            puts("0");
            continue;
        }
        ll a = n >> 1;
        ll sum = (a * (a + 1)) >> 1;
        if(!(n & 1)){
            sum -= 2 * a - 1;
        }
        ll ans = sum * n / 3;
        printf("%lld\n", ans);
    }
    
    return 0;
}
