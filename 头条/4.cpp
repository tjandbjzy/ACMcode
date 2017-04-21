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
const int N = 100000 + 10;

struct node{
    int x, y;
};

node a[N];

bool cmp(const node &a, const node &b){
    if(a.y == b.y){
        return a.x > b.x;
    }
    return a.y < b.y;
}

int main(){
    int n, q;
    while(~scanf("%d %d", &n, &q)){
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i].x);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i].y);
        }
        std::sort(a, a + n, cmp);
        while(q--){
            int qa, qb;
            scanf("%d %d", &qa, &qb);
            int ans = 0, i = n - 1;
            while(!(a[i].x >= qa && a[i].y >= qb) && i >= 0){
                i--;
            }
            while(a[i].x >= qa && a[i].y >= qb && i >= 0){
                i--;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
