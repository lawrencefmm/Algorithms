#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll expo(ll a, ll b, ll mod)
{
    ll ans = 1;

    while(b)
    {
        if(b&1) ans = (ans*(a%mod))%mod;
        a = (a%mod)*(a%mod)%mod;
        b >>= 1;
    }
    return ans;
}
