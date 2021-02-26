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
ll dub[25][100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,L,Q;
    ll X[100010], A[100010], B[100010];
    cin >> N;
    rep(i,0,N) cin >> X[i];
    cin >> L >> Q;
    rep(i,0,Q){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        if(A[i] > B[i]) swap(A[i], B[i]);
    }
    ll next_pos[100010] = {};
    rep(i,0,N){
        ll pos = upper_bound(X, X+N, X[i] + L) - X;
        next_pos[i] = pos-1;
    }
    // printa(next_pos, N);
    rep(i,0,N){
        dub[0][i] = next_pos[i];
    }
    rep(k,0,20){
        rep(i,0,N){
            if(dub[k][i] == -1){
                dub[k+1][i] = -1;
            }else{
                dub[k+1][i] = dub[k][dub[k][i]];
            }
        }
    }
    rep(i,0,Q){
        ll lv = 0, rv = N+1;
        while(rv - lv > 1){  
            ll mid = (rv + lv) / 2;
            ll p = A[i];
            rrep(k,19,0){
                if((mid >> k) & 1){
                    p = dub[k][p];
                }
            }
            if(p >= B[i]){
                rv = mid;
            }else{
                lv = mid;
            }
        }
        print(rv);

    }


}
