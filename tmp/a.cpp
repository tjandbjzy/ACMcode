#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 1000000 + 10;

struct edge{
	int u, v;
};

ll ha[MAXN], co[MAXN];
edge s[MAXN];

int main(){
	//freopen("E.in", "r", stdin);
	co[0] = 1;
	for(int i = 1; i < MAXN; ++i){
		co[i] = co[i - 1] * 3;
	}
	int n, m;
	while(~scanf("%d %d", &n, &m)){
		memset(ha, 0, sizeof(ha));
		for(int i = 0; i < m; ++i){
			scanf("%d %d", &s[i].u, &s[i].v);
			ha[s[i].u] += co[s[i].v];
			ha[s[i].v] += co[s[i].u];
		}
		ll ans = 0;
		for(int i = 0; i < m; ++i){
			int x = s[i].u, y = s[i].v;
			if(ha[x] + co[x] == ha[y] + co[y]){
				++ans;
			}
		}
		std::sort(ha + 1, ha + n + 1);
		for(int i = 1; i < n; ++i){
			if(ha[i] == ha[i + 1]){
				int l = i;
				while(l + 1 <= n && ha[l] == ha[l + 1]){
					++l;
				}
				ll c = l - i + 1;
				ans += 1LL * c * (c - 1) / 2;
				i = l;
			}
		}
		std::cout << ans << std::endl;
	}

	return 0;
}
