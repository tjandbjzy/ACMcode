#include <cstdio>

int f(int p, int q){
	if(p == q){
		return 1;
	}else if(p < q){
		return 2 * f(p, q - p);
	}else{
		return 2 * f(p - q, q) + 1;
	}

}

int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int k, p, q;
		scanf("%d %d/%d", &k, &p, &q);
		printf("%d %d\n", k, f(p, q));

	}
	return 0;
}
