#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 3000 + 100;
char s[MAXN];

int main(){
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int len = strlen(s);
    for(int i = 0; i < k; ++i){
        s[len + i] = '#';
    }
    len += k;
    int ans = 0;
    bool flag;
    for(int i = 0; i < len; ++i){
        for(int j = 1; i + 2 * j <= len; ++j){
            flag = true;
            for(int m = i; m < i + j; ++m){
                if(s[m] != s[m + j] && s[m + j] != '#'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = std::max(ans, j << 1);
            }

        }
    }
    printf("%d\n", ans);
    return 0;
}
