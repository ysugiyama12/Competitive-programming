#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
const double pi = acos(-1);
typedef pair<int, int> P;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EPS 1e-4
#define OUTPUT(i) (cout << (ll)i << endl)

/*unsigned int xor128(void)
{
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
unsigned int xor128rnd(unsigned int m)
{
    return xor128() % m;
}*/

bool operator<(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

struct edge
{
    int to, cost;
};

ll a[1000010] = {};
int bitn[10000] = {};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    ll sumt = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        sumt += a[i];
    }

    if (K == 0)
    {
        cout << sumt << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i)
    {
        ll cnt = 0;
        ll t = a[i];

        while (t)
        {
            if ((1 & t) == 1)
                bitn[cnt]++;

            cnt++;
            t >>= 1;
            // cout << i << " " << cnt << endl;
        }
    }
    ll t = K;
    int cnt = 0; //2進数での桁数
    while (t)
    {
        cnt++;
        t >>= 1;
    }
    //bitの本数 番号

    vector<pair<int, int> > vp;
    for (int i = 0; i < cnt; ++i)
    {
        vp.push_back(P(bitn[i], i));
    }
    sort(vp.begin(), vp.end());

    t = 0;
    vector<int> v[100010];
    for (int i = 0; i < cnt; ++i)
    {
        v[vp[i].first].push_back(vp[i].second);
    }

    for (int i = 0; i < cnt; ++i)
        sort(v[i].rbegin(), v[i].rend());
    

    ll ans = 0;
    for (int i = 0; i < cnt; ++i)
    {
        for (int j = 0; j < (int)v[i].size(); ++j)
        {
            ll cntt = 0;
            t |= (1LL << v[i][j]);
            if (t > K)
                t &= ~(1LL << v[i][j]);

            for (int k = 0; k < N; ++k)
            {
                cntt += (a[k] ^ t);
            }

            ans = max(ans, cntt);
        }
    }

    cout << ans << endl;
    return 0;
}
