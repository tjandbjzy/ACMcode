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
const double eps = 1e-6;

bool equ(double z){
    return fabs(z) < eps;
}

int main(){
    int n, m, x, y, t;
    while(~scanf("%d %d %d %d %d", &n, &m, &x, &y, &t)){
        double ss = 0.0;
        double cc;
        double p;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                scanf("%lf", &p);
                if(i == x && j == y){
                    cc = 1 - p;
                }
                ss += (1 - p) / (1.0 * n * m);
            }
        }
        //printf("%f %f\n", ss, cc);
        ss = 1 - pow(ss, t);
        cc = 1 - pow(cc, t);
        if(equ(ss - cc)){
            puts("equal");
            printf("%.2f\n", ss);
        }else if(ss > cc){
            puts("ss");
            printf("%.2f\n", ss);
        }else{
            puts("cc");
            printf("%.2f\n", cc);
        }

    }
    
    return 0;
}
