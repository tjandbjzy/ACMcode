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
const int MAXN = 1000000 + 100;
int a[MAXN];

int cal(int l, int r, int k){
    int i = l, j = r;
    while(i < j){
        while(a[j] > a[l]){
            --j;
        } 
        while(a[i] < a[l]){
            ++i;
        }
        std::swap(a[i], a[j]);
    }
    a[i] = a[l];
    if(i == k){
        return a[k];
    }else if(i > k){
        return cal(l, i, k);
    }else{
        return cal(i + 1, r, i - k + 1);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }
    int ans;
    if(k > n){
        ans = -1;
    }else{
        ans = cal(1, n, k);
    }
    printf("%d\n", ans);
    
    return 0;
}
