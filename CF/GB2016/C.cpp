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
const int INF = 1 << 30;
const int MAXN = 200000 + 100;
int a[MAXN], b[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    int d = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", a + i, b + i);
    }
    int l = -INF, r = INF;
    for(int i = 0; i < n; ++i){
        if(b[i] == 1){
            l = std::max(1900 - d, l);
        }else{
            r = std::min(1899 - d, r);
        }
        d += a[i];
    }
    if(l > r){
        puts("Impossible");
    }else if(l <= r && r == INF){
        puts("Infinity");
    }else{
        printf("%d\n", r + d);
    }
    return 0;
}
