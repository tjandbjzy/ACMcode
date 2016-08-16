#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 10000;
const ll INF = 1e10;
ll s[MAXN];
std::string p[6] = {"", "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(){
    int t = 1;
    s[1] = 5;
    while(s[t] < INF){
        ++t;
        s[t] = s[t - 1] * 2LL;
    }
    int n;
    while(std::cin >> n){
        int cur = 1;
        while(s[cur] < n){
            n -= s[cur]; 
            ++cur;
        }
        int ans;
        int d = (1 << (cur - 1));
        if(n >= 1 && n <= d){
            ans = 1;
        }else if(n > d && n <= 2 * d){
            ans = 2;
        }else if(n > 2 * d && n <= 3 * d){
            ans = 3;
        }else if(n > 3 * d && n <= 4 * d){
            ans = 4;
        }else{
            ans = 5;
        }
        std::cout << p[ans] << std::endl;
    }

    return 0;
}
