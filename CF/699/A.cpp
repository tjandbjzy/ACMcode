#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 200000 + 100;
int s[MAXN];
char t[MAXN];

int main(){
    //freopen("A.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        scanf("%s", t);
        for(int i = 0; i < n; ++i){
            scanf("%d", s + i);
        }
        int ans = 1 << 30;
        if(t[0] == 'R' && t[1] == 'L'){
            ans = std::min(ans, s[1] - s[0]);
        }
        if(t[n - 2] == 'R' && t[n - 1] == 'L'){
            ans = std::min(ans, s[n - 1] - s[n - 2]);
        }
        for(int i = 1; i < n - 1; ++i){
            if(t[i] == 'L' && t[i - 1] == 'R'){
                ans = std::min(s[i] - s[i - 1], ans);
            }
            if(t[i] == 'R' && t[i + 1] == 'L'){
                ans = std::min(s[i + 1] - s[i], ans);
            }
        }
        if(ans == (1 << 30)){
            ans = -1;
        }else{
            ans >>= 1;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
