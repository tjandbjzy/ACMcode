#include <cstdio>

typedef long long ll;

int main(){
	int n;
	while(~scanf("%d", &n)){
		ll ans = 1LL;
		n--;
		while(n--){
			ans += 1;
			ans <<= 1;
		}
		printf("%lld\n", ans);

	}


	return 0;
}
