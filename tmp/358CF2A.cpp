#include <cstdio>
#include <algorithm>
#include <iostream> 

typedef long long ll;

int main(){
	ll a, b;
	while(std::cin >> a >> b){
		if(a > b){
			std::swap(a, b);
		}
		ll ta = a / 5, la = a % 5;
		ll tb = b / 5, lb = b % 5;
		ll ans = a * tb + ta * lb;
		for(int i = 0; i <= la; ++i){
			for(int j = 0; j <= lb; ++j){
				if((i + j) % 5 == 0){
					ans++;
				}
			}
		}
		std::cout << ans - 1 << std::endl;
	}


	return 0;
}
