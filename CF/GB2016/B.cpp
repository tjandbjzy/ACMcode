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
    //freopen("B.in", "r", stdin);
    int n, x;
    std::string s;
    std::cin >> n;
    bool flag = true;
    int pos = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> x >> s;
        if(s == "West" || s == "East"){
            std::cout << s << "\n";
            if(pos == 0 || pos == 20000){
                flag = false;
                std::cout << "2\n";
                break;
            }
        }
        if(s == "South"){
            pos += x;
        }else if(s == "North"){
            pos -= x;
        }
        if(pos < 0 || pos > 20000){
            flag = false;
            std::cout << "1\n";
            break;
        }
        
    }
    if(flag && pos == 0){
        std::cout << "YES\n";
    }else{
        std::cout << "NO\n";
    }
    return 0;
}
