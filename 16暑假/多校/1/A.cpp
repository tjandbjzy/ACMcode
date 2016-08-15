#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long ll;
const int MAXN = 100000 + 10;
int head[MAXN];
struct node{
	int from, to, c, next;
};

std::vector<node> G[MAXN];
node s[MAXN * 10];
int e, n;
int fa[MAXN];
ll sum[MAXN], dp[MAXN];

bool cmp(const node &x, const node &y){
	return x.c < y.c;
}

inline void add(int x, int y, int z){
	s[e].from = x;
	s[e].to = y;
	s[e].next = 0;
	s[e++].c = z;
}

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void dfs(int rt, int pre){
	sum[rt] = 1;
	for(int i = 0; i < G[rt].size(); ++i){
		int aa = G[rt][i].to;
		int cc = G[rt][i].c;
		if(aa == pre){
			continue;
		}
		dfs(aa, rt);
		sum[rt] += sum[aa];
		dp[rt] += dp[aa] + (sum[aa] * (n - sum[aa])) * 1.0 * cc;
	}
	return;
}

int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int m;
		scanf("%d %d", &n, &m);
		e = 0;
		for(int i = 0 ; i < m; ++i){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			add(x, y, z);
		}
		for(int i = 1; i <= n; ++i){
			fa[i] = i;
		}
		std::sort(s, s + m, cmp);
		ll ans = 0;
		int cnt = 0;
		for(int i = 0; ; ++i){
			int x = find(s[i].from);
			int y = find(s[i].to);
			if(x != y){
				fa[y] = x;
				ans += s[i].c;
				s[i].next = 1;
				++cnt;
			}
			if(cnt == n - 1){
				break;
			}
		}
		//printf("%lld\n", ans);
		for(int i = 0; i <= n; ++i){
			G[i].clear();
		}
		for(int i = 0; ; ++i){
			if(s[i].next){
				node e1, e2;
				e1.to = s[i].from;
				e2.to = s[i].to;
				e1.c = e2.c = s[i].c;
				G[s[i].from].push_back(e2);
				G[s[i].to].push_back(e1);
			}
		}
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		dfs(0, -1);
		ll tmp = (n - 1) * n / 2;
		printf("%.2f\n", 1.0 * dp[0] / tmp);

	}


	return 0;
}
