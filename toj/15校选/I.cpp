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
    int n;
    while(~scanf("%d", &n) && n){
        int x, a = 0, b = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            if(x & 1){
                ++a;
            }else{
                ++b;
            }
        }
        if(n & 1 && a > b){
            puts("Justice will prevail over evil.");
        }else if(!(n & 1) && a < b){
            puts("While the priest climbs a post, the devil climbs ten.");
        }else{
            puts("I love this world.");
        }
    }
    return 0;
}
