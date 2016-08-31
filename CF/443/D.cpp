#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 1000 + 100;
double s[MAXN];

bool cmp(const double &a, const double &b){
    return a > b;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%lf", s + i);
    }
    std::sort(s, s + n, cmp);
    double ans = 0, t, tmp;
    for(int i = 1; i <= n; ++i){
        t = 0;
        for(int j = 0; j < i; ++j){
            tmp = s[j];
            for(int k = 0; k < i; ++k){
                if(k == j){
                    continue;
                }
                tmp *= (1.0 - s[k]);
            }
            t += tmp;
        }
        ans = std::max(ans, t);
    }
    printf("%.12f\n", ans);
    return 0;
}
