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
    int cas, t = 0;
    scanf("%d", &cas);
    while(cas--){
        int v, v1, s1, v2, s2;
        scanf("%d %d %d %d %d", &v, &s1, &v1, &s2, &v2);
        if(v < v1 && v < v2){
            printf("Case #%d: 0\n", ++t);
            continue;
        }
        double d1 = (1.0 * v) / (1.0 * v1);
        double d2 = (1.0 * v) / (1.0 * v2);
        int ans = 0, n;
        int x, y;
        if(d1 < d2){
            for(int i = 0; i * v1 <= v; ++i){
                n = (v - i * v1) / v2;
                if(ans < i * s1 + n * s2){
                    ans = i * s1 + n * s2;
                    x = i;
                    y = n;
                }
                //ans = std::max(ans, i * s1 + n * s2);
            }
        }else{
            for(int i = 0; i * v2 <= v; ++i){
                n = (v - i * v2) / v1;
                if(ans < i * s2 + n * s1){
                    ans = i * s2 + n * s1;
                    x = n;
                    y = i;
                }
                //ans = std::max(ans, i * s2 + n * s1);
            }
        }
        printf("Case #%d: %d\n%d %d\n", ++t, ans, x, y);
    }
    
    return 0;
}
