#include <cstdio>
#include <iostream>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while(cas--){
		int n, m, x;
		ll sum = 0;
		std::cin >> n >> m;
		for(int i = 0; i < n; ++i){
			std::cin >> x;
			sum += x;
		}
		for(int i = 0; i < m; ++i){
			int s;
			std::cin >> s;
			if(s > sum){
				putchar('1');
			}else{
				putchar('0');
			}
		}
		puts("");
	}

	return 0;
}
