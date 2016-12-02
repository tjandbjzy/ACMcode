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
    ll a, b, c, n;
    std::cin >> n >> a >> b >> c;
    //scanf("%d %d %d %d", &n, &a, &b, &c);
    if(n % 4 == 0){
        puts("0");
    }else{
        ll d = 4 - n % 4, ans;
        if(d == 1){
            ans = std::min(a, b + c);
            ans = std::min(ans, 3 * c);
            std::cout << ans << std::endl;
        }else if(d == 2){
            ans = std::min(2 * a, b);
            ans = std::min(ans, 2 * c);
            std::cout << ans << std::endl;
        }else{
            ans = std::min(3 * a, a + b);
            ans = std::min(ans, c);
            std::cout << ans << std::endl;
        }
    }
    
    return 0;
}
