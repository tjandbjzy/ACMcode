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
const int MAXN = 300;
const int step = 294;
int s[MAXN];
char str[7][20] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

ll powmod(ll a, ll b, ll mod){
    ll res = 1LL;
    while(b){
        if(b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    s[1] = 1;
    for(int i = 2; i < MAXN; ++i){
        s[i] = (s[i - 1] + (int)powmod(i, i, 7)) % 7;
    }
    s[0] = s[step];
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        printf("%s\n", str[s[n % step]]);
    }
    
    return 0;
}
