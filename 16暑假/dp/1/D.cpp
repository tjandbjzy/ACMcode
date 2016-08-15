#include <cstdio>

typedef long long ll;

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        if(n == 1 || n == 2){
            puts("1");
            continue;
        }
        ll a = 1, b = 1, ans;
        for(int i = 3; i <= n; ++i){
            ans = a + b;
            b = a;
            a = ans;
        } 
        printf("%lld\n", ans);
    }
    return 0;
}
