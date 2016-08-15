#include <cstdio>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > q; 


int main(){
//	freopen("stone.in", "r", stdin);
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		while(!q.empty()){
			q.pop();
		}
		while(n--){
			int x;
			scanf("%d", &x);
			q.push(x);
		}
		int ans = 0;
		while(q.size() > 1){
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			ans += x + y;
//			printf("%d %d\n", x + y, ans);
			q.push(x + y);
		}
		printf("%d\n", ans);
	}
	return 0;
}
