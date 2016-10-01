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
const int MAXN = 2000 + 10;

int f[MAXN];
char s[MAXN][MAXN];

void getFail(char* p, int* f){
    int m = strlen(p);
    f[0] = f[1] = 0;
    for(int i = 1; i < m; ++i){
        int j = f[i];
        while(j && p[i] != p[j]){
            j = f[j];
        }
        f[i + 1] = p[i] == p[j] ? j + 1 : 0;
    }
    return;
}

bool Find(char* t, char* p, int* f){
    int n = strlen(t), m = strlen(p);
    getFail(p, f);
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(j && p[j] != t[i]){
            j = f[j];
        }
        if(p[j] == t[i]){
            ++j;
        }
        if(j == m){
            return true;
        }
    }
    return false;
}

int main(){
    int cas, t = 1;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%s", s[i]);
        }
        int low = 1, ans = -1;
        for(int i = 2; i <= n; ++i){
            while(low < i){
                if(Find(s[i], s[low], f)){
                    ++low;
                }else{
                    ans = i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", t++, ans);
    }
    
    return 0;
}
