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
char s[MAXN];

int main(){
    int n;
    scanf("%d %s", &n, s);
    int ans = 1, cnt = 0;
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i - 1]){
            ++cnt;
        }else{
            ++ans;
        }
    }
    if(cnt > 2){
        cnt = 2;
    }
    printf("%d\n", ans + cnt);
    
    return 0;
}
