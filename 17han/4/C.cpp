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
const int MAXN = 100 + 10;
double s[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n)){
        double x, sum = 0;
        for(int i = 0; i < n; ++i){
            scanf("%lf", &x);
            sum += 1.0 / x;
        }
        double ans;
        scanf("%lf", &ans);
        ans /= sum;
        printf("%.2f\n", ans);
    }
    
    return 0;
}
