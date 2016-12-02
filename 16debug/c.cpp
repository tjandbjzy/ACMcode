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
const int MAXN = 1000 + 100;
char s[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n) && n){
        scanf("%s", s);
        for(int i = 0; i < n; ++i){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - 'A' + 'a';
            }else{
                int k = s[i] - 'a';
                k = (k + 3) % 26;
                s[i] = k + 'a';
            }
        }
        printf("%s\n", s);
    }
    
    return 0;
}
