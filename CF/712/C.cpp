#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;

int main(){
    int a, b;
    int s[3];
    scanf("%d %d", &a, &b);
    s[0] = s[1] = s[2] = b;
    int ans = 0, i = 0;
    while(!(s[0] >= a && s[1] >= a && s[2] >= a)){
        s[i % 3] = s[(i + 1) % 3] + s[(i + 2) % 3] - 1;
        ++ans;
        ++i;
    }
    printf("%d\n", ans);
    
    return 0;
}
