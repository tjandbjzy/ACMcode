#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>


const int N = 1000 + 10;
int a[N];

int main(){
    int n;
    while(std::cin >> n){
        for(int i = 0; i < n; ++i){
            std::cin >> a[i];
        }
        std::sort(a, a + n);
        if(n == 1){
            puts("2");
        }else if(n == 2){
            if(a[1] - a[0] <= 10){
                puts("1");
            }else{
                puts("4");
            }
        }else{
            int ans = 0, i;
            for(i = 0; i < n - 2;){
                if(a[i + 1] - a[i] > 10){
                    ans += 2;
                    i++;
                }else if(a[i + 2] - a[i + 1] > 10){
                    ans += 1;
                    i += 2;
                }else{
                    i += 3;
                }
            }
            if(n - i == 1){
                ans += 2;
            }else if(n - i == 2){
                if(a[n - 1] - a[n - 2] <= 10){
                    ans += 1;
                }else{
                    ans += 4;
                }
            }
            std::cout << ans << std::endl;
        }
    }

    return 0;
}
