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
const int MAXN = 1000 + 100;
bool isPrime[MAXN];
int pri[MAXN];

int main(){
    for(int i = 0; i < MAXN; ++i){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < MAXN; ++i){
        if(isPrime[i]){
            for(int j = i + i; j < MAXN; j += i){
                isPrime[j] = false;
            }
        }
    }
    memset(pri, 0, sizeof(pri));
    for(int i = 1; i < MAXN; ++i){
        pri[i] = pri[i - 1] + (isPrime[i] ? 1 : 0);
    }
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", pri[r] - pri[l - 1]);
    }
    
    return 0;
}
