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
const int MAXN = 1000 + 100;
int ans[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n, cnt = 0;
        scanf("%d", &n);
        if(n % 6 != 2 && n % 6 != 3){
            for(int i = 1; i <= n; ++i){
                if(!(i & 1)){
                    ans[++cnt] = i;
                }
            }
            for(int i = 1; i <= n; ++i){
                if(i & 1){
                    ans[++cnt] = i;
                }
            }
        }else if(n % 6 == 2){
            int s = n >> 1;
            for(int i = s; i <= n; i += 2){
                ans[++cnt] = i;
            }
            for(int i = s & 1 ? 1 : 2; i <= s - 2; i += 2){
                ans[++cnt] = i;
            }
            for(int i = s + 3; i <= n; i += 2){
                ans[++cnt] = i;
            }
            for(int i = s & 1 ? 2 : 1; i <= s + 1; i += 2){
                ans[++cnt] = i;
            }
        }else{
            int s = n >> 1;
            for(int i = s; i < n; i += 2){
                ans[++cnt] = i;
            }
            for(int i = s & 1 ? 1 : 2; i <= s - 2; i += 2){
                ans[++cnt] = i;
            }
            for(int i = s + 3; i < n; i += 2){
                ans[++cnt] = i;
            }
            for(int i = s & 1 ? 2 : 1; i <= s + 1; i += 2){
                ans[++cnt] = i;
            }
            ans[++cnt] = n;
        }
        printf("%d\n", n);
        for(int i = 1; i <= n; ++i){
            printf(" %d", ans[i] - 1);
        }
        puts("");

    }
    
    return 0;
}
