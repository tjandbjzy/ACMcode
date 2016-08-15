#include <cstdio>
#include <cmath>

int main(){
	const double PI = acos(-1.0);
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		double ans = log10(sqrt(2.0 * PI * n)) + n * log10(n / exp(1.0)); 
		printf("%d\n", (int)ans + 1);
	}

	return 0;
}
