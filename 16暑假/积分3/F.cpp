#include<iostream>
#include <cstdio>

const int MAXN = 1000 + 10;
int a[MAXN];

int main(){
	int n, x; 
	scanf("%d %d", &n, &x);
	int ans = 0;
 	for(int i = 1; i <= n; ++i){
    	scanf("%d", a + i); 
		ans += a[i];
    }
    for(int i = x - 1, r = x + 1; i >= 1 && r <= n; --i, ++r){
    	if(a[i] != a[r]){
			ans -= a[i] + a[r];
		}
	}
    printf("%d\n", ans);
	return 0;
}
