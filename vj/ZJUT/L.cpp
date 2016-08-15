#include <cstdio>

int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		double ans = -100, x;
		for(int i = 0; i < n; ++i){
			scanf("%lf", &x);
			ans = ans > x ? ans : x;
		}
		printf("%.2f\n", ans);
	}

	return 0;
}
