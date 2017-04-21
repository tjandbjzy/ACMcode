#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>

typedef long long ll;
const int MAXN = 100 + 10;
const int N = 100000000;
int p[MAXN];
int t[MAXN];

int main(){
    srand(time(NULL));
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++i){
            scanf("%d", p + i);
        }
        int tar = n * 3 / 5;
        if(n * 3 % 5){
            tar++;
        }
        int ans = 0, cnt;
        for(int i = 0; i < N; ++i){
            cnt = 0;
            for(int j = 0; j < n; ++j){
                t[j] = rand() % 101;
                if(t[j] <= p[j]){
                    cnt++;
                }
            }
            if(cnt >= tar){
                ans++;
            }
        }
        printf("%.5f\n", 1.0 * ans / (1.0 * N));

    }
    return 0;
}
