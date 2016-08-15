#include <cstdio>

char s[100][100];

int main(int argc, char const *argv[]){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		for(int i = 0; i < 4; i++){
			scanf("%s", s[i]);
		}
		int ax, ay, bx, by;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 8; j++){
				if(s[i][j] == '*'){
					ax = i;
					ay = j;
				}
				if(s[i][j] == '.'){
					bx = i;
					by = j;
				}
			}
		}
		int ans = ax + ay - bx - by;
		if(ans < 0){
			ans = -ans;
		}
		if(ans & 1){
			puts("Red win");
		}else{
			puts("Black win");
		}
	}
	return 0;
}