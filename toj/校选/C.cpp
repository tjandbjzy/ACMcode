#include <cstdio>

typedef long long ll;
ll _pow[20];

void Init()
{
    _pow[0] = 1;
    for(int i = 1; i < 20; i++)
    {
    	_pow[i] = 10 * _pow[i - 1];
    }
    return;
}

ll solve(ll n)
{
	if(n < 0)
        return 0;
	ll res = 1;
	for(int i = 1; _pow[i] <= n; i++)
	{
		ll t = n / _pow[i];
    	ll a = n % _pow[i - 1];
      	ll x = (n / _pow[i - 1]) % 10;
	    if(x == 0)
			res += (t - 1) * _pow[i - 1] + a + 1;
      	else
			res += t * _pow[i - 1];
	}

	return res;
}

int main(int argc, char const *argv[])
{
	ll n;
	Init();
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%lld", &n);
		ll ans = solve(n);
		printf("%lld\n", ans - 1);
	}
	return 0;
}
