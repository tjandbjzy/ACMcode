#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
int s[4];

int main(){
    double A, B, C, D;
	scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
    if(A == 0 && B == 0 && C == 0 && D == 0){
		puts("0");
	}else{
        s[0] = abs(A + B + C + D);
        s[1] = abs(A + B - C - D);
        s[2] = abs(A - B + C - D);
        s[3] = abs(A - B - C + D);
		std::sort(s, s + 4);
		printf("%.10f\n", abs(A * D - B * C) / s[3]);
    }
}

