#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long ll;
const int MAXN = 100000 + 10;
ll s[MAXN];
int p[MAXN] = {0,2,3,5,7,9,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};

int main(){
	int t = 1 << 16;
	for(int i = 0; i < 10; ++i){
		printf("%d\n", p[i]);
	}
	int k = 0;
	for(int i = 1; i < t; ++i){
		s[i] = 1LL;
		for(int j = 0; j < 15; ++j){
			if(i & (1 << j)){
				s[i] *= p[j];
				if(k < 10)
				printf("%lld\n", s[i]), k++;
			}
		}
		s[i] = s[i] * s[i];
	}
	std::sort(s, s + t);
	for(int i = 1; i < 10; ++i){
		printf("%lld\n", s[i]);
	}
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n - 1; ++i){
			scanf("%lld", s + i);
			++s[i];
		}
		std::sort(s, s + n - 1);
		ll ans = 1LL;
		int i = n - 2, j = 0;
		while(i >= 0){
            if(j >= k - 1){
                ans += s[i];
            }else{
				++ans;
       		}
			++j;
			--i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
