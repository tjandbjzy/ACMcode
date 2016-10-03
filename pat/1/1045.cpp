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
const int MAXN = 100000 + 10;
int s[MAXN];
int a[MAXN];
int ans[MAXN];
int n;

bool judge(int pos){
    if(pos > n - pos){
        for(int i = pos + 1; i < n; ++i){
            if(s[i] < s[pos]){
                return false;
            }
        }
    }else{
        for(int i = pos - 1; i >= 0; --i){
            if(s[i] > s[pos]){
                return false;
            }
        }
    }
    return true;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", s + i);
        a[i] = s[i];
    }
    std::sort(a, a + n);
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == s[i] && judge(i)){
            ans[cnt++] = a[i];
        }
    }
    printf("%d\n", cnt);
    if(cnt == 0){
        puts("");
        return 0;
    }
    for(int i = 0; i < cnt; ++i){
        printf(i == cnt - 1 ? "%d\n" : "%d ", ans[i]);
    }
    
    return 0;
}
