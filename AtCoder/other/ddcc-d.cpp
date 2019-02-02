#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

ll extGcd(ll a, ll b,ll &p, ll &q){
    if(b == 0){
        p = 1; q = 0; return a;
    }
    ll d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

lpair ChineseRem(vector<ll> &b, vector<ll> &m){
    ll r = 0, M = 1;
    ll N = b.size();
    rep(i,0,N){
        ll p,q;
        ll d = extGcd(M, m[i], p, q);
        if((b[i] - r) % d != 0) return make_pair(0,-1);
        ll tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M*tmp;
        M *= m[i]/d;
        if(r > 1e12) return make_pair(0,-1);
    }
    return make_pair((r+M) % M, M);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a[40];
    rep(i,2,31){
        cin >> a[i];
    }
    vector<ll> b,m;
    rep(i,2,31){
        b.push_back(a[i] % (i-1));
        m.push_back(i-1);
    }
    lpair ans = ChineseRem(b,m);
    if(ans.second == -1 || ans.first < 1 || ans.first > 1e12){
        print("invalid");
        return 0;
    }
    rep(i,2,31){
        ll sum = 0;
        ll v = ans.first;
        while(v > 0){
            sum += v % i;
            v /= i;
        }
        if(sum != a[i]){
            print("invalid");
            return 0;
        }
    }
    print(ans.first);

}
