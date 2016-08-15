#include <cstdio>
#include <cstring>

const int MAXN = 100 + 10;
char s[MAXN][MAXN];
int sum[MAXN];

int main(int argc, char const *argv[]) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
                scanf("%s", s[i]);
        }
        memset(sum, 0, sizeof(sum));
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
                int a = 0, d = 0;
                for(int j = m - 1; j >= 0; j--){
                        d += sum[j];
                        if(s[i][j] == 'W'){
                                a = 1;
                        }
                        else{
                                a = -1;
                        }
                        if(d != a){
                                ans++;
                                sum[j] += a - d;
                                d = a;
                        }
                }
        }
        printf("%d\n", ans);
        return 0;
}
