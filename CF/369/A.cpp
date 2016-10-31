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
int s[MAXN];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", s + i);
    }
    int ans = 0, tm = m, tk = k;
    for(int i = 0; i < n; ++i){
        if(s[i] == 2){
            if(tm == 0 && tk == 0){
                ans++;
                tm = m;
                tk = k;
            }else if(tk){
                tk--;
            }else{
                tm--;
            }
        }else{
            if(tm){
                tm--;
            }else{
                ans++;
                tm = m;
                tk = k;
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
