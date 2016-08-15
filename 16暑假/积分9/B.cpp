#include <cstdio>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 10000 + 10;
int p;

int pow(int a, int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = res * a % p;
		}
		b >>= 1;
		a = a * a % p;
	}
	return res;
}

int main(){
	scanf("%d", &p);
	int a, b;
	while(scanf("%d", &a) && a){
		scanf("%d", &b);
		int ans = 0;
		for(int i = 0; i < p; ++i){
			if(pow(a, i) == b){
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
