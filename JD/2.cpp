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
int c[MAXN][MAXN];
double p[MAXN];

int main(){
    for(int i = 0; i < MAXN; ++i){
        c[0][i] = c[i][i] = 1;
    }
    for(int i = 1; i < MAXN; ++i){
        for(int j = i + 1; j < MAXN; ++j){
            c[i][j] = c[i - 1][j - 1] + c[i][j - 1];
        }
    }
    int n;
    while(~scanf("%d", &n)){
        double t = 1.0;
        for(int i = 0; i < n; ++i){
           scanf("%lf", p + i);
           p[i] /= 100.0;
           t *= p[i];
        }
        int tar = n * 3 / 5;
        if(n * 3 % 5){
            tar++;
        }
        double sum = 0.0;
        for(int i = tar; i <= n; ++i){
            sum += c[i][n] * 1.0;
        }
        printf("%.5f\n", sum * t);
    }

    return 0;
}
