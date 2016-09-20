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

ll *primarr, *v;
ll q, p;

ll pi(ll n, ll primarr[], ll len){
    ll i = 0, mark = 0;
    for (i = len - 1; i > 0; i--) {
        if (primarr[i] < n) {
            mark = 1;
            break;
        }
    }
    if (mark){
        return i + 1;
    }
    return 0;
}
 
ll phi(ll x, ll a, ll m){
    if (a == m){
        return x / q * p + v[x % q];
    }
    if (x < primarr[a - 1]){
        return 1LL;
    }
    return phi(x, a - 1, m) - phi(x / primarr[a - 1], a - 1, m);
}
 
ll prime(ll n){
    char *mark;
    ll mark_len, count = 0, i, j, m = 7, sum = 0, s = 0;
    ll len, len2, len3;
 
    mark_len = (n < 10000) ? 10002 : ((ll)exp(2.0 / 3 * log(n)) + 1);
 
    mark = (char *)malloc(sizeof(char) * mark_len);
    memset(mark, 0, sizeof(char) * mark_len);
    for (i = 2; i < (ll)sqrt(mark_len); i++) {
        if (mark[i]){
            continue;
        }
        for (j = i + i; j < mark_len; j += i){
            mark[j] = 1;
        }
    }
    mark[0] = mark[1] = 1;
 
    for (i = 0; i < mark_len; i++)
        if (!mark[i]){
            count++;
        }
 
    primarr = (ll *)malloc(sizeof(ll) * count);
    j = 0;
    for (i = 0; i < mark_len; i++){
        if (!mark[i]){
            primarr[j++] = i;
        }
    }
 
    if (n < 10000){
        return pi(n, primarr, count);
    }
 
    len = pi((ll)exp(1.0 / 3 * log(n)), primarr, count);
    len2 = pi((ll)sqrt(n), primarr, count);
    len3 = pi(mark_len - 1, primarr, count);
 
    j = mark_len - 2;
    for (i = (ll)exp(1.0 / 3 * log(n)); i <= (ll)sqrt(n); i++) {
        if (!mark[i]) {
            while (i * j > n) {
                if (!mark[j]){
                    s++;
                }
                j--;
            }
            sum += s;
        }
    }
    free(mark);
    sum = (len2 - len) * len3 - sum;
    sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;
 
    if (m > len){
        m = len;
    }
    for (i = 0; i < m; i++) {
        q *= primarr[i];
        p *= primarr[i] - 1;
    }
    v = (ll *)malloc(sizeof(ll) * q);
    for (i = 0; i < q; i++){
        v[i] = i;
    }
    for (i = 0; i < m; i++){
        for (j = q - 1; j >= 0; j--){
            v[j] -= v[j / primarr[i]];
        }
    }
 
    sum = phi(n, len, m) - sum + len - 1;
    free(primarr);
    free(v);
    return sum;
}
 
int main(){
    ll n;
	while(~scanf("%lld", &n)){
        
		p = 1;
		q = 1;
		printf("%lld\n", prime(n));
	}
    return 0;
}
