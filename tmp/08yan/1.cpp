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
const int MAXN = 100 + 10;
char s[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%s %d", s, &n);
        for(int i = 0, l = strlen(s); i < l; ++i){
            int x = s[i] - 'a';
            x = (x + n) % 26;
            s[i] = x + 'a';
        }
        printf("%s\n", s);
    }
    
    return 0;
}
