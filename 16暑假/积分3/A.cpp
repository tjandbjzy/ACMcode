#include <cstdio>
#include <iostream>
#include <cstring>

const int MAXN = 60;
char s[MAXN][MAXN];
int used[1000];

bool f(int x, int y){
        memset(used, 0, sizeof(used));
        used[s[x][y]]++;
        used[s[x + 1][y]]++;
        used[s[x][y + 1]]++;
        used[s[x + 1][y + 1]]++;
        return used['f'] == 1 && used['a'] == 1 && used['c'] == 1 && used['e'] == 1;
}

int main(int argc, char const *argv[]){
        int n, m;
       	scanf("%d %d", &n, &m); 
		for(int i = 0; i <= n + 1; i++){
                for(int j = 0; j <= m + 1; j++){
                        if(!i || !j || i == n + 1 || j == m + 1){
                                s[i][j] = '#';
                        }
                        else{
							std::cin >> s[i][j];
                        }
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(f(i, j)){
                                ans++;
                        }
                }
        }
        printf("%d\n", ans);
		return 0;
}
