#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 500000 + 100;
ll s[MAXN];

int main(){
    int n;
    ll sum = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> s[i]; 
        sum += s[i];
    }
    if(sum % 3){
        puts("0");
    }else{
        if(n == 1 || n == 2){
            puts("0");
        }else{
            ll s1 = sum / 3, s2 = sum / 3 * 2;
            ll ans = 0;
            if(sum){
                ll a = 0, ans = 0, cnt = 0;
                for(int i = 0; i < n; ++i){
                    a += s[i];
                    if(a == s1){
                        ++cnt;
                    }
                    if(a == s2){
                        ans += cnt;
                    }
                }
                std::cout << ans << std::endl;
            }else{
                ll ans = s[0] == 0 ? 1 : 0;
                for(int i = 1; i < n; ++i){
                    s[i] += s[i - 1];
                    if(s[i] == 0){
                        ++ans;
                    }
                }
                std::cout << (ans - 1) * (ans - 2) / 2 << std::endl;
            }
        }
    }

    return 0;
}
