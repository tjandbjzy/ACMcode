#include <cstdio>

int main(int argc, char const *argv[]){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		int s, r;
		scanf("%d", &n);
		int sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d %d", &s, &r);
			sum += s * r;
		}
		printf("%d %d %d\n", 36 * 36 / sum, 2 * 36 * 36/ sum, 3 * 36 * 36 / sum);
		
	}
	return 0;
}