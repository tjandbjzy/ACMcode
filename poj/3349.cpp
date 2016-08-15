#include <cstdio>
#include <cstring>
#include <algorithm>

const int MOD = 30031;
const int MAXN = 20000 + 100;

struct node{
    int d[6];
};

int ha[MAXN];
node a[MAXN][100];

bool cmp(node x, node y){
	std::sort(x.d, x.d + 6);
	std::sort(y.d, y.d + 6);
    for(int i = 0; i < 6; ++i){
        if(x.d[i] != y.d[i])
            return false;
    }
    return true;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(ha, 0, sizeof(ha));
        bool flag = false;
		for(int i = 0; i < n; ++i){
            int sum = 0;
            node p;
            for(int j = 0; j < 6; ++j){
                scanf("%d", &p.d[j]);
                sum=(sum + p.d[j]) % MOD;
            }
            if(!flag){
                for(int j = 0; j < ha[sum]; ++j){
                    if(cmp(p, a[sum][j])){
                        flag = true;
						break;
                    }
                }
                a[sum][ha[sum]] = p;
                ++ha[sum];
            }
        }
        if(flag){
            puts("Twin snowflakes found.");
		}else{
            puts("No two snowflakes are alike.");
    	}
	}
    return 0;
}
