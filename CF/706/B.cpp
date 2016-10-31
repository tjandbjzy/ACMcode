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
const int MAXN = 100000 + 100;
int s[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", s + i);
    }
    std::sort(s, s + n);
    int q, m, ans;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &m);
        ans = std::upper_bound(s, s + n, m) - s;
        printf("%d\n", ans);
    }
    
    return 0;
}
