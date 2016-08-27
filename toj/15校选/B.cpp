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
        int n;
        scanf("%d", &n);
        int ans = log(n) / log(2);
        //printf("%d\n", ans);
        if((int)pow(2.0, ans) == n){
            printf("%d\n", ans);
        }else{
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}
