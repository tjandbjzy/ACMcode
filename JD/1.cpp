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
const int MAXN = 100000 + 10;
char s[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n)){
        scanf("%s", s);
        int v, c = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] >= '1' && s[i] <= '9'){
                v = s[i] - '0';
                for(int j = 1; j <= v && i + j < n; ++j){
                    if(s[i + j] == 'X'){
                        c++;
                        s[i + j] = '#';
                    }
                }
                for(int j = 1; j <= v && i - j >= 0; ++j){
                    if(s[i - j] == 'X'){
                        c++;
                        s[i - j] = '#';
                    }
                }
            }
        }
        printf("%d\n", c);
    }
    
    return 0;
}
