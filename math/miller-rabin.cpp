// Literature : cp-algorithms.com

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rd(random_device{}());

ll mul(ll a, ll b, ll c)
{
	return __int128(a)*b%c;
}

ll expo(ll a, ll p, ll m)
{
	ll t = 1;

	while(p)
	{
		if(p & 1) t = mul(t, a , m);
		a = mul(a, a, m);
		p >>= 1;
	}
	return t;
}

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool check_composite(ll n, ll a, ll d, ll s)
{
	ll x = expo(a, d, n);
	if(x == 1 or x == n - 1) return false;
	for(int r = 1; r < s; r++)
	{
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
	return true;
}

bool MillerRabin(ll n)
{
	if(n < 4) return n == 3 || n == 2;

	ll s = 0, d = n - 1;

	while(!(d & 1))
	{
		d >>= 1;
		s++;
	}

	for(ll p : primes)
	{
		int a = 2 + rd() % (n - 3);
		if(check_composite(n, a, d, s)) return false;
	}
	return true;
}
