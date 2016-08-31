#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 1000 + 10;
char s[MAXN][MAXN];
int r[MAXN], c[MAXN];
int n, m, cnt;

inline bool cal(int x, int y){
    int sum = 0;
    sum += r[x];
    sum += c[y];
    if(s[x][y] == '*'){
        --sum;
    }
    return sum == cnt;
}

int main(){
    //freopen("B.in", "r", stdin);
    while(~scanf("%d %d", &n, &m)){
        for(int i = 0; i < n; ++i){
            scanf("%s", s[i]);
        }
        cnt = 0;
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(s[i][j] == '*'){
                    ++cnt;
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int x = 1, y = 1;
        bool flag = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                flag = cal(i, j);
                if(flag){
                    x = i + 1;
                    y = j + 1;
                    break;
                }
            }
            if(flag){
                break;
            }
        } 
        if(flag || !cnt){
            printf("YES\n%d %d\n", x, y);
        }else{
            puts("NO");
        }
    }
    
    return 0;
}
