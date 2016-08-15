#include <cstdio>
#include <cmath>


int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		double ans = 0;
		for(int i = 1; i <= n; ++i){
			ans += log10(1.0 * i);
		}
		printf("%d\n", (int)ans + 1);
	}
		

	return 0;
}
