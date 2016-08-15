#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 100;
int w[MAXN], c[MAXN], dp[MAXN];

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", w + i, c + i);
	}
	for(int i = 0; i < n; ++i){
		for(int v = m; v >= w[i]; --v){
			dp[v] = std::max(dp[v], dp[v - w[i]] + c[i]);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}
