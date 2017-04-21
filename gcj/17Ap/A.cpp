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
    //freopen("A.in", "r", stdin);
    freopen("A-small-practice.in", "r", stdin);
    freopen("ASM.out", "w", stdout);
    int cas, k = 0;
    std::cin >> cas;
    while(cas--){
        int n;
        std::cin >> n;
        getchar();
        std::string s, ans;
        int cnt = 0;
        bool vis[260];
        for(int j = 0; j < n; ++j){
            getline(std::cin, s);
            memset(vis, false, sizeof(vis));
            int tmp = 0;
            for(int i = 0; i < s.size(); ++i){
                if(s[i] != ' '){
                    vis[s[i] - 'A'] = true;
                }
            }
            for(int i = 0; i < 26; ++i){
                if(vis[i]){
                    tmp++;
                }
            }
            if(j == 0){
                ans = s;
                cnt = tmp;
            }else{
                if(tmp > cnt){
                    cnt = tmp;
                    ans = s;
                }
            }
        }
        std::cout << "Case #" << ++k << ": " << ans << std::endl; 
    }
    
    return 0;
}
