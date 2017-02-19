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
    int x[6];
    while(true){
        for(int i = 0; i < 6; ++i){
            std::cin >> x[i];
        }
        std::sort(x, x + 6);
        int ans = 0;
        for(int i = 0; i < 6; ++i){
            ans += x[i];
        }
        if(ans == 0){
            break;
        }
        ans = ans - x[0] - x[5];
        if(ans % 4 == 0){
            std::cout << ans / 4 << std::endl;
            continue;
        }
        printf("%g\n", 1.0 * ans / 4.0);
    }
    
    return 0;
}
