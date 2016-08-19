#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>

typedef long long ll;
const int MAXN = 100000 + 10;
std::map<std::string, int> m;
std::string s, t;
int fa[MAXN];

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}


int main(){
    freopen("1066.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    m.clear();
    int n;
    std::cin >> n;
    for(int i = 0; i <= n; ++i){
        fa[i] = i;
    }
    int cnt = 1, op, x, y;
    while(n--){
        std::cin >> op >> s >> t;
        if(!m[s]){
            m[s] = cnt++;
        }
        if(!m[t]){
            m[t] = cnt++;
        }
        if(op){
            x = find(m[s]);
            y = find(m[t]);
            if(x == y){
                std::cout << "yes\n";
            }else{
                std::cout << "no\n";
            }
        }else{
            x = find(m[s]);
            y = find(m[t]);
            if(x != y){
                fa[x] = y;
            }
        }
        //for(int i = 0; i < cnt; ++i){
            //std::cout << i << " " << find(i) << "\n";
        //}
        //std::cout << "\n";
    }
    //for(std::map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it){
        //std::cout << it -> first << " " << it -> second << "\n";
    //}
    return 0;
}
