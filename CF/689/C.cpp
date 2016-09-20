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
const ll UpperBound = 1e16;
const ll LowerBound = 0;

ll judge(ll n){
    ll res = 0;
    for(int i = 2; 1LL * i * i * i <= n; ++i){
        res += n / (1LL * i * i * i);
    }
    return res;
}

int main(){
    ll m, ans;
    while(std::cin >> m){
        ll l = LowerBound, r = UpperBound, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(judge(mid) < m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        ll ans = -1;
        if(judge(l) == m){
            ans = l;
        }
        std::cout << ans << std::endl; 
    }
    return 0;
}
