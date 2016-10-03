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

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n != 1){
        ++ans;
        if(n & 1){
            n = 3 * n + 1;
        }
        n >>= 1;
    }
    printf("%d\n", ans);
    
    return 0;
}
