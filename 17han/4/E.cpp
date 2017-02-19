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
int s;

inline bool judge(ll n){
    int res = 0;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res == s;
}
int main(){
    ll a, b;
    while(~scanf("%lld %lld %d", &a, &b, &s)){
        ll ans = a;
        while(ans <= b && !judge(ans)){
            ans++;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
