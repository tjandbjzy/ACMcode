#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 1000 + 100;
int s[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n, m, a, b;
        scanf("%d %d %d %d", &n, &m, &a, &b);
        n += m;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", s + i);
            sum += s[i];
        }
        if(sum < a + b){
            puts("wash your face");
            continue;
        }
        std::sort(s, s + n);
        int cur = 0;
        sum = 0;
        while(cur < n && sum < b){
            sum += s[cur];
            ++cur;
        }
        sum = 0;
        for(int i = cur; i < n; ++i){
            sum += s[i];
        }
        if(sum >= a){
            puts("wellplay");
        }else{
            puts("wash your face");
        }
    }
    
    return 0;
}
