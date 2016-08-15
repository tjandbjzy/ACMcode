#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

const int MAXN = 1000000 + 100;
struct node{
	double c;
	int x, y;
};

node s[MAXN];
int len;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

bool cmp(const node &a, const node &b){
	return a.c < b.c;
}

void init(){
	len = 0;
	for(int i = 1; i <= 1000; ++i){
		for(int j = 0; j <= i; ++j){
			if(gcd(i, j) == 1){
				s[len].c = 1.0 * j / i;
				s[len].x = j;
				s[len++].y = i;
			}
		}
	}
	std::sort(s, s + len, cmp);
	return;
}

int main(){
	init();
	int cas;
	scanf("%d", &cas);
	while(cas--){
		double a;
		scanf("%lf", &a);
		int l = 0, r = len - 1, ans = len - 1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a <= s[mid].c){
				r = mid - 1;
				ans = mid;
			}else{
				l = mid + 1;
			}
		}
		node b = fabs(a - s[l].c) <= fabs(s[l - 1].c - a) ? s[l] : s[l - 1];
		printf("%d/%d\n", b.x, b.y);
	}

	return 0;
}
