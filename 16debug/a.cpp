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
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        int a, b, c, x;
        a = b = c = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            if(x >= 60){
                ++a;
            }
            if(x >= 85){
                ++b;
            }
            c += x;
        }
        c /= n;
        printf("%d %d %d\n", a, b, c);
    }
    
    return 0;
}
