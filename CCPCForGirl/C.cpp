#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100 + 10;
int h[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        memset(h, 0, sizeof(h));
        int sum = 0, x;
        for(int i = 0; i < n - 1; ++i){
            scanf("%d", &x);
            sum += x;
            ++h[x];
        }
        int ans = 2 * sum / (3 * n - 2);
        printf("%d %.2f\n", ans, 1.0 / (h[ans] + 1));
    }
    
    return 0;
}
