#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int MAXN = 1000000 + 10;
int a[MAXN];


void Init(){
	memset(a, 0, sizeof(a));
    for(int i = 2; i < MAXN; ++i){
       if(!a[i]){
           ++a[i];
           for(int j = 2; i * j <= MAXN; ++j){
               ++a[i * j];
           }
       }
    }
	return;
}

int main(){
	Init();
	int cas, t = 0;
	scanf("%d", &cas);
	while(cas--){
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		int ans = 0;
		for(int i = x; i <= y; ++i){
			if(a[i] == k){
				++ans;
			}
		}
		printf("Case #%d: %d\n", ++t, ans);
	}

	return 0;
}
