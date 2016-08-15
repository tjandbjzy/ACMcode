#include <cstdio>
#include <iostream>

typedef long long ll;
const int MAXN = 100000 + 100;
ll a[MAXN], b[MAXN], c[MAXN];

int main(){
	std::ios::sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while(cas--){
		int n;
		std::cin >> n;
		for(int i = 0; i < n; ++i){
			std::cin >> a[i];
		}
		b[0] = 0;
		for(int i = 1; i < n; ++i){
			b[i] = std::max(b[i - 1], std::abs(a[i] - a[i - 1]));
		}
		c[n - 1] = 0;
		for(int i = n - 2; i >= 0; --i){
			c[i] = std::max(c[i + 1], std::abs(a[i] - a[i + 1]));
		}
		ll sum = b[n - 2] + c[1];
		for(int i = 1; i < n - 1; ++i){
			sum += std::max(std::max(b[i - 1], c[i + 1]), std::abs(a[i + 1] - a[i - 1]));
		}
		std::cout << sum << std::endl;
	}

	return 0;
}

