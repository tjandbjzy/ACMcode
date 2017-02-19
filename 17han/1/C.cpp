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

int cal(int n){
    int ans = n;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            n /= i;
            ans = ans - ans / i;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n != 1){
        ans = ans - ans / n;
    }
    return ans;
}

int main(){
    int n;
    while(~scanf("%d", &n) && n){
        printf("%d\n", n - 1 - cal(n)); 
    }
    return 0;
}
