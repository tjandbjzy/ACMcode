#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long ll;
const int MAXN = 100000 + 10;
ll s[MAXN];

int main(){
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
