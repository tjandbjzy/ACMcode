#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
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
    std::string s;
    while(std::cin >> s && s != "0"){
        int tmp = 0;
        for(int i = 0; i < s.size(); ++i){
            tmp += s[i] - '0';
        }
        int ans = tmp;
        while(tmp > 9){
            ans = 0;
            while(tmp){
                ans += tmp % 10;
                tmp /= 10;
            }
            tmp = ans;
        }
        std::cout << ans << std::endl;
    }


    
    return 0;
}
