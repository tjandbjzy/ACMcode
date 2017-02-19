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
int s[6];

int main(){
    while(~scanf("%d%d%d%d%d%d", s, s + 1, s + 2, s + 3, s + 4, s + 5)){
        if(!s[0] && !s[1] && !s[2] && !s[3] && !s[4] && !s[5]){
            break;
        }
        std::sort(s, s + 6);
        double ans = 0.0;
        for(int i = 1; i < 5; ++i){
            ans += s[i];
        }
        ans /= 4.0;
        std::cout << ans << "\n";
    }
    
    return 0;
}
