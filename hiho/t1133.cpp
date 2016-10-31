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
const int MAXN = 1e6 + 10;
int a[MAXN];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }
    if(k > n){
        puts("-1");
        return 0;
    }
    std::sort(a + 1, a + 1 + n);
    printf("%d\n", a[k]);

    
    return 0;
}
