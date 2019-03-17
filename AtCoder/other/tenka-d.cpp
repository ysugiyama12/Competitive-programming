#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll A[100010], B[100010];
    rep(i,0,N) cin >> A[i] >> B[i];
    // vector<lpair> lp;
    // rep(i,0,N) lp.push_back(make_pair(A[i], B[i]));
    // sort(lp.begin(), lp.end());
    ll ans = 0;
    rrep(bit,31,0){
        if(!((K>>bit) & 1)) continue;
        ll k_tmp = K - (1LL<<bit);
        ll tt = 0;
        rep(i,0,N){
            bool ok = true;
            rrep(j,31,0){
                if(j > bit){
                    if(!((K>>j) & 1) && ((A[i]>>j) & 1)){
                        ok = false;
                    }
                }else if(j == bit){
                    if((A[i]>>j) & 1) ok = false;
                }
            }
            if(ok) tt += B[i];
        }
        ans = max(ans, tt);
    }
    ll tt = 0;
    rep(i,0,N){
        bool ok = true;
        rrep(j,31,0){
            if(!((K>>j) & 1) && ((A[i]>>j) & 1)){
                ok = false;

            }
        }
        if(ok) tt += B[i];
    }
    ans = max(ans, tt);
    print(ans);

}
