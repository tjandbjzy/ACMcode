#include <cstdio>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 10000 + 10;
char s[MAXN];

int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d %s", &n, s);
		int cnt = 0, ans = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == '('){
				++cnt;
			}else{
				--cnt;
			}
			if(cnt < 0){
				++ans;
				cnt = 1;
			}
		}
		printf("%d\n", ans + (cnt >> 1));
	}
	return 0;
}
