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
const int MAXN = 200000 + 100;
const double PI = acos(-1.0);
const double ANSPI = PI * PI / 6.0;
char s[10000];
double ans[MAXN];

int main(){
    ans[0] = 0.0;
    ans[1] = 1.0;
    for(int i = 2; i <= 120000; ++i){
        ans[i] = ans[i - 1] + 1.0 / (1.0 * i) * 1.0 / (1.0 * i);
    }
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        if(len > 6){
            printf("%.5f\n", ANSPI);
            continue;
        }
        int n = 0;
        for(int i = 0; i < len; ++i){
            n = n * 10 + s[i] - '0';
        }
        if(n < 120000){
            printf("%.5f\n", ans[n]);
        }else{
            printf("%.5f\n", ANSPI);
        }
    }
   
    return 0;
}
