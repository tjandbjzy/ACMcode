#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long ll;
const int MAXN = 10000 + 10;
const int INF = 1 << 30;


int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int a, b, d, n;
		scanf("%d %d %d %d", &a, &b, &d, &n);
		if(n == 1){
			int x = a * b, ans = 0;;
			while(x){
				if(x % 10 == d){
					ans++;
				}
				x /= 10;
			}
			printf("%d\n", ans);
			continue;
		}
		if(a * b < 10){
			if(a * b == d){
				printf("%d\n", n);
			}else{
				printf("0\n");
			}
		}else if(a * b == 10){
			if(d == 0){
				puts("1");
			}else if(d == 1){
				printf("%d\n", n);
			}else{
				puts("0");
			}
		}else{
			int x, y, z, w;
			x = a * b / 10;
			z = a * b % 10;
			y = x + z;
			int ans = 0;
			if(y < 10){
				if(d == x){
					++ans;
				}	
				if(d == y){
					ans += n - 1;
				}
				if(d == z){
					++ans;
				}
			}else{
				w = x + 1;
				x = y / 10 + y % 10;
				y = y % 10;
				if(d == w){
					++ans;
				}
				if(d == x){
					ans += n - 2;
				}
				if(d == y){
					++ans;
				}
				if(d == z){
					++ans;
				}
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}
