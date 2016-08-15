#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

typedef long long ll;
const int MAXN = 100000 + 10;
int a[MAXN];

int main(){
	int n, k;
	std::cin >> n >> k;
	int l = 1, r = n, cur = 1, cnt = 0;
	bool f = true;
	while(l <= r){
		if(f){
			a[cur++] = l++;
		}else{
			a[cur++] = r--;
		}
		if(k != cnt + 1){
			f = !f;
			++cnt;
		}
	}
	for(int i = 1; i <= n; ++i){
		printf(i == n ? "%d\n" : "%d ", a[i]);
	}
	return 0;
}
