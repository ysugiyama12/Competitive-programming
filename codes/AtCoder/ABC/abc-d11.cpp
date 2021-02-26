/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
struct Combination{
private:
    ll N;
    vector<ll> fac, facinv;

public:
    Combination(ll n){
        N = n;
        fac.push_back(1); fac.push_back(1);
        rep(i,2,N+1) fac.push_back(fac[i-1] * i % MOD);
        rep(i,0,N+1) facinv.push_back(power(fac[i], MOD-2));
    }
    ll power(ll x, ll n){
        if(n == 0) return 1LL;
        ll res = power(x * x % MOD, n/2);
        if(n % 2 == 1) res = res * x % MOD;
        return res;
    }
    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
    }
    ll npk(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[n-k] % MOD;
    }
    ll get(ll x){return fac[x];};
    ll getinv(ll x){return facinv[x];};
};

double per[1010][1010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,D,X,Y;
    cin >> N >> D >> X >> Y;
    per[1][0] = 0.5;
    per[1][1] = 0.5;
    per[0][0] = 1.0;
    rep(i,2,N+1){
        rep(j,0,i+1){
            if(j == 0){
                per[i][j] = per[i-1][j] / 2.0;
            }else if(j == i){
                per[i][j] = per[i-1][j-1] / 2.0;
            }else{
                per[i][j] = (per[i-1][j-1] + per[i-1][j]) / 2.0;
            }
        }
    }

    X = abs(X);
    Y = abs(Y);
    if(X % D != 0 || Y % D != 0){
        print(0.0);
    }else{
        ll val = X / D + Y / D;
        if(val > N){
            print(0.0);
        }else if((N - val) % 2 == 1){
            print(0.0);
        }else{
            ll cnt = (N - val) / 2;
            double sum = 0;
            ll r = X / D, u = Y / D, l = 0, d = 0;
            rep(i,0,cnt+1){
                r += i; l += i; u += (cnt-i); d += (cnt-i);
                // double tt = fac[r] * fac[u] * fac[l] * fac[d];
                // print(tt);
                sum += per[N][r+l] * per[r+l][r] * per[N-r-l][u];
                // sum += per(N, r+l) * per(r+l, r) * per(N-r-l, u);
                r -= i; l -= i; u -= (cnt-i); d -= (cnt-i);
            }
            // print(sum);
            // sum *= fac[N] / pow(4.0,N);
            cout << setprecision(15) << sum << endl;

        }
    }

    
}