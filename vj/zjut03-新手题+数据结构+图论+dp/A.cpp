#include <cstdio>

int main(){
	int n;	
	while(~scanf("%d", &n) && n){
		int ans = 5 * n;
		int cur = 0;
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			if(x > cur){
				ans += 6 *(x - cur);
			}else if(x < cur){
				ans += 4 * (cur - x);
			}
			cur = x;
		}
		printf("%d\n", ans);
	}
	return 0;
}
