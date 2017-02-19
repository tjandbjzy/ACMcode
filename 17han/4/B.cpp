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
    int cas;
    scanf("%d", &cas);
    while(cas--){
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll ans = std::abs(b - a);
        printf("%llu\n", ans);
    }
    
    return 0;
}
