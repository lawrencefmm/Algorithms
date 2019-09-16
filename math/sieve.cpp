#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

bool is_composite[MAXN];

void sieve()
{
    is_composite[0] = is_composite[1] = true;

    for(long long i = 2; i < MAXN; i++)
        if(is_composite[i] == false)
            for(long long j = i+i; j*j < MAXN; j+=i)
                is_composite[j] = true;
}
