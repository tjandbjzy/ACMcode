#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;

int main(){
    int n, m;
    char t;
    bool flag = true;
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            std::cin >> t;
            if(t == 'C' || t == 'M' || t == 'Y'){
                flag = false;
            }
        }
    }
    if(!flag){
        std::cout << "#Color\n";
    }else{
        std::cout << "#Black&White\n";
    }
    return 0;
}
