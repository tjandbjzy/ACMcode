#include <cstdio>

int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int x;
		scanf("%d", &x);
		int a[20], cur = 0, t = x;
		while(x){
			++cur;
			x /= 10;
		}
		for(int i = cur; i; --i){
			a[i] = t % 10;
			t /= 10;
		}
		if(cur & 1){
			int p = 0, q = 0;
			for(int i = 1; i <= cur / 2; ++i){
				p += a[i];
				p *= 10;
			}	
			for(int i = cur; i > cur / 2 + 1; --i){
				q += a[i];
				q *= 10;
			}
			printf("%d\n", p + q + a[cur / 2 + 1]);

		}else{
			int p = 0, q = 0;
			for(int i = 1; i <= cur / 2; ++i){
				p += a[i];
				p *= 10;
			}	
			for(int i = cur; i > cur / 2; --i){
				q += a[i];
				q *= 10;
			}
			printf("%d\n", (p + q) / 10);
		}
	}

	return 0;
}
