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
    if(n < 3){
        return 0;
    }else if(n > 6){
        return 5 * n;
    }else if(n == 3){
        return 1;
    }else if(n == 4){
        return 8;
    }else if(n == 5){
        return 35;
    }else if(n == 6){
        return 32;
    }
}

int main(){
    int cas, k = 0;;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", ++k, cal(n));
    }

    return 0;
}
