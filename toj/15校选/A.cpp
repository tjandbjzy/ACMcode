#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;

int cal(int n){
    int res = 1, a, b;
    while(true){
        a = res * (res - 1) / 2;
        b = (res + 1) * res / 2;
        if(n > a && n <= b){
            return res;
        }
        ++res;
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        int ans = cal(n);
        printf("%d\n", ans);
    }
    return 0;
}
