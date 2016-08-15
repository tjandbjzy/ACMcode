#include <cstdio>

int main(){
	int n;
	while(~scanf("%d", &n)){
		int cnt = 0;
		int top = 0;
		int x;
		while(n--){
			scanf("%d", &x);
			if(!cnt){
				top = x;
				cnt = 1;
			}else if(x == top){
				cnt++;
			}else{
				cnt--;
			}
		}	
		printf("%d\n", top);
	}
	return 0;
}
