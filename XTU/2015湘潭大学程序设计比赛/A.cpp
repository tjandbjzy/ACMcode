#include <cstdio>


int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n, l;
		scanf("%d %d", &n, &l);
		int ex = 0, px = 0;
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			if(l >= x){
				ex += 10 / (l - x + 1);
				if(ex >= (px + 1) * 100){
					++l;
					px++;
				}	
			}
		}
		printf("%d %d\n", l, ex);
	}

	return 0;
}
