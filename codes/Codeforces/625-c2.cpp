/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll a[200010], ca[200010];
ll b[200010], cb[200010];

ll x[200010], y[200010], z[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,P;
    cin >> N >> M >> P;
    rep(i,0,N) cin >> a[i] >> ca[i];
    rep(i,0,M) cin >> b[i] >> cb[i];
    rep(i,0,P) cin >> x[i] >> y[i] >> z[i];
    ll ans = -INF;
    rep(i,0,N){
        rep(j,0,M){
            ll attack = a[i], defense = b[j];
            ll cost = - ca[i] - cb[j];

            rep(k,0,P){
                if(attack > x[k] && defense > y[k]) cost += z[k];
            }
            ans = max(ans, cost);
            print(i,j,cost);
        }
    }
    print(ans);

}