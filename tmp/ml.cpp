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
const int MAXN = 100000000;
double a[MAXN];

int main(){
    int n = 10000000;
    a[1] = 1;
    for(int i = 2; i < n; ++i){
        a[i] = sin(a[i - 1]);
    }
    double ans = log(a[n - 2]) - log(a[n - 1]);
    ans = ans /(a[n - 1] * a[n - 2]);
    printf("%f\n", ans);
    
    return 0;
}
