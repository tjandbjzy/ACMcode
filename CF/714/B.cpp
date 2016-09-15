#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 100;
std::map<int, int> m;

int main(){
    int n;
    while(~scanf("%d", &n)){
        m.clear();
        int x;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            ++m[x];
        }
        int cnt = 0;
        for(std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
            ++cnt;
        }
        if(cnt > 3){
            puts("NO");
        }else if(cnt == 3){
            cnt = 0;
            int a[3];
            for(std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
                a[cnt++] = it -> first;
            }
            std::sort(a, a + 3);
            if(a[2] + a[0] == a[1] + a[1]){
                puts("YES");
            }else{
                puts("NO");
            }
        }else{
            puts("YES");
        }
    }
    
    return 0;
}
