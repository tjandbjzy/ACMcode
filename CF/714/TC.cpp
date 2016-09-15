#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
std::map<ll, int> m;
int a[20], b[20];

int main(){
    std::ios::sync_with_stdio(false);
    freopen("C.in", "r", stdin);
    int n;
    std::cin >> n;
    while(n--){
        ll x;
        char s;
        std::cin >> s >> x;
        if(s == '+'){
            ++m[x];
        }else if(s == '-'){
            --m[x];
        }else{
            int ans = 0, l1 = 0, l2 = 0;
            ll t = x, f, s;
            while(t){
                a[l1++] = t & 1;
                t >>= 1;
            }
            for(std::map<ll, int>::iterator it = m.begin(); it != m.end(); ++it){
                f = it -> first;
                s = it -> second;
                l2 = 0;
                while(f){
                    b[l2++] = (f % 10) & 1;
                    f /= 10;
                }
                if(l2 == l1){
                    bool flag = true;
                    for(int i = 0; i < l2; ++i){
                        if(a[i] != b[i]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        ans += s;
                    }
                }
            }
            std::cout << ans << std::endl;
        }
    }

    
    return 0;
}
