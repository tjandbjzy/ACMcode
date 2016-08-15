#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int MAXN = 200 + 10;
int s[MAXN];

int main(){
	int sum = 0;
	for(int i = 0; i < 5; ++i){
		int a;
		scanf("%d", &a);
		s[a]++;
		sum += a;
	}
	int ans = sum;
	for(int i = 0;i <= 100; ++i){
		if(s[i] >= 2)
			ans = std::min(ans, sum - i * std::min(s[i], 3));
	}
	printf("%d\n", ans);
	return 0;
}
