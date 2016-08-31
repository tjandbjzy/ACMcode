#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 100;
char s[MAXN];
bool h[1000];

int main(){
    gets(s);
    if(s[1] == '}'){
        puts("0");
    }else{
        int len = strlen(s);
        for(int i = 1; i < len; i += 3){
            h[s[i]] = true;
        }
        int ans = 0;
        for(int i = 0; i < 1000; ++i){
            if(h[i]){
                ++ans;
            }
        } 
        printf("%d\n", ans);
    }
    return 0;
}
