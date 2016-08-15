#include <cstdio>

int main(int argc, char const *argv[]){
	int a, b, c;
	while(~scanf("%d %d %d", &a, &b, &c)){
		int ans = a * 3 + b * 2 + c * 6;
		if(ans >= 60){
			printf("I passed the exam.\n%d\n", ans);
		}else{
			printf("Exam was too hard.\n%d\n", ans);
		}
	}
	return 0;
}