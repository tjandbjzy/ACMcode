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
const int MAXN = 500 + 100;
int a[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n) && n){
        int sum = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
            sum += a[i];
        }
        double ave = (1.0 * sum) / (1.0 * n);
        double ans = 0;
        for(int i = 0; i < n; ++i){
            ans += (a[i] - ave) * (a[i] - ave);
        }
        ans /= 1.0 * n;
        printf("%.2f\n", ans);
    }
    
    return 0;
}
