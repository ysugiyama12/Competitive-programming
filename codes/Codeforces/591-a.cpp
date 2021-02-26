/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    while(Q--){
        ll N;
        cin >> N;
        ll p[200010];
        rep(i,0,N) cin >> p[i];
        rep(i,0,N) p[i] /= 100;
        sort(p, p+N, greater<ll>());
        ll x,a,y,b,k;
        cin >> x >> a >> y >> b >> k;
        ll lv = 0, rv = N+1;
        while(rv - lv > 1){
            ll mid = (rv + lv) / 2;
            bool ok = true;
            ll ab = lcm(a, b);
            ll va = mid/a - (mid/ab);
            ll vb = mid/b - (mid/ab);
            ll vab = mid/ab;
            ll ans = 0;
            ll tt[200010] = {};
            rep(i,0,vab) tt[i] = x+y;
            if(x > y){
                rep(i,0,va) tt[i+vab] = x;
                rep(i,0,vb) tt[i+vab+va] = y;
            }else{
                rep(i,0,vb) tt[i+vab] = y;
                rep(i,0,va) tt[i+vab+vb] = x;
            }

            rep(i,0,mid){
                ans += tt[i] * p[i];
            }
            if(ans < k) ok = false;

            if(ok){
                rv = mid;
            }else{
                lv = mid;
            }
        }
        if(rv == N+1){
            print(-1);
        }else{
            print(rv);
        }

    }

    

}