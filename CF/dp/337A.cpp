#include <cstdio>
#include <algorithm>

const int MAXN = 100 + 10;
int a[MAXN];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d", a + i);
    }
    std::sort(a, a + m);
    int ans = 1 << 20;
    for(int i = 0; i + n <= m; ++i){
        ans = std::min(ans, a[i + n - 1] - a[i]);
    }
    printf("%d\n", ans);
    return 0;
}
