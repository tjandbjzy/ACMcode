#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 100;
int a[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    std::sort(a, a + n);
    int q;
    scanf("%d", &q);
    int x;
    while(q--){
        scanf("%d", &x);
        printf("%ld\n", std::upper_bound(a, a + n, x) - a);
    }
    return 0;
}
