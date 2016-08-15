#include <cstdio>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 10000 + 10;
ll a[MAXN], b[MAXN], c[MAXN];

int main(){
	a[1] = 1;
	b[1] = 1;
	c[1] = 2;
	for(int i = 2; i < MAXN; ++i){
		a[i] = a[i - 1] + i;
		b[i] = b[i - 1] + 2 * i - 1;
		c[i] = c[i - 1] + 2 * i;
	}
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n, k;
		scanf("%d %d", &k, &n);
		printf("%d %lld %lld %lld\n", k, a[n], b[n], c[n]);
	}


	return 0;
}
