#include <cstdio>

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        printf("%d\n", 2 * n * n - n + 1);
    }
    return 0;
}
