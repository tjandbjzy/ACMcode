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
const int MAXN = 100000 + 100;
int s[MAXN];
bool a[MAXN];
int ans[MAXN];

int main(){
    int n;
    memset(a, false, sizeof(bool));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", s + i);
    }
    int l = 0, r = 1;
    while(r < n){
        if(s[l] < s[r]){
            ++l;
            ++r;
        }else{
            a[l] = a[r] = true;
            for( ; s[r] < s[l] && r < n; ++r){
                a[r] = true;
            }
            l = r - 1;
        }
    }
    l = n - 2;
    r = n - 1;
    while(l >= 0){
        if(s[l] < s[r]){
            --l;
            --r;
        }else{
            a[r] = a[l] = true;
            for( ; s[l] > s[r] && l >= 0; --l){
                a[l] = true;
            }
            r = l + 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(!a[i]){
            ans[cnt++] = s[i];
        }
    }
    std::sort(ans, ans + cnt);
    printf("%d\n", cnt);
    if(cnt == 0){
        puts("");
    }
    for(int i = 0; i < cnt; ++i){
        printf(i == cnt - 1 ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
