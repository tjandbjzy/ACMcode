#include <cstdio>
#include <algorithm>
#include <cstring>

const int INF = (1 << 30);
const int MAXN = 100000 + 10;
int p[MAXN], ti[MAXN], ans[MAXN];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d", p + i);
	}
	memset(ti, 0, sizeof(ti));
	ans[1] = 1;
	for(int i = 2; i <= k + 1; ++i){
		ans[i] = INF;
		for(int j = 0; j < n; ++j){
			while(p[j] * ans[ti[j]] <= ans[i - 1]){
				++ti[j];
			}
			ans[i] = std::min(ans[i], p[j] * ans[ti[j]]);
		}
	}
	printf("%d\n", ans[k + 1]);
	return 0;
}
