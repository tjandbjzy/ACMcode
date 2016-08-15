#include <cstdio>

int main(int argc, char const *argv[]){
	int n;
    scanf("%d", &n);
    int ans1 = n / 7 * 2;
    int ans2 = n / 7 * 2;
    n %= 7;
    if (n == 6){
		ans1++;
    }
    if (n >= 1){
    	ans2++;
    }
    if (n >= 2){
    	ans2++;
	}
    printf("%d %d\n", ans1, ans2);
	
	return 0;
}