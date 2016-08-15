#include <cstdio>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 1000000 + 10;

ll cal(int s){
	ll a, t1, t2;
	int ride, lim, t;
	t = s & 1;
	if(t == 1) {
		ride = 1 + (s >> 1);
		a = ride;
	} else {
		ride = s >> 1;
		a = 1;
	}
	ll res = 0;
	for(lim = s / 3; t <= lim; ride++, t += 2) {
		res += a * a;
		t1 = (ride + 1) * (ride - t);
		t2 = (t + 1) * (t + 2);
		a = a * t1 / t2;
	}
	return res;
}
int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		ll result;
		int s, k;
		scanf("%d %d", &k, &s);
		result = cal(s / 2);
		printf("%d %lld\n", k, result);
	}
	return 0;
}

