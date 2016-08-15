#include <cstdio>
#include <cstdlib>

struct point{
	int x, y;
};

const int MAXN = 500 + 10;
point s[MAXN];

bool ok(point a, point b, point c, point d){
	if(abs((a.y - b.y) * (c.x - d.x)) == abs((c.y - d.y) * (a.x - b.x))){
		return true;
	}else if(abs((a.y - c.y) * (b.x - d.x)) == abs((b.y - d.y) * (a.x - c.x))){
		return true;
	}else if(abs((a.y - d.y) * (c.x - b.x)) == abs((c.y - b.y) * (a.x - d.x))){
		return true;
	}
	return false;
}

int main(int argc, char const *argv[]){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; i++){
			scanf("%d %d", &s[i].x, &s[i].y);
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				for(int k = j + 1; k < n; k++){
					for(int l = k + 1; l < n; l++){
						if(ok(s[i], s[j], s[k], s[l])){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}