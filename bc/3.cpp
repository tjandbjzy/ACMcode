#include <cstdio>
#include <iostream>
typedef long long ll;
const int MAXN = 400000 + 10;
int ha[MAXN];

int main(){
	std::ios::sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while(cas--){
		ll n, m, k;
		std::cin >> n >> m >> k;
		memset(ha, 0, sizeof(ha));
		for(int i = 1; i <= n; ++i){
			ll x;
			std::cin >> x;
			if(m <= x){
				++ha[i];
			}
		}
		for(int i = 1; i <= n; ++i){
			ha[i] += ha[i - 1];
		}
		ll ans = 0;
		for(int i = 1, j = k; i <= n; ++i){
			while(j <= n){
				if(ha[j] - ha[i - 1] == k){
					ans += 1LL + n - j;
					break;
				}else{
					++j;
				}
			}
		}
		std::cout << ans << std::endl;
	}


	return 0;
}
