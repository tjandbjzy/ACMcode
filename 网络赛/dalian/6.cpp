#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 100;
int b[MAXN];

int main(){
    int m;
    while(~scanf("%d", &m)){
        while(m--){
            int n, sum = 0;
            bool f = true;
            scanf("%d", &n);
            for(int i = 0; i < n; ++i){
                scanf("%d", b + i);
                sum += b[i];
                if(b[i] > 2 * n - 2){
                    f = false;
                }
            }
            if(!f || sum != n * (n - 1)){
                puts("F");
            }else{
                puts("T");
            }
        }
    }
    
    return 0;
}
