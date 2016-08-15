#include <cstdio>

typedef long long ll;
const int MAXN = 1000 + 100;
int ha[MAXN];

int main(){
	int a, b;
	while(~scanf("%d %d", &a, &b)){
		int cnt = 0;
		while(a && b){
			if(a == 1 && b == 1){
				break;
			}
			if(a > b){
				a -= 2;
				b++;
			}else{
				b -= 2;
				a++;
			}
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
