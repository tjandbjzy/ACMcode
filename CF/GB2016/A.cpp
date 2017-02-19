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

int main(){
    int n, k;
    while(~scanf("%d %d", &n, &k)){
        int sum = k, cnt = 0;
        for(int i = 1; i <= n && sum <= 240; ++i){
            if(sum + 5 * i <= 240){
                sum += 5 * i;
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
