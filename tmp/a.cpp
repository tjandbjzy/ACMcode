#include <cstdio>
#include <iostream>

int cnt;
int a[1000];

bool ok(int n){
    int ans = 0, t = n, x;
    while(t){
        x = t % 10;
        ans += x * x * x;
        t /= 10;
    }
    return ans == n;
}

int main(){
    int n, m;
    while(std::cin >> m >> n){
        cnt = 0;
        for(int i = m; i <= n; ++i){
            if(ok(i)){
                a[cnt++] = i;
            }
        }
        if(cnt == 0){
            std::cout << "no" << std::endl;
        }else{
            for(int i = 0; i < cnt; ++i){
                std::cout << a[i];
                if(i == cnt - 1){
                    std::cout << "\n";
                }else{
                    std::cout << " ";
                }
            }
        }
    }


    return 0;
}
