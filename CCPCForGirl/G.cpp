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
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int q, k;
        scanf("%d %d", &q, &k);
        ++k;
        while(q--){
            int n, m;
            scanf("%d %d", &n, &m);
            if(n > m){
                std::swap(n, m);
            }
            if(!(n % k)){
                puts("Alice");
                continue;
            }
            int s = n / k;
            if(k > 2 && s & 1){
                puts((n + m) & 1 ? "Bob" : "Alice");
            }else{
                puts((n + m) & 1 ? "Alice" : "Bob");
            }
        }
    }
    return 0;
}
