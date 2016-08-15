#include <cstdio>
#include <cmath>

double cal(int x){
	double res = 1.0;
	for(int i = 1; i <= x; ++i){
		double t = 1.0;
		for(int j = 1; j <= i; ++j){
			t *= j;
		}
		res += 1.0 / (1.0 * t);
	}
	return res;
}

int main(){
	puts("n e");
	puts("- -----------");
	puts("0 1");
	puts("1 2");
	puts("2 2.5");
	for(int i = 3; i < 10; ++i){
		printf("%d %.9f\n", i, cal(i));
	}

	return 0;
}
