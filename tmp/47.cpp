#include <cstdio>

typedef int ll;

ll f(ll a){
	ll res = 1;
	for(int i = 1; i <= a; ++i){
		res *= i;
	}
	return res;
}

int main(){
	int n;
	while(~scanf("%d", &n)){
		ll ans = 0;
		for(int i = 1; i <= n; ++i){
			ans += f(i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
