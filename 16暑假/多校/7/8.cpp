#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

typedef long long ll;
const int MAXN = 2000000 + 100;

int s[100],w[50];
ll dp[MAXN],h[MAXN],ans[MAXN];

ll gcd(ll a,ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int C(int a, int b){
    int res = 1;
    for(int i = 1; i <= a; ++i){
        res = res * (b - i + 1) / i;
    }
    return res;
}

int main(){
    int cas;
    scanf("%d", &cas);
	while(cas--){
        int p, n, m;
		scanf("%d %d %d", &p, &n, &m);
		int sum = 0;
        for(int i = 0;i < m; ++i){
            scanf("%d", w + i);
			sum += w[i];
        }
        if(sum < p){
            puts("0/1");
			continue;
        }
        int temp = (1 << m);
		memset(s, 0, sizeof(s));
        for(int i = n; i < m + n; ++i){
            s[i] = 1;
        }
        memset(h, 0, sizeof(h));
        memset(dp, 0, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        int tmp = 0;
		int num;
        while(tmp < temp){
            num = 0;
			sum = 0;
            for(int i = 0; i < m; ++i){
                if(tmp & (1 << i)){
                    sum += w[i];
                    ++num;
                }
            }
            ++h[num];
            if(sum >= p){
               dp[num]++;
            }
            tmp++;
        }
        tmp = 0;
		temp = C(n, n + m);
		int a, b;
        while(tmp < temp){
                int j = 1, i = 0;
				a = 0;
				b = 0;
				num = 0;
                if(!s[0]){
                    a++;
                    while(true){
                        if(j > i + 2 * a || j > n + m - 1){
							break;
						}
						if(!s[j]){
                            ++a;
                        }else{
							++b;
						}
						++j;
						++num;
                        if(num == 2){
                            --a;
							num = 0;
							i += 2;
                        }
                    }
                }else{
					++b;
				}
                ans[b] += dp[b];
				std::next_permutation(s, s + m + n);
        		++tmp;
        }
        ll t1 = 0, t2 = 1, tt, yy;
        for(int i = 1; i <= m; ++i){
            if(!ans[i]){
                continue;
            }else{
                tt = gcd(t2, h[i]);
                yy = t2 * h[i] / tt;
                t1 = t1 * yy / t2 + ans[i] * yy / h[i];
                t2 = yy;
            }
        }
        t2 *= (ll)temp;
        tt = gcd(t1, (ll)t2);
        printf("%lld/%lld\n", t1 / tt, t2 / tt);
    }
}
