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

int gcd(int a, int b){
    return b == 0 ? a :gcd(b, a % b);
}

int main(){
    //freopen("1.in", "r", stdin);
    int cas, t = 1;
    scanf("%d", &cas);
    while(cas--){
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        int ans = n / gcd(a, b) - 2;
        printf("Case #%d: ", t++);
        if(ans & 1){
            puts("Yuwgna");
        }else{
            puts("Iaka");
        }
    }
    return 0;
}
