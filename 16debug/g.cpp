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
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        puts((a & b) > (a ^ b) ? "1" : "0");
    }
    
    return 0;
}
