
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


const double PI = acos(-1.0);
const int MAXN = 100 + 10;
struct node{
	double x, y;
};

struct tnode{
	int from, to;
	double c;
};
tnode p[MAXN * MAXN];
node s[MAXN];
int fa[MAXN * MAXN];
double d;

inline double dis(node a, node b){
	//printf("%f %f %f %f %f\n", d, a.x, a.y, b.x, b.y);
	double c = fabs(d * acos(cos(a.x) * cos(b.x) * cos(b.y - a.y) + sin(a.x) * sin(b.x)));
	//printf("%f\n", c);
	return c;
    //return d * acos(cos(a.x) * cos(b.x) * cos(b.y - a.y) + sin(a.x) * sin(b.x));
}

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool cmp(const tnode &a, const tnode &b){
	return a.c < b.c;
}

int main(int argc, char const *argv[]){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		double l;

		//！！！！
		scanf("%lf", &d);// ！！！更改读入时一定注意格式控制符！！！
		//!!!

		d /= 2;
		scanf("%lf", &l);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%lf %lf", &s[i].x, &s[i].y);
			s[i].x *= PI / 180.0;
			s[i].y *= PI / 180.0;
		}
		//puts("hehe");
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; j++){
				p[cnt].from = i;
				p[cnt].to = j;
				//printf("%f %f\n", s[i].x, s[i].y);
				p[cnt++].c = dis(s[i], s[j]);
				//printf("%f\n", p[cnt - 1].c);
			}
		}
		//printf("%f %f\n", p[0].c);
		for(int i = 0; i <= cnt; i++){
			fa[i] = i;
		}
		sort(p, p + cnt, cmp);
		//puts("hehe");
		int cur = 0;
		double ans = 0;
		for(int i = 0;; ++i){
			int ta = find(p[i].from), tb = find(p[i].to);
			if(ta != tb){
				fa[ta] = fa[tb];
				ans += p[i].c;
				cur++;
			}
			if(cur == n - 1){
                break;
			}
		}
		if(l >= ans){
			puts("IS POSSIBLE");
		}else{
			puts("IS NOT POSSIBLE");
		}
	}


	return 0;
}
