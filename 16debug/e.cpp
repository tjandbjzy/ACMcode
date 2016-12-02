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
const int MAXN = 500 + 10;
int x[MAXN], y[MAXN];

double dis(int i, int j){
    double d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(d);
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d %d",  x + i, y + i);
        }
        double mx = 0, mi = 1000000.0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j){
                    continue;
                }
                mx = std::max(dis(i, j), mx);
                mi = std::min(dis(i, j), mi);
            }
        }
        printf("%.3lf %.3lf\n", mx, mi);
    }
    
    return 0;
}
