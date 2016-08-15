#include <cstdio>
#include <iostream>
#include <cstring>

const int MAXN = 100 + 10;
int sg[MAXN];
bool vis[MAXN];

int main(){
	/*
	freopen("1173.out", "w", stdout);
	sg[0] = 0;
	for(int i = 1; i < MAXN; ++i){
		memset(vis, false, sizeof(vis));
		for(int j = 0; j < i; ++j){
			vis[sg[j]] = true;	
		}
		for(int j = 1; j <= i; ++j){
			for(int k = 1; k <= i; ++k){
				if(k + j  == i){
					vis[sg[j] ^ sg[k]] = true;	
				}	
			}
		}
		for(int j = 0; j < 300; ++j){
			if(!vis[j]){
				sg[i] = j;
				break;
			}
		}
	}

	for(int i = 0 ; i < MAXN; ++i){
		if(sg[i] != i){
			printf("sg[%d] = %d\n", i, sg[i]);	
		}
	}
	*/
	int n;
	while(~scanf("%d", &n)){
		int ans = 0, x;
		for(int i = 0; i < n; ++i){
			scanf("%d", &x);
			if(x % 4 == 0){
				ans ^= x - 1;	
			}else if(x % 4 == 3){
				ans ^= x + 1;	
			}else{
				ans ^= x;	
			}	
		}
		if(ans){
			puts("Alice");		
		}else{
			puts("Bob");	
		}
	}
	return 0;
}
