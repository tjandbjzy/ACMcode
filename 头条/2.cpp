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
const int N = 600 + 10;
std::string s[N];
int f[N];

int main(){
    freopen("2.in", "r", stdin);
    int n, m;
    std::cin >> n >> m;
    getchar();
    for(int i = 0; i < n; ++i){
        getline(std::cin, s[i]);
    }
    while(m--){
        std::string t;
        std::string tmp;
        getline(std::cin, t);
        memset(f, 0, sizeof(f));
        int a, b, pos;
        for(int i = 0; i < t.size(); i++){
            a = i;
            while(t[i] != ' ' && i < t.size()){
                ++i;
            }
            b = i;
            tmp = t.substr(a, b - a + 1);
            for(int j = 0; j < n; ++j){
                pos = t.find(tmp);
                if(pos >= 0){
                    f[j]++;
                }
            }
        }
        for(int i = 0; i < 10; ++i){
            std::cout << f[i] << std::endl;
        }
        puts("");
        int mx = -1, p = 0;
        for(int i = 0; i < n; ++i){
            if(mx < f[i]){
                mx = f[i];
                p = i;
            }
        }
        std::cout << s[p] << std::endl;
    }
    
    return 0;
}
