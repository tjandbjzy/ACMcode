#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 1000000 + 10;
int s[10], ans, n;

void dfs(int depth, int sum){
	if(depth == n + 1){
		ans = max(ans, sum);
		return;
	}
	int t = sum + s[depth];
	int a[10], l = 0;
	while(t){
		a[l++] = t % 10;
		t /= 10;
	}
	sort(a, a + l);
	do{
		int tmp = 0;
		for(int i = 0; i < l; ++i){ 
			tmp = tmp * 10 + a[i];
		}
		dfs(depth + 1, tmp);
	}while(next_permutation(a, a + l));
}

int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; ++i){
			scanf("%d", s + i);
		}
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
