#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

typedef long long ll;
const int MAXN = 10000 + 10;
const int INF = 1 << 30;
const double PI = acos(-1.0);


int main(){
	double s;
	while(~scanf("%lf", &s)){
		double a = sqrt(s / PI);
		double ans = sqrt(2.0) * PI * a * a * a / 12.0;
		printf("%.6f\n", ans);
	}
	return 0;
}
