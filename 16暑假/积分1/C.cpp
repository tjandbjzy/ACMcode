#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

typedef long long ll;
const int MAXN = 2000 + 10;
const int MOD = 1000000007;

ll dp1[MAXN][MAXN], dp2[MAXN][MAXN];

void Init(){
	 for(int i = 1; i < MAXN; ++i){
        dp1[i][0] = 1LL;
        dp2[0][i] = 1LL;
    }
    for(int i = 1; i < MAXN; ++i){
        for(int j = 1; j < MAXN; ++j){
            if(i != j){
				dp1[i][j] = dp1[i][j - 1];
			}
			dp1[i][j] += dp1[i - 1][j];
           	dp1[i][j] %= MOD;
			dp2[i][j] = dp2[i - 1][j];
            if(i < j){
				dp2[i][j] += dp2[i][j - 1];
			}
            dp2[i][j] %= MOD;
        }
    }
	return;
}

int main(){
	Init();
    int t = 0, cas;
    scanf("%d", &cas);
	while(cas--){
    	int a, b;
        scanf("%d-%d", &a, &b);
        printf("Case #%d: %lld %lld\n", ++t, dp1[a][b], std::max(dp2[a][b], 1LL));
    }
	return 0;
}
