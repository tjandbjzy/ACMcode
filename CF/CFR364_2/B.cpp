#include <cstdio>
#include <iostream>
#include <cstring>

typedef long long ll;
const int MAXN = 100000 + 10;
bool r[MAXN], c[MAXN];

int main(){
	memset(r, false, sizeof(r));
	memset(c, false, sizeof(c));
	int n, m;
	std::cin >> n >> m;
	ll ans = 0;
	int ta = 0, tb = 0;
	for(int i = 0 ; i < m; ++i){
		int a, b;
		std::cin >> a >> b;	
		if(!r[a]){
			++ta;
			r[a] = true;
		}
		if(!c[b]){
			++tb;
			c[b] = true;
		}
		ans = (n - ta - 0LL) * (n - tb - 0LL);
		std::cout << ans << std::endl;
	}
	return 0;
}
