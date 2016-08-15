#include <cstdio>

int main(int argc, char const *argv[]){
        int n, k;
        scanf("%d %d", &n, &k);
        int num = 0, ans;
        for(int i = 0; i < n; ++i){
        	int x;
            scanf("%d", &x);
            if(x & 1){
            	num++;
           	}
        }
        if(n == k){
        	ans = num & 1;
		}else if(!(n & 1)){
        	if(!(k & 1)){
            	ans = 0;
        	}else {
            	if(n / 2 - k / 2 <= num){
                	ans = 1;
                }else{
                	ans = 0;
                }
            }
        }else{
        	if(!(k & 1)){
            	if(num >= (n / 2 - k / 2 + 1) && num <= (n / 2 + k / 2)){
                	ans = 1;
                }else{
                	ans = 0;
                }
            }else{
            	if(n / 2 + k / 2 + 1 <= num){
                	ans = 1;
                }else{
                	ans = 0;
                }
            }
        }
        puts(ans ? "Stannis" : "Daenerys");
        return 0;
}
