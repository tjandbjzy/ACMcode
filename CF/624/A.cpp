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
    double l, d, v1, v2;
    scanf("%lf %lf %lf %lf", &d, &l, &v1, &v2);
    printf("%.20f\n", (l - d) / (v1 + v2));
    return 0;
}
