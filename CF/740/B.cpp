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
const int MAXN = 1000 + 100;
int s[MAXN], sum[MAXN];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", s + i);
        sum[i] = sum[i - 1] + s[i];
    }
    int ans = 0;
    for(int i = 0; i < m; ++i){
        int l, r;
        scanf("%d %d", &l, &r);
        int res = sum[r] - sum[l - 1];
        if(res > 0){
            ans += res;
        }
    }
    printf("%d\n", ans);

    
    
    return 0;
}
