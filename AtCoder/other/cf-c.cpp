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
    ll N;
    ll T[100010], A[100010];
    cin >> N;
    bool flg = true;
    rep(i,0,N) cin >> T[i];
    rep(i,0,N) cin >> A[i];
    ll h[100010] = {};
    h[0] = T[0];
    rep(i,0,N-1){
        if(T[i] != T[i+1]){
            h[i+1] = T[i+1];
        }
    }
    if(h[N-1] != 0 && h[N-1] != A[N-1]) flg = false;

    h[N-1] = A[N-1];
    rrep(i,N-1,1){
        if(A[i] != A[i-1]){
            if(h[i-1] == 0){
                h[i-1] = A[i-1];
            }else if(h[i-1] != A[i-1]){
                flg = false;
            }
        }
    }
    rep(i,0,N){
        if(h[i] > T[i] || h[i] > A[i]) flg = false;
    }
    if(!flg){
        print(0);
        return 0;
    }
    ll ans = 1;
    rep(i,0,N){
        if(h[i] == 0){
            ans *= min(T[i], A[i]);
            ans %= MOD;
        }
    }
    print(ans);
}
