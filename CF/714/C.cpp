#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
std::map<ll, int> m;

int main(){
    //freopen("C.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    while(n--){
        ll x;
        char s;
        std::cin >> s >> x;
        ll temp = x, a = 0, b = 0;
        while(temp){
            if((temp % 10) & 1){
                a |= 1 << b;
            }
            temp /= 10;
            ++b;
        }
        if(s == '+'){
            ++m[a];
        }else if(s == '-'){
            --m[a];
        }else{
            std::cout << m[a] << std::endl;
        }
    }
    
    return 0;
}
