/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

struct BIT { //1-indexed
private:
    int n,n2;
    vector<ll> bit;

public:
    BIT(ll N){
        n = N;
        bit.resize(n+1);
        rep(i,0,n) bit[i+1] = 0;
        n2 = 1;
        while(n2 * 2 <= n) n2 *= 2;
    }

    ll sum(ll i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(ll i, ll x){
        if(i == 0) return;
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
    ll lower_bound(ll w) {
        if (w <= 0) return 0;
        ll x = 0;
        for (ll k = n2; k > 0; k /= 2) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[200010], y[200010];
    rep(i,0,N) cin >> x[i] >> y[i];
    vector<ll> X, Y;
    rep(i,0,N){
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }
    X.push_back(-INF);
    X.push_back(INF);
    Y.push_back(-INF);
    Y.push_back(INF);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    rep(i,0,N){
        x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
        y[i] = lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
    }
    vector<lpair> lp;
    rep(i,0,N) lp.push_back(make_pair(x[i], y[i]));
    sort(lp.begin(), lp.end());
    rep(i,0,N){
        x[i] = lp[i].first;
        y[i] = lp[i].second;
    }

    BIT Lb(200010), Rb(200010);
    rep(i,0,N) Rb.add(y[i], 1);
    ll pow_mod[200010] = {};
    pow_mod[0] = 1;
    rep(i,0,N+1) pow_mod[i+1] = pow_mod[i] * 2 % MOD;
    ll ans = 0;
    rep(i,0,N){
        Rb.add(y[i], -1);
        rep(bit,0,16){
            ll RT = Rb.sum(N) - Rb.sum(y[i]);
            ll RD = Rb.sum(y[i]);
            ll LT = Lb.sum(N) - Lb.sum(y[i]);
            ll LD = Lb.sum(y[i]);
            ll b0 = ((bit>>0) & 1);
            ll b1 = ((bit>>1) & 1);
            ll b2 = ((bit>>2) & 1);
            ll b3 = ((bit>>3) & 1);
            RT = b0 ? pow_mod[RT] - 1 : 1;
            RD = b1 ? pow_mod[RD] - 1 : 1;
            LT = b2 ? pow_mod[LT] - 1 : 1;
            LD = b3 ? pow_mod[LD] - 1 : 1;
            
            ll v = RT * RD % MOD * LT % MOD * LD % MOD;
            if((b0 && b3) || (b1 && b2)) (v *= 2) %= MOD;
            (ans += v) %= MOD;
        }
        Lb.add(y[i], 1);
    }
    print(ans);
}