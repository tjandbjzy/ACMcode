#include <cstdio>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(!c){
		puts(a == b ? "YES" : "NO");
	}else{
		int d = (b - a) / c;
		if(d < 0){
			puts("NO");
		}else{
			d = (b - a) % c;
			if(!d){
				puts("YES");
			}else{
				puts("NO");
			}
		}
	}
	return 0;
}
