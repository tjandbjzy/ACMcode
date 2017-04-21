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
const int MAXN = 10000000 + 10;
int a[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
        }
        int ax, ay, mx = -1;
        for(int i = 1; i < n - 1; ++i){
            if(a[i - 1] > a[i] || a[i + 1] > a[i]){
                continue;
            }
            int j = i - 1, k = i + 1;
            while(j >= 0 && a[j] < a[j + 1]){
                j--;
            }
            while(k < n && a[k] < a[k - 1]){
                k++;
            }
            if(mx < k - j + 1){
                mx = k - j + 1;
                ax = j + 1;
                ay = k - 1;
            }
        }
        if(mx == -1){
            puts("-1 -1");
        }else{
            printf("%d %d\n", ax, ay);
        }
    }
    
    return 0;
}
