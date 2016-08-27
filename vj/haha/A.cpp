#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;

int main(){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    double ans = (double)(1e20);
    double x, y, v;
    while(n--){
        scanf("%lf %lf %lf", &x, &y, &v);
        ans = std::min(ans, sqrt(((x - a) * (x - a) + (y - b) * (y - b))) / v);
    }
    printf("%.10f\n", ans);
    return 0;
}
