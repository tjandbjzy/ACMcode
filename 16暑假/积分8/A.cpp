#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

const int MAXN = 100000 + 10;
int a[MAXN], s[MAXN];
bool vis[MAXN];

int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n, m;
		scanf("%d %d", &n, &m);
		s[0] = 0;
		bool flag = false;
		for(int i = 1; i <= n; ++i){
			scanf("%d", a + i);
			s[i] = s[i - 1] + a[i];
		}
		memset(vis, false, sizeof(vis));
		vis[0] = true;
		for(int i =1; i <= n; ++i){
			if(vis[s[i] % m]){
				flag = true;
				break;
			}else{
				vis[s[i] % m] = true;
			}
		}
		if(!flag){
			puts("NO");
		}else{
			puts("YES");
		}
	}


	return 0;
}
