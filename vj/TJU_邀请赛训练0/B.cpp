#include <cstdio>

typedef long long ll;
const int MAXN = 1000 + 100;
int ha[MAXN];

int main(){
	int n;
	while(~scanf("%d", &n)){
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			ha[x]++;
			if(ha[x] > ans){
				ans = ha[x];
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
