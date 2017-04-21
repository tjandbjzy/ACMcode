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
        for(int i = 0; i < n; ++i){
            int j = 1;
            while(a[j + i] > a[i] && j + i < n){
                j++;
            }
            while(a[j + i] < a[i] && j + i < n){
                j++;
            }
            if(j > mx){
                mx = j;
                ax = i;
                ay = i + j;
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
