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
#include <iomanip>
#include <ctime>

typedef long long ll;
const int MAXN = 200000 + 100;
const double PI = acos(-1.0);
const double ANSPI = PI * PI / 6.0;
std::string s;
double ans[MAXN];

int main(){
    std::ios::sync_with_stdio(false);
    ans[0] = 0.0;
    ans[1] = 1.0;
    for(int i = 2; i <= 120000; ++i){
        ans[i] = ans[i - 1] + 1.0 / (1.0 * i) * 1.0 / (1.0 * i);
    }
    while(std::cin >> s){
        if(s.size() > 6){
            std::cout << std::setprecision(5) << std::fixed << ANSPI << "\n";
            //printf("%.5f\n", ANSPI);
            continue;
        }
        int n = 0;
        for(int i = 0; i < s.size(); ++i){
            n = n * 10 + s[i] - '0';
        }
        if(n < 120000){
            std::cout << std::setprecision(5) << std::fixed << ans[n] << "\n";
            //printf("%.5f\n", ans[n]);
        }else{
            //printf("%.5f\n", ANSPI);
            std::cout << std::setprecision(5) << std::fixed << ANSPI << "\n";
        }
    }
   
    return 0;
}

