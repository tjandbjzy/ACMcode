#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int MAXN = 1000000 + 10;
int s[10];

bool cmp(const int &a, const int &b){
	return a > b;
}

int main(){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d", s + i);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int a[4], k = 0, t = ans + s[i];
			while(t){
				a[k++] = t % 10;
				t /= 10;
			}
			std::sort(a, a + k, cmp);
			for(int j = 0; j < k; ++j){
				t = t * 10 + a[j];
			}
			ans = t;
			printf("%d\n", ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
