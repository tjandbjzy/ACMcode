#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAXN = 110;
int s[MAXN][MAXN];
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main(int argc, char const *argv[]){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &s[i][j]);
			}
		}
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(vis, false, sizeof(vis));

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; j++){
				dp1[i][j] = std::max(dp1[i - 1][j], dp1[i][j - 1]) + s[i][j];
				s[i][j] = 0;
			}
		}
		for(int i = n; i; --i){
			for(int j = n; j; --j){
				dp2[i][j] = std::max(dp2[i + 1][j], dp2[i][j + 1]) + s[i][j];
				s[i][j] = 0;
			}
		}
		printf("%d\n", dp1[n][n] + dp2[1][1]);
	}
	return 0;
}