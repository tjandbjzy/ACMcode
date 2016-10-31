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
const int MAXN = 10000 + 10;
struct node{
    double x, y, v;
};
node s[MAXN];

int main(){
    double ax, ay;
    int n;
    scanf("%lf %lf %d", &ax, &ay, &n);
    for(int i = 0; i < n; ++i){
        scanf("%lf %lf %lf", &s[i].x, &s[i].y, &s[i].v);
    }
    double ans = 999999999999, d, t;
    for(int i = 0; i < n; ++i){
        d = sqrt((s[i].x - ax) * (s[i].x - ax) + (s[i].y - ay) * (s[i].y - ay));
        t = d / s[i].v;
        ans = std::min(t, ans);
    }
    printf("%.8f\n", ans);
    return 0;
}
