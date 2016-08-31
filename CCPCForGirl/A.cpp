#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 11;
struct node{
    char s[MAXN];
    int c;
    friend bool operator < (node a, node b){
        return a.c > b.c;
    }
};

node a[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s %d", a[i].s, &a[i].c);
        }
        std::sort(a, a + n);
        for(int i = 0; i < n; ++i){
            printf(i == n - 1 ? "%s\n" : "%s ", a[i].s);
        }
    }
    
    return 0;
}
