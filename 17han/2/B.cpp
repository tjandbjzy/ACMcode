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
const int MAXN = 1000000 + 10;
char a[MAXN], b[MAXN];

int main(){
    int cas = 0;
    while(~scanf("%s", a)){
        if(a[0] == '0' && strlen(a) == 1){
            break;
        }
        printf("%d. ", ++cas);
        int j = 0, k = 0;
        int l = strlen(a);
        b[l] = '\0';
        for(int i = l - 1; i >= 0; --i){
            if(k <= a[i] - '0' - j){
                b[i] = a[i] - j - k;
                j = 0;
            }else{
                b[i] = a[i] + 10 - j - k;
                j = 1;
            }
            k = b[i] - '0';
        }
        puts(b[0] == '0' ? "IMPOSSIBLE" : b);
    }
    
    return 0;
}
