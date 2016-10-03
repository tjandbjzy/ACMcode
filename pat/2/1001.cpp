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
const int MAXN = 100;
ll a[MAXN];

int main(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    ll c = x + y;
    if(c < 0){
        putchar('-');
        c = -c;
    }
    if(c >= 1000000){
        printf("%lld,%03lld,%03lld\n", c / 1000000, c / 1000 % 1000, c % 1000);
    }else if(c >= 1000){
        printf("%lld,%03lld\n", c / 1000, c % 1000);
    }else{
        printf("%lld\n", c);
    }
    return 0;
}
