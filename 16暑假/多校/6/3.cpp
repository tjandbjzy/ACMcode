#include <cstdio>
#include <iostream>
#include <cstring>

const int MAXN = 100 + 10;
int sg[MAXN];
bool vis[MAXN];

int main(){
	/*
	freopen("3.out", "w", stdout);
	sg[0] = 0;
	for(int i = 1; i < MAXN; ++i){
		memset(vis, false, sizeof(vis));
		for(int j = 0; j < i; ++j){
			vis[sg[j]] = true;	
		}
		for(int j = 1; j <= i; ++j){
			for(int k = 1; k <= i; ++k){
				for(int l = 1; l <= i; ++l){	
					if(k + j + l == i){
						vis[sg[j] ^ sg[k] ^ sg[l]] = true;
					}
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
	}*/
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		int ans = 0, x;
		for(int i = 0; i < n; ++i){
			scanf("%d", &x);
			if(x % 8 == 0){
				ans ^= x - 1;	
			}else if(x % 8 == 7){
				ans ^= x + 1;	
			}else{
				ans ^= x;	
			}	
		}
		if(!ans){
			puts("Second player wins.");
		}else{
			puts("First player wins.");	
		}
	}
	return 0;
}
