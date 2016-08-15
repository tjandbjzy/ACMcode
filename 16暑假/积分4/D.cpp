#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int MAXN = 30;
int a[MAXN];
bool vis[MAXN];

int main(){
    int n;
	scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    memset(vis, false, sizeof(vis));
	std::sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			for(int k = j + 1; k < n; ++k){
				if(a[i] + a[j] > a[k] && !vis[i] && !vis[j] && !vis[k]){
					++ans;
					vis[i] = vis[j] = vis[k] = true;
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}
