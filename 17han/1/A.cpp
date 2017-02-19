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
const int MAXN = 100 + 5;

struct node{
    double x, y;
    bool operator <(const node &a) const{
        return atan2(y, x) < atan2(a.y, a.x);
    }
};

node s[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n) && n >= 0){
        for(int i = 0; i < n; ++i){
            scanf("%lf %lf", &s[i].x, &s[i].y);
        }
        std::sort(s, s + n);
        for(int i = 0; i < n; ++i){
            printf(i == n - 1 ? "%.1f %.1f\n" : "%.1f %.1f ", s[i].x, s[i].y);
        }
    }
    
    return 0;
}
